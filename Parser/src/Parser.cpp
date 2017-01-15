/*
 * Parser.cpp
 *
 *  Created on: 11.12.2016
 *      Author: Denis
 */

#include "../includes/Parser.h"
#include <iostream>
#include <stdlib.h>

Parser::Parser(char* filename) {
	Symboltable* symtab = new Symboltable;
	this->scanner = new Scanner(filename, symtab);
	this->tree = new ParseTree();
	this->currentToken = NULL;
}

Parser::~Parser() {
	delete this->scanner;
	delete this->tree;
}

void Parser::nextToken() {
	this->currentToken = this->scanner->nextToken();
}

bool Parser::checkToken(Token::TType type) {
	if (this->currentToken->getType() != type) {
		//std::cerr << "Error: unerwartetes Token " << myTok.toString() << ", " << TokenTypeStr[type] << " erwartet" << std::endl;
		//exit(EXIT_FAILURE);
		cerr << "error " << currentToken->getType() << endl;
		return false;
	}

	nextToken();
	return true;
}

ParseTree* Parser::parse() {
	nextToken();
	this->tree->addProg(prog());
	return this->tree;
}

/**
 * PROG ::= DECLS STATEMENTS
 */
NodeProg* Parser::prog() {
	NodeProg* prog = new NodeProg();
	prog->addNode(decls());
	prog->addNode(statements());
	return prog;
}

/**
 * DECLS ::= DECL;DECLS | e
 */
NodeDecls* Parser::decls() {
	if (currentToken->getType() == Token::Int) {
		nextToken();
		NodeDecls* declarations = new NodeDecls();
		declarations->addNode(decl());
		nextToken();
		if (checkToken(Token::Semicolon)) {
			declarations->addNode(decls());
		}
		return declarations;
	} else {
		return new NodeEpsilon();
	}

}

/**
 * DECL ::= int ARRAY identifier
 */
NodeDecl* Parser::decl() {
	NodeDecl* decl = new NodeDecl();
	decl->addNode(array());
	if (currentToken->getType() == Token::Identifier) {
		NodeIdentifier* identifier = new NodeIdentifier();
		identifier->addInformation(currentToken->getSymtabEntry()->getInfo());
		decl->addNode(identifier);
	} else {
		cerr << "unexpected Token Line: " << currentToken->getLine() << " Column: " << currentToken->getColumn() << " " << currentToken->getType() << endl;
		exit(EXIT_FAILURE);
	}
	return decl;
}

/**
 * ARRAY ::= [integer] | e
 */
NodeArray* Parser::array() {
	if (currentToken->getType() == Token::LeftBracket) {
		nextToken();
		NodeArray* array = new NodeArray();
		if (currentToken->getType() == Token::Integer) {
			array->addInteger(new NodeInteger(currentToken->getValue()));
			nextToken();
		} else { //????
			cerr << "unexpected Token Line: " << currentToken->getLine() << " Column: " << currentToken->getColumn() << " " << currentToken->getType() << endl;
			exit(EXIT_FAILURE);
		}
		if (!checkToken(Token::RightBracket)) {
			cerr << "unexpected Token Line: " << currentToken->getLine() << " Column: " << currentToken->getColumn() << " " << currentToken->getType() << endl;
			exit(EXIT_FAILURE);
		}
		return array;
	} else {
		return new NodeEpsilon();
	}
}

/**
 * STATEMENTS ::= STATEMENT;STATEMENTS | e
 */
NodeStatements* Parser::statements() {
	switch (currentToken->getType()) {
		case Token::Identifier:
		case Token::Write:
		case Token::Read:
		case Token::LeftCurved:
		case Token::If:
		case Token::While: {
			NodeStatements* statements_ = new NodeStatements();
			statements_->addNode(statement());
			if (currentToken->getType() == Token::Semicolon) {
				statements_->addNode(statements());
			}
			return statements_;
		}

		default:
			return new NodeEpsilon();
	}
}

NodeStatement* Parser::statement() {
	switch (currentToken->getType()) {
		case Token::Identifier: {
			NodeStatementAssign* statement = new NodeStatementAssign();
			NodeIdentifier* identifier = new NodeIdentifier();
			identifier->addInformation(currentToken->getSymtabEntry()->getInfo());
			statement->addNode(identifier);
			nextToken();
			statement->addNode(index());
			nextToken();
			if (checkToken(Token::Assign)) {
				statement->addNode(exp());
			} else {
				//error ???
			}
			return statement;
		}
		case Token::Write: {
			NodeStatementWrite* statement = new NodeStatementWrite();
			nextToken();
			if (checkToken(Token::LeftParent)) {
				statement->addNode(exp());
			}
			checkToken(Token::RightParent);
			return statement;
		}
		case Token::Read: {
			NodeStatementRead* statement = new NodeStatementRead();
			nextToken();
			if (checkToken(Token::LeftParent)) {
				NodeIdentifier* identifier = new NodeIdentifier();
				identifier->addInformation(currentToken->getSymtabEntry()->getInfo());
				statement->addNode(identifier);
				nextToken();
				statement->addNode(index());
			}
			checkToken(Token::RightParent);
			return statement;
		}
		case Token::LeftCurved: {
			NodeStatementBlock* statement = new NodeStatementBlock();
			if (checkToken(Token::LeftCurved)) {
				statement->addNode(statements());
				checkToken(Token::RightCurved);
			}
			return statement;
		}
		case Token::If: {
			NodeStatementIf* statement_ = new NodeStatementIf();
			if (checkToken(Token::If)) {
				checkToken(Token::LeftParent);
				statement_->addNode(exp());
				checkToken(Token::RightParent);
				statement_->addNodeIf(statement());
				checkToken(Token::Else);
				statement_->addNodeElse(statement());
			}
			return statement_;
		}
		case Token::While: {
			NodeStatementWhile* statement_ = new NodeStatementWhile();
			if (checkToken(Token::If)) {
				checkToken(Token::LeftParent);
				statement_->addNode(exp());
				checkToken(Token::RightParent);
				statement_->addNode(statement());
			}
			return statement_;
		}
		default:
			//error
			break;
	}

	//return statement;
}

NodeIndex* Parser::index() {
	if (currentToken->getType() == Token::LeftBracket) {
		nextToken();
		NodeIndex* index = new NodeIndex();
		index->addNode(exp());
		if (currentToken->getType() != Token::RightBracket) {
			//error
		}
		return index;
	} else {
		return new NodeEpsilon();
	}

}

NodeExp* Parser::exp() {
	NodeExp* exp = new NodeExp();
	exp->addNode(exp2());
	exp->addNode(opExp());
	return exp;
}

NodeExp2* Parser::exp2() {
	switch (currentToken->getType()) {
		case Token::LeftParent: {
			nextToken();
			NodeExp2Bracket* exp2 = new NodeExp2Bracket();
			exp2->addNode(exp());
			if (!checkToken(Token::RightParent)) {
				//error
			}
			return exp2;
		}
		case Token::Identifier: {
			NodeExp2Identifier* exp2 = new NodeExp2Identifier();
			NodeIdentifier* identifier = new NodeIdentifier();
			identifier->addInformation(currentToken->getSymtabEntry()->getInfo());
			exp2->addNode(identifier);
			nextToken();
			exp2->addNode(index());
			return exp2;
		}
		case Token::Integer: {
			NodeInteger* integer = new NodeInteger(currentToken->getValue());
			NodeExp2Integer* exp2 = new NodeExp2Integer();
			exp2->addNode(integer);
			nextToken();
			return exp2;
		}
		case Token::Minus: {
			NodeExp2Minus* exp2_ = new NodeExp2Minus();
			nextToken();
			exp2_->addNode(exp2());
			return exp2_;
		}
		case Token::Exclamation: {
			NodeExp2Exclamation* exp2_ = new NodeExp2Exclamation();
			nextToken();
			exp2_->addNode(exp2());
			return exp2_;
		}
		default:
			//return error
			break;
	}
	//return new NodeExp2();
}

NodeOpExp* Parser::opExp() {
	switch (currentToken->getType()) {
		case Token::Plus:
		case Token::Minus:
		case Token::Star:
		case Token::Colon:
		case Token::LessThan:
		case Token::GreaterThan:
		case Token::Equal:
		case Token::ColonBetweenEqual:
		case Token::And: {
			NodeOpExp* opExp = new NodeOpExp();
			opExp->addNode(op());
			opExp->addNode(exp());
			return opExp;
		}

		default:
			return new NodeEpsilon();
	}
}

NodeOp* Parser::op() {
	NodeOp* op = new NodeOp(currentToken);
	nextToken();
	return op;
}

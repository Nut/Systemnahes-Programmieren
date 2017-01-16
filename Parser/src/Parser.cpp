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
	if (currentToken == NULL) {
		exit(EXIT_FAILURE);
	}
}


//checkToken, false => error, true => nextToken
void Parser::checkTokenError(Token::TType type) {
	if (this->currentToken->getType() != type) {
		error();
	}
	nextToken();
}

//checkToken for Epsilon return, only nextToken() if true
bool Parser::checkToken(Token::TType type) {
	if (this->currentToken->getType() == type) {
		nextToken();
		return true;
	} else {
		return false;
	}
}

void Parser::error() {
	cerr << "unexpected Token Line: " << currentToken->getLine() << " Column: " << currentToken->getColumn() << " " << currentToken->typeToString() << endl;
	exit(EXIT_FAILURE);
}

ParseTree* Parser::parse() {
	cout << "parse()" << endl;
	nextToken(); //get first token
	this->tree->addProg(prog());
	return this->tree;
}

/**
 * PROG ::= DECLS STATEMENTS
 */
NodeProg* Parser::prog() {
	cout << "prog()" << endl;
	NodeProg* prog = new NodeProg();
	cout << "Before decls()" << endl;
	prog->addNode(decls());
	cout << "Before statements()" << endl;
	prog->addNode(statements());
	return prog;
}

/**
 * DECLS ::= DECL;DECLS | e
 */
NodeDecls* Parser::decls() {
	cout << "decls()" << endl;
	if (checkToken(Token::Int)) {
		NodeDecls* declarations = new NodeDecls();
		declarations->addNode(decl());
		cout << "After decl()" << endl;
		checkTokenError(Token::Semicolon);
		cout << "After checkToken Semicolon" << endl;
		declarations->addNode(decls());
		cout << "After decls()" << endl;
		return declarations;
	} else {
		cout << "No decls" << endl;
		return new NodeEpsilon();
	}

}

/**
 * DECL ::= int ARRAY identifier
 */
NodeDecl* Parser::decl() {
	cout << "decl()" << endl;
	NodeDecl* decl = new NodeDecl();
	decl->addNode(array());
	cout << "After array()" << endl;
	checkTokenError(Token::Identifier);
	cout << "After tokenCheck" << endl;
	NodeIdentifier* identifier = new NodeIdentifier();
	cout << "After Node creating" << endl;
	//identifier->addInformation(currentToken->getSymtabEntry()->getInfo());
	cout << "Before addNode" << endl;
	decl->addNode(identifier);
	cout << "Before return decl" << endl;
	return decl;
}

/**
 * ARRAY ::= [integer] | e
 */
NodeArray* Parser::array() {
	cout << "array()" << endl;
	if (checkToken(Token::LeftBracket)) {
		cout << "Inside array()" << endl;
		NodeArray* array = new NodeArray();
		checkTokenError(Token::Integer);
		array->addInteger(new NodeInteger(currentToken->getValue()));
		checkTokenError(Token::RightBracket);
		return array;
	} else {
		cout << "Else array()" << endl;
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
			checkTokenError(Token::Semicolon);
			statements_->addNode(statements());
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
			checkTokenError(Token::Assign);
			statement->addNode(exp());
			return statement;
		}
		case Token::Write: {
			NodeStatementWrite* statement = new NodeStatementWrite();
			nextToken();
			checkTokenError(Token::LeftParent);
			statement->addNode(exp());
			checkTokenError(Token::RightParent);
			return statement;
		}
		case Token::Read: {
			NodeStatementRead* statement = new NodeStatementRead();
			nextToken();
			checkTokenError(Token::LeftParent);
			NodeIdentifier* identifier = new NodeIdentifier();
			identifier->addInformation(currentToken->getSymtabEntry()->getInfo());
			statement->addNode(identifier);
			nextToken();
			statement->addNode(index());
			checkTokenError(Token::RightParent);
			return statement;
		}
		case Token::LeftCurved: {
			NodeStatementBlock* statement = new NodeStatementBlock();
			checkTokenError(Token::LeftCurved);
			statement->addNode(statements());
			checkTokenError(Token::RightCurved);
			return statement;
		}
		case Token::If: {
			NodeStatementIf* statement_ = new NodeStatementIf();
			checkTokenError(Token::LeftParent);
			statement_->addNode(exp());
			checkTokenError(Token::RightParent);
			statement_->addNodeIf(statement());
			checkTokenError(Token::Else);
			statement_->addNodeElse(statement());
			return statement_;
		}
		case Token::While: {
			NodeStatementWhile* statement_ = new NodeStatementWhile();
			checkTokenError(Token::LeftParent);
			statement_->addNode(exp());
			checkTokenError(Token::RightParent);
			statement_->addNode(statement());
			return statement_;
		}
		default:
			error();
			return new NodeStatement();
	}
}

NodeIndex* Parser::index() {
	if (checkToken(Token::LeftBracket)) {
		NodeIndex* index = new NodeIndex();
		index->addNode(exp());
		checkTokenError(Token::RightBracket);
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
			checkTokenError(Token::RightParent);
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
			error();
			return new NodeExp2();
	}
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

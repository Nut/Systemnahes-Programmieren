/*
 * Parser.cpp
 *
 *  Created on: 11.12.2016
 *      Author: Denis
 */

#include "../includes/Parser.h"
#include <iostream>

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
		return false;
	}

	// Wir akzeptieren das Token auch im Fehlerfall, um weitere Fehler finden zu können
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
	if (checkToken(Token::Int)) {
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
		throw "stop";
	}
	return decl;
}

/**
 * ARRAY ::= [integer] | e
 */
NodeArray* Parser::array() {
	if (checkToken(Token::LeftBracket)) {
		NodeArray* array = new NodeArray();
		if (currentToken->getType() == Token::Integer) {
			array->addInteger(currentToken->getValue());
			nextToken();
		} else { //????
			cerr << "unexpected Token Line: " << currentToken->getLine() << " Column: " << currentToken->getColumn() << " " << currentToken->getType() << endl;
			throw "stop";
		}
		if (!checkToken(Token::RightBracket)) {
			cerr << "unexpected Token Line: " << currentToken->getLine() << " Column: " << currentToken->getColumn() << " " << currentToken->getType() << endl;
			throw "stop";
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
			break;
		}
		case Token::Write:
			break;
		case Token::Read:
			break;
		case Token::LeftCurved:
			break;
		case Token::If:
			break;
		case Token::While:
			break;
		default:
			//error
			break;
	}

	//return statement;
}

NodeIndex* Parser::index() {
	if (checkToken(Token::LeftBracket)) {
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
	return new NodeExp();
}

NodeExp2* Parser::exp2() {

}

NodeOpExp* Parser::opExp() {

}

NodeOp* Parser::op() {

}

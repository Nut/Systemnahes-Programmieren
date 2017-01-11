/*
 * Parser.cpp
 *
 *  Created on: 11.12.2016
 *      Author: Denis
 */

#include "../includes/Parser.h"
#include <iostream>

Parser::Parser(char* filename) {
	Symboltable* symtab = new Symboltable; //
	this->scanner = new Scanner(filename, symtab);
	this->tree = new ParseTree();
}

Parser::~Parser() {
	delete this->scanner;
}

ParseTree* Parser::parse() {
	this->tree->addProg(prog());
	return this->tree;
}

NodeProg* Parser::prog() {
	NodeProg* prog = new NodeProg();
	prog->addNode(decls());
	prog->addNode(statements());
	return prog;
}

NodeDecls* Parser::decls() {
	currentToken = this->scanner->nextToken();
	NodeDecls* declarations = new NodeDecls();
	if (currentToken->getType() == Token::Int) {
		declarations->addNode(decl());
		currentToken = this->scanner->nextToken();
		if (currentToken->getType() == Token::Semicolon) {
			declarations->addNode(decls());
		}
	}
	return declarations;
}

NodeDecl* Parser::decl() {
	currentToken = this->scanner->nextToken();
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

NodeArray* Parser::array() {
	Token* token = this->scanner->nextToken();
	NodeArray* array = new NodeArray();
	if (token->getType() == Token::LeftBracket) {
		token = this->scanner->nextToken();
		if (token->getType() == Token::Integer) {
			array->addInteger(token->getValue());
		} else {
			cerr << "unexpected Token Line: " << currentToken->getLine() << " Column: " << currentToken->getColumn() << " " << currentToken->getType() << endl;
			throw "stop";
		}
		Token* token = this->scanner->nextToken();
		if (token->getType() != Token::RightBracket) {
			cerr << "unexpected Token Line: " << currentToken->getLine() << " Column: " << currentToken->getColumn() << " " << currentToken->getType() << endl;
			throw "stop";
		}
	}
	return array;
}

NodeStatements* Parser::statements() {
	NodeStatements* statements = new NodeStatements();
	return statements;
}



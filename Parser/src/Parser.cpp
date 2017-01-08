/*
 * Parser.cpp
 *
 *  Created on: 11.12.2016
 *      Author: Denis
 */

#include "../includes/Parser.h"

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
	Token* token = this->scanner->nextToken();
	NodeDecls* declarations = new NodeDecls();
	if (token->getType() == Token::Int) {
		declarations->addNode(decl());
		Token* token = this->scanner->nextToken();
		if (token->getType() == Token::Semicolon) {
			declarations->addNode(decls());
		}
	}
	return declarations;
}

NodeDecl* Parser::decl() {
	Token* token = this->scanner->nextToken();
	NodeDecl* decl = new NodeDecl();
	decl->addNode(array());
	if (token->getType() == Token::Identifier) {
		decl->addNode(new Node()); //add identifier (as leaf?)
		//next Token?
	} else {
		//return error
	}
	return decl;
}

NodeArray* Parser::array() {
	Token* token = this->scanner->nextToken();
	NodeArray* array = new NodeArray();
	if (token->getType() == Token::LeftBracket) {
		token = this->scanner->nextToken();
		if (token->getType() == Token::Integer) {
			array->addNode(new Node()); //add integer (as leaf?)
		} else {
			//return Error
		}
		Token* token = this->scanner->nextToken();
		if (token->getType() != Token::RightBracket) {
			//return Error
		}
	}
	return array;
}

NodeStatements* Parser::statements() {
	NodeStatements* statements = new NodeStatements();
	return statements;
}



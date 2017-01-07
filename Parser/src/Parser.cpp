/*
 * Parser.cpp
 *
 *  Created on: 11.12.2016
 *      Author: Denis
 */

Parser::Parser(const char* filename) {
	this->scanner = new Scanner(filename);
	this->tree = new ParseTree();
}

Parser::~Parser() {
	delete this->scanner;
}

ParseTree* Parser::parse() {
	this->tree->addProg(prog());
	return this->tree;
}

Node* Parser::prog() {
	Node* prog = new Node();
	prog->addNode(decls());
	prog->addNode(statements());
	return prog;
}

Node* Parser::decls() {
	Token* token = this->scanner.nextToken();
	Node* declarations = new Node();
	if (token->getType() == Token::Int) {
		declarations->addNode(decl());
		Token* token = this->scanner.nextToken();
		if (token->getType() == Token::Semicolon) {
			declarations->addNode(decls());
		}
	}
	return decls;
}

Node* Parser::decl() {
	Token* token = this->scanner.nextToken();
	Node* decl = new Node();
	decl->addNode(array());
	if (token->getType() == Token::Identifier) {
		decl->addNode(new Node());
	} else {
		//return error
	}
	return decl;
}

Node* Parser::array() {
	Token* token = this->scanner.nextToken();
	Node* array = new Node();
	if (token->getType() == Token::LeftBracket) {
		token = this->scanner.nextToken();
		if (token->getType() == Token::Integer) {
			array->addNode(new Node());
		} else {
			//return Error
		}
		Token* token = this->scanner.nextToken();
		if (token != Token::RightBracket) {
			//return Error
		}
	}
	return array;
}

Node* Parser::statements() {
	Node* statements = new Node();
	return statements;
}



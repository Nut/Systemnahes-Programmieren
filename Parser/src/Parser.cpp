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
	prog();
	return this->tree;
}

void Parser::prog() {
	Node* decls = decls();
	Node* statements = statements();
	Node* prog = new Node();
	//prog->addNode(decls);
	//prog->addNode(statements);
	this->tree->addProg(prog);
}

Node* Parser::decls() {
	Token* token = this->scanner.nextToken();
	Node* decls = new Node;
	while(token != Token::Semicolon) {
		token = this->scanner.nextToken();
		switch (token) {
			case Token::Int:
				decls->addNode(decl());
				break;
			default:
				break;
		}
	}
	return decls;
}

Node* Parser::decl() {
	Token* token;
	Node* decl = new Node;
	while(token != Token::Semicolon) {
		token = this->scanner.nextToken();
		switch (token) {
			case Token::Int:
				decl->addNode(decl());
				break;
			default:
				break;
		}
	}
	return decls;
}

void Parser::array() {
	Token* token = this->scanner.nextToken();
		switch (token) {
			case Token::LeftBracket:

				break;
			default:
				break;
		}
}

void Parser::statements() {

}



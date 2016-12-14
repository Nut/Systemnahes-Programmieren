/*
 * Parser.cpp
 *
 *  Created on: 11.12.2016
 *      Author: Denis
 */

Parser::Parser(const char* filename) {
	this->scanner = new Scanner(filename);
}

Parser::~Parser() {
	delete this->scanner;
}

ParseTree* Parser::parse() {
	return new ParseTree();
}

void Parser::prog() {
	Node decls = new Node();
	Node statements = new Node();
}

void Parser::decls() {

}



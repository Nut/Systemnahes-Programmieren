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
	decls();
	statements();
}

void Parser::decls() {

}

void Parser::statements() {

}



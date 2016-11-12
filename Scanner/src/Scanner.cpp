/*
 * Scanner.cpp
 *
 *  Created on: Sep 26, 2012
 *      Author: knad0001
 */

#include "../includes/Scanner.h"
#include <cstring>

Scanner::Scanner(char* filename, Symboltable* symtab) {
	this->automat = new Automat();
	this->buffer = new Buffer(filename);
	this->symboltable = symtab;
}

Scanner::~Scanner() {
	// TODO Auto-generated destructor stub
}

Token* Scanner::nextToken() {
	char nextChar;
	while(!automat->isStop()) {
		nextChar = buffer->getChar();
		automat->read(nextChar);
	}
	Token* token = createToken();
	buffer->ungetChar(automat->getBack());
	automat->reset();
	return token;
}

Token* Scanner::createToken() {
	switch(automat->getLastFinalState()) {
		case Automat::Eof:
			return NULL;
		case Automat::Error:
			return new Token(Token::Unknown, 0, 0, NULL, NULL, automat->getLexem());
		case Automat::Identifier:
			return new Token(Token::Identifier, 0, 0, symboltable->insert(automat->getLexem()), NULL, NULL);
		case Automat::Integer:
			return new Token(Token::Integer, 0, 0, NULL, NULL , NULL);
		default:
			return NULL;
	}
}

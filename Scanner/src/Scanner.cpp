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
		case Automat::DoubleAnd:
			return new Token(Token::And, 0, 0, NULL, NULL , NULL);
		case Automat::Equal:
			return new Token(Token::Equal, 0, 0, NULL, NULL , NULL);
		case Automat::Assign:
			return new Token(Token::Assign, 0, 0, NULL, NULL , NULL);
		case Automat::Colon:
			return new Token(Token::Colon, 0, 0, NULL, NULL , NULL);
		case Automat::ColonBetweenEqualFinal:
			return new Token(Token::ColonBetweenEqual, 0, 0, NULL, NULL , NULL);
		case Automat::CommentFinal:
			return new Token(Token::Null, 0, 0, NULL, NULL, NULL);
		case Automat::Sign:
			if (*automat->getLexem() == ';') {
				return new Token(Token::Semicolon, 0, 0, NULL, NULL, NULL);
			} else if (*automat->getLexem() == '+') {
				return new Token(Token::Plus, 0, 0, NULL, NULL, NULL);
			} else if (*automat->getLexem() == '-') {
				return new Token(Token::Minus, 0, 0, NULL, NULL, NULL);
			} else if (*automat->getLexem() == '*') {
				return new Token(Token::Star, 0, 0, NULL, NULL, NULL);
			} else if (*automat->getLexem() == '<') {
				return new Token(Token::LessThan, 0, 0, NULL, NULL, NULL);
			} else if (*automat->getLexem() == '>') {
				return new Token(Token::GreaterThan, 0, 0, NULL, NULL, NULL);
			} else if (*automat->getLexem() == '!') {
				return new Token(Token::Exclamation, 0, 0, NULL, NULL, NULL);
			} else if (*automat->getLexem() == '(') {
				return new Token(Token::LeftParent, 0, 0, NULL, NULL, NULL);
			} else if (*automat->getLexem() == ')') {
				return new Token(Token::RightParent, 0, 0, NULL, NULL, NULL);
			} else if (*automat->getLexem() == ') {') {
				return new Token(Token::LeftCurved, 0, 0, NULL, NULL, NULL);
			} else if (*automat->getLexem() == '}') {
				return new Token(Token::RightCurved, 0, 0, NULL, NULL, NULL);
			} else if (*automat->getLexem() == '[') {
				return new Token(Token::LeftBracket, 0, 0, NULL, NULL, NULL);
			} else if (*automat->getLexem() == ']') {
				return new Token(Token::RightBracket, 0, 0, NULL, NULL, NULL);
			}

	}
}

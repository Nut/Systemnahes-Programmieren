/*
 * Scanner.cpp
 *
 *  Created on: Sep 26, 2012
 *      Author: knad0001
 */

#include "../includes/Scanner.h"
#include <cstring>
#include <cstdlib>
#include <cerrno>

Scanner::Scanner(char* filename, Symboltable* symtab) {
	this->automat = new Automat();
	this->buffer = new Buffer(filename);
	this->symboltable = symtab;
}

Scanner::~Scanner() {
	delete automat;
	delete buffer;
}

Token* Scanner::nextToken() {
	while (!automat->isStop()) {
		char symbol = buffer->getChar();
		unsigned int line = buffer->getLine();
		unsigned int column = buffer->getColumn();
		automat->read(symbol, line, column);
	}
	Token* token = createToken();
	buffer->ungetChar(automat->getBack());
	automat->reset();
	return token;
}

Token* Scanner::createToken() {
	switch (automat->getLastFinalState()) {
		case Automat::Error:
			return new Token(Token::Unknown, automat->getLine(), automat->getColumn(), NULL, NULL, *automat->getLexem());
		case Automat::Identifier:
			return new Token(Token::Identifier, automat->getLine(), automat->getColumn(), symboltable->insert(automat->getLexem()), NULL, NULL);
		case Automat::Integer: {
			errno = 0;
			long temp = std::strtol(automat->getLexem(), NULL, 10);
			if (errno == ERANGE) {
				return new Token(Token::Error, automat->getLine(), automat->getColumn(), NULL, NULL, NULL);
			} else{
				return new Token(Token::Integer, automat->getLine(), automat->getColumn(), NULL, temp , NULL);
			}
		}
		case Automat::DoubleAnd:
			return new Token(Token::And,automat->getLine(), automat->getColumn(), NULL, NULL , NULL);
		case Automat::Equal:
			return new Token(Token::Equal, automat->getLine(), automat->getColumn(), NULL, NULL , NULL);
		case Automat::Assign:
			return new Token(Token::Assign, automat->getLine(), automat->getColumn(), NULL, NULL , NULL);
		case Automat::Colon:
			return new Token(Token::Colon, automat->getLine(), automat->getColumn(), NULL, NULL , NULL);
		case Automat::ColonBetweenEqualFinal:
			return new Token(Token::ColonBetweenEqual, automat->getLine(), automat->getColumn(), NULL, NULL , NULL);
		case Automat::CommentFinal:
			return new Token(Token::Null, automat->getLine(), automat->getColumn(), NULL, NULL, NULL);
		case Automat::Sign:
			if (*automat->getLexem() == ';') {
				return new Token(Token::Semicolon, automat->getLine(), automat->getColumn(), NULL, NULL, NULL);
			} else if (*automat->getLexem() == '+') {
				return new Token(Token::Plus, automat->getLine(), automat->getColumn(), NULL, NULL, NULL);
			} else if (*automat->getLexem() == '-') {
				return new Token(Token::Minus, automat->getLine(), automat->getColumn(), NULL, NULL, NULL);
			} else if (*automat->getLexem() == '*') {
				return new Token(Token::Star, automat->getLine(), automat->getColumn(), NULL, NULL, NULL);
			} else if (*automat->getLexem() == '<') {
				return new Token(Token::LessThan, automat->getLine(), automat->getColumn(), NULL, NULL, NULL);
			} else if (*automat->getLexem() == '>') {
				return new Token(Token::GreaterThan, automat->getLine(), automat->getColumn(), NULL, NULL, NULL);
			} else if (*automat->getLexem() == '!') {
				return new Token(Token::Exclamation, automat->getLine(), automat->getColumn(), NULL, NULL, NULL);
			} else if (*automat->getLexem() == '(') {
				return new Token(Token::LeftParent, automat->getLine(), automat->getColumn(), NULL, NULL, NULL);
			} else if (*automat->getLexem() == ')') {
				return new Token(Token::RightParent, automat->getLine(), automat->getColumn(), NULL, NULL, NULL);
			} else if (*automat->getLexem() == '{') {
				return new Token(Token::LeftCurved, automat->getLine(), automat->getColumn(), NULL, NULL, NULL);
			} else if (*automat->getLexem() == '}') {
				return new Token(Token::RightCurved, automat->getLine(), automat->getColumn(), NULL, NULL, NULL);
			} else if (*automat->getLexem() == '[') {
				return new Token(Token::LeftBracket, automat->getLine(), automat->getColumn(), NULL, NULL, NULL);
			} else if (*automat->getLexem() == ']') {
				return new Token(Token::RightBracket, automat->getLine(), automat->getColumn(), NULL, NULL, NULL);
			}
		case Automat::Eof:
		default:
			return NULL;
	}
}

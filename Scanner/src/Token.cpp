/*
 * Token.cpp
 *
 *  Created on: Nov 2, 2016
 *      Author: hede1021
 */

#include "../includes/Token.h"

Token::Token(TType type, int line, int column) {
		this->type = type;
		this->line = line;
		this->column = column;
}

Token::Token(int line, int column, int value) {
		this->type = Integer;
		this->line = line;
		this->column = column;
		this->value = value;
}

Token::Token(int line, int column, int infoKey) {
		this->type = Identifier;
		this->line = line;
		this->column = column;
		this->infoKey = infoKey;
}

Token::~Token() {

}

int Token::getColumn() {
	return column;
}

int Token::getLine() {
	return line;
}

int Token::getValue() {
	return value;
}

int Token::getInfoKey() {
	return infoKey;
}





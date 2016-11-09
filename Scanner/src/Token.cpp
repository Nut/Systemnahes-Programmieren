/*
 * Token.cpp
 *
 *  Created on: Nov 2, 2016
 *      Author: hede1021
 */

#include "../includes/Token.h"

Token::Token(Token::TType type, int line, int column, int infoKey, int value) {
		this->type = type;
		this->line = line;
		this->column = column;
		if (infoKey != NULL) {
			this->infoKey = infoKey;
		}
		if (value != NULL) {
			this->value = value;
		}
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

Token::TType Token::getType() {
	return type;
}

char* Token::typeToString()
{
    switch (this->type)
    {
        case Token::Identifier:   return "Identifier";
        default:      return "[Unknown Type]";
    }
}

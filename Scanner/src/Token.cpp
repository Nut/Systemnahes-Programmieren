/*
 * Token.cpp
 *
 *  Created on: Nov 2, 2016
 *      Author: hede1021
 */

#include "../includes/Token.h"

Token::Token(Token::TType type, int line, int column, unsigned int infoKey, unsigned long value,
		char symbol) {
	this->type = type;
	this->line = line;
	this->column = column;
	this->infoKey = infoKey;
	this->value = value;
	this->symbol = symbol;
}

Token::~Token() {

}

int Token::getColumn() {
	return this->column;
}

int Token::getLine() {
	return this->line;
}

unsigned long Token::getValue() {
	return this->value;
}

unsigned int Token::getInfoKey() {
	return this->infoKey;
}

char Token::getSymbol() {
	return this->symbol;
}

Token::TType Token::getType() {
	return type;
}

char* Token::typeToString() {
	switch (this->type) {
	case Token::Identifier:
		return "Identifier";
	case Token::Integer:
		return "Integer";
	case Token::Unknown:
		return "Unknown";
	case Token::Assign:
		return "Assign";
	case Token::Plus:
		return "Plus";
	case Token::Minus:
		return "Minus";
	case Token::Colon:
		return "Colon";
	case Token::Star:
		return "Star";
	case Token::LessThan:
		return "LessThan";
	case Token::GreaterThan:
		return "GreaterThan";
	case Token::Equal:
		return "Equal";
	case Token::ColonBetweenEqual:
		return "ColonBetweenEqual";
	case Token::Exclamation:
		return "Exclamation";
	case Token::And:
		return "And";
	case Token::Semicolon:
		return "Semicolon";
	case Token::LeftParent:
		return "LeftParent";
	case Token::RightParent:
		return "RightParent";
	case Token::LeftCurved:
		return "LeftCurved";
	case Token::RightCurved:
		return "RightCurved";
	case Token::LeftBracket:
		return "LeftBracket";
	case Token::RightBracket:
		return "RightBracket";
	case Token::WhileToken:
		return "WhileToken";
	case Token::IfToken:
		return "IfToken";
	case Token::Error:
		return "Error";
	default:
		return "[Unknown Type]";
	}
}

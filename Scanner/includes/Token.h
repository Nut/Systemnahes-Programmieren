/*
 * Token.h
 *
 *  Created on: Nov 2, 2016
 *      Author: hede1021
 */

#ifndef SCANNER_INCLUDES_TOKEN_H_
#define SCANNER_INCLUDES_TOKEN_H_
#include "../../Symboltable/includes/Information.h"

class Token {
public:

	enum TType {
		While,
		Else,
		Int,
		Read,
		Write,
		If,
		Identifier,
		Assign,
		Integer,
		Plus,
		Minus,
		Colon,
		Star,
		LessThan,
		GreaterThan,
		Equal,
		ColonBetweenEqual,
		Exclamation,
		And,
		Semicolon,
		LeftParent,
		RightParent,
		LeftCurved,
		RightCurved,
		LeftBracket,
		RightBracket,
		Unknown,
		Null,
		Error
	};
	Token(Token::TType type, int line, int column, Information* info, unsigned long value, char symbol);
	virtual ~Token();
	int getLine();
	int getColumn();
	unsigned long getValue();
	Information* getInfo();
	char getSymbol();
	Token::TType getType();
	char* typeToString();
private:
	Token::TType type;
	int line;
	int column;
	unsigned long value;
	Information* info;
	char symbol;
};



#endif /* SCANNER_INCLUDES_TOKEN_H_ */

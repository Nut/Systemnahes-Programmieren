/*
 * Token.h
 *
 *  Created on: Nov 2, 2016
 *      Author: hede1021
 */

#ifndef SCANNER_INCLUDES_TOKEN_H_
#define SCANNER_INCLUDES_TOKEN_H_
#include <cstring>

class Token {
public:

	enum TType {
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
		WhileToken,
		IfToken,
		Unknown,
		Null,
		Error
	};
	Token(Token::TType type, int line, int column, unsigned int infoKey, unsigned long value, char symbol);
	virtual ~Token();
	int getLine();
	int getColumn();
	unsigned long getValue();
	unsigned int getInfoKey();
	char getSymbol();
	Token::TType getType();
	char* typeToString();
private:
	Token::TType type;
	int line;
	int column;
	unsigned long value;
	unsigned int infoKey;
	char symbol;
};



#endif /* SCANNER_INCLUDES_TOKEN_H_ */

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
		Unknown
	};
	Token(Token::TType type, int line, int column, int infoKey, int value, char* symbol);
	virtual ~Token();
	int getLine();
	int getColumn();
	int getValue();
	int getInfoKey();
	Token::TType getType();
	char* typeToString();
private:
	Token::TType type;
	int line;
	int column;
	int value = NULL;
	int infoKey = NULL;
	char* symbol = NULL;
};



#endif /* SCANNER_INCLUDES_TOKEN_H_ */

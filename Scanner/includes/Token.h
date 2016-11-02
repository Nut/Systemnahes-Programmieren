/*
 * Token.h
 *
 *  Created on: Nov 2, 2016
 *      Author: hede1021
 */

#ifndef SCANNER_INCLUDES_TOKEN_H_
#define SCANNER_INCLUDES_TOKEN_H_
#include <iostream>;

class Token {
public:

	enum TType {
		Identifier,
		Assign,
		Integer,
		Plus,
		Minus,
		Semicolon
	};
	Token(TType type, int line, int column);
	Token(int line, int column, int infoKey);
	Token(int line, int column, int value);
	virtual ~Token();
	int getLine();
	int getColumn();
	int getValue();
	int getInfoKey();
	TType getType();
private:
	TType type;
	int line;
	int column;
	int value = NULL;
	int infoKey = NULL;
};



#endif /* SCANNER_INCLUDES_TOKEN_H_ */

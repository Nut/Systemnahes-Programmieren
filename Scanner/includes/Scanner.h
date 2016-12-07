/*
 * Scanner.h
 *
 *  Created on: Sep 26, 2012
 *      Author: knad0001
 */

#ifndef SCANNER_H_
#define SCANNER_H_

#include "Token.h"
#include "../../Automat/includes/Automat.h"
#include "../../Buffer/includes/Buffer.h"
#include "../../Symboltable/includes/Symboltable.h"

class Scanner {
public:
	Scanner(char* filename, Symboltable* symtab);
	virtual ~Scanner();
	Token* nextToken();
	int main(int argc, char **argv);

private:
	int stringCompare( const char *s1, const char *s2);
	char* whileUpper = "WHILE";
	char* whileLower = "while";
	char* read = "read";
	char* write = "write";
	char* ifUpper = "IF";
	char* ifLower = "if";
	char* elseUpper = "ELSE";
	char* elseLower = "else";
	Automat* automat;
	Buffer* buffer;
	Symboltable* symboltable;
	Token* createToken();
};


#endif /* SCANNER_H_ */

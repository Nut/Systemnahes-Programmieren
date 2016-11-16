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
private:
	Automat* automat;
	Buffer* buffer;
	Symboltable* symboltable;
	Token* createToken();
	unsigned int atoi(const char *c);
};

#endif /* SCANNER_H_ */

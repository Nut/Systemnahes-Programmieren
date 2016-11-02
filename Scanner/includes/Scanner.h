/*
 * Scanner.h
 *
 *  Created on: Sep 26, 2012
 *      Author: knad0001
 */

#ifndef SCANNER_H_
#define SCANNER_H_
#include "Token.h";

class Scanner {
public:
	Scanner(char* filename);
	virtual ~Scanner();
	Token nextToken();
};

#endif /* SCANNER_H_ */

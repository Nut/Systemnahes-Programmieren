/*
 * Scanner.cpp
 *
 *  Created on: Sep 26, 2012
 *      Author: knad0001
 */

#include "../includes/Scanner.h"
#include "../../Automat/includes/Automat.h"
#include "../../Buffer/includes/Buffer.h"
#include "../../Symboltable/includes/Symboltable.h"


Scanner::Scanner(char* filename) {
	automat = new Automat();
	buffer = new Buffer(filename);
	symboltable = new Symboltable();
}

Scanner::~Scanner() {
	// TODO Auto-generated destructor stub
}

Token Scanner::nextToken() {
	char nextChar;
	while(automat->getLastFinalState() == NULL) {
		nextChar = buffer->getChar;
	}
	return createToken(automat->getLastFinalState());
}

Token Scanner::createToken(Automat::State state) {
	switch(state) {
	case Automat:Error:
		return new Token(Token::Unknown, 0, 0);
	case Automat:Indentifier:
		int infoKey = symboltable->insert(lexem);
		return new Token(0, 0, infoKey);
	}
}

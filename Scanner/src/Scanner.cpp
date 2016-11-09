/*
 * Scanner.cpp
 *
 *  Created on: Sep 26, 2012
 *      Author: knad0001
 */

#include "../includes/Scanner.h"
#include <cstring>

Scanner::Scanner(char* filename, Symboltable* symtab) {
	automat = new Automat();
	buffer = new Buffer(filename);
	symboltable = symtab;
	lexem = new char[1024];
}

Scanner::~Scanner() {
	// TODO Auto-generated destructor stub
}

Token* Scanner::nextToken() {
	char nextChar;
	int i = 0;
	while(!automat->isStop()) {
		nextChar = buffer->getChar();
		if (nextChar == '\0') {
			break;
		}
		automat->read(nextChar);
		lexem[i] = nextChar;
		i++;
		//cout << "Current: " << automat->getCurrentState() << endl;
		//cout << "Last final State: " << automat->getLastFinalState() << endl;
	}
	return createToken(automat->getLastFinalState());
}

Token* Scanner::createToken(Automat::State state) {
	//cout << "Automat State: " << state << endl;
	automat->reset();
	switch(state) {
	case Automat::Error:
		//cout << "Case Error" << endl;
		return new Token(Token::Unknown, 0, 0, NULL, NULL, lexem);
	case Automat::Identifier:
		//cout << "Case Identifier" << endl;
		unsigned int infoKey = symboltable->insert(lexem);
		//cout << "Infokey: " << infoKey << endl;
		lexem = new char[1024];
		return new Token(Token::Identifier, 0, 0, infoKey, NULL, NULL);
	}
}

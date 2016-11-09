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
}

Scanner::~Scanner() {
	// TODO Auto-generated destructor stub
}

Token* Scanner::nextToken() {
	char nextChar;
	while(automat->getLastFinalState() == Automat::Null) {
		nextChar = buffer->getChar();
		if (nextChar == '\0') {
			return NULL;
		}
		automat->read(nextChar);
		lexem += nextChar;
		cout << "Current: " << automat->getCurrentState() << endl;
		cout << "Last final State: " << automat->getLastFinalState() << endl;
	}
	return createToken(automat->getLastFinalState());
}

Token* Scanner::createToken(Automat::State state) {
	cout << "Automat State: " << state << endl;
	automat->setLastFinalState(Automat::Null);

	switch(state) {
	case Automat::Error:
		cout << "Case Error" << endl;
		return new Token(Token::Unknown, 0, 0, NULL, NULL);
	case Automat::Identifier:
		cout << "Case Identifier" << endl;
		unsigned int infoKey = symboltable->insert("test");
		cout << "Infokey: " << infoKey << endl;
		//lexem = ""; //reset lexem
		return new Token(Token::Identifier, 0, 0, infoKey, NULL);
	}
}

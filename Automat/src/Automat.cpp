/*
 * Automat.cpp
 *
 */

#include "../includes/Automat.h"
#include <iostream>
#include <cstring>
#include <ctype.h>

Automat::Automat() {
	this->currentState = Start;
	this->lastFinalState = Null;
	this->back = 0;
	this->stop = false;
	clearLexem();
}

Automat::~Automat() {
	// TODO Auto-generated destructor stub
}

Automat::State Automat::getCurrentState() {
	return this->currentState;
}

Automat::State Automat::getLastFinalState() {
	return this->lastFinalState;
}

void Automat::setLastFinalState(Automat::State state) {
	this->lastFinalState = state;
}

int Automat::getBack() {
	return this->back;
}

void Automat::setBack(int steps) {
	this->back = steps;
}

bool Automat::isStop() {
	return this->stop;
}

char* Automat::getLexem() {
	return this->lexem;
}

unsigned int Automat::getLine() {
	return this->line;
}

unsigned int Automat::getColumn() {
	return this->column;
}

void Automat::reset() {
	this->currentState = Start;
	this->lastFinalState = Null;
	this->back = 0;
	this->stop = false;
	clearLexem();
}

void Automat::clearLexem() {
	this->indexLexem = 0;
	delete[] lexem;
    this->lexem = new char[1024];
    for (int i = 0; i <= 1024; ++i) {
    	lexem[i] = '\0';
	}
}

bool Automat::isSign(char c) {
	if (c == '+' || c == '-' || c == '<' || c == '>' || c == '!' || c == ';' ||
	    c == '(' || c == ')' || c == '{' || c == '}' || c == '[' || c == ']') {
		return true;
	} else {
		return false;
	}
}

void Automat::read(char c, unsigned int line, unsigned int column) {
	switch (currentState) {
		case Start:
			this->line = line;
			this->column = column;
			if (isalpha(c)) {
				this->currentState = Identifier;
				this->lastFinalState = Identifier;
				lexem[indexLexem++] = c;
			} else if (isdigit(c)) {
				this->currentState = Integer;
				this->lastFinalState = Integer;
				lexem[indexLexem++] = c;
			} else if (c == '=') {
				this->currentState = Equal;
				this->lastFinalState = Equal;
			} else if (c == '&') {
				this->currentState = And;
			} else if (c == ':') {
				this->currentState = Colon;
				this->lastFinalState = Colon;
			} else if (isSign(c)) {
				this->lastFinalState = Sign;
				lexem[indexLexem++] = c;
				stop = true;
			} else if (c == ' ' || c == '\n') {
				this->currentState = Start;
			} else if (c == '\0') {
				this->lastFinalState = Eof;
				stop = true;
			} else {
				this->lastFinalState = Error;
				lexem[indexLexem++] = c;
				stop = true;
			}
			break;
		case Identifier:
			if (!(isalpha(c) || isdigit(c))) {
				stop = true;
				if (c != '\0') {
					this->back++;
				}
			} else {
				lexem[indexLexem++] = c;
			}
			break;
		case Integer:
			if (!isdigit(c)) {
				stop = true;
				if (c != '\0') {
					this->back++;
				}
			} else {
				lexem[indexLexem++] = c;
			}
			break;
		case Colon:
			if (c == '=') {
				this->lastFinalState = Assign;
				stop = true;
			} else if (c == '*') {
				this->currentState = CommentStart;
				this->back++;
			} else {
				if (c != '\0') {
					this->back++;
				}
				stop = true;
			}
			break;
		case Equal:
			if (c == ':') {
				this->currentState = ColonBetweenEqual;
			} else {
				if (c != '\0') {
					this->back++;
				}
				stop = true;
			}
			break;
		case And:
			if (c == '&') {
				this->lastFinalState = DoubleAnd;
			} else {
				this->lastFinalState = Error;
				lexem[indexLexem++] = c;
				if (c != '\0') {
					this->back++;
				}
			}
			stop = true;
			break;
		case ColonBetweenEqual:
			if (c == '=') {
				this->lastFinalState = ColonBetweenEqualFinal;
			} else {
				if (c != '\0') {
					this->back += 2;
				}
			}
			stop = true;
			break;
		case CommentStart:
			if (c == '\0') {
				this->lastFinalState = CommentFinal;
				stop = true;
			} else if (c == '*') {
				this->currentState = CommentClose;
				this->back++;
			}
			break;
		case CommentClose:
			if (c == ':' || c == '\0') {
				this->lastFinalState = CommentFinal;
				this->back = 0;
				stop = true;
			} else {
				this->currentState = CommentStart;
			}
			break;
	}
}

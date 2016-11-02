/*
 * Automat.cpp
 *
 */

#include "../includes/Automat.h"
#include <ctype.h>

Automat::Automat() {
	this->currentState = Start;
	this->lastFinalState = Null;
	this->back = 0;
}

Automat::~Automat() {
	// TODO Auto-generated destructor stub
}

void Automat::read(char c) {
	switch (currentState) {
	case Start:
		if (isalpha(c)) {
			this->currentState = Identifier;
		} else if (isdigit(c)) {
			this->currentState = Integer;
		} else {
			this->currentState = Error;
		}
		break;
	case Identifier:
		if (isalpha(c)) {
			this->currentState = Identifier;
		} else if (isdigit(c)) {
			this->currentState = Identifier;
		} else {
			this->lastFinalState = Identifier;
			this->currentState = Start;
		}
		break;
	default:
		break;
	}
}

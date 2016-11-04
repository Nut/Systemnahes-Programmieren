/*
 * Automat.cpp
 *
 */

#include "../includes/Automat.h"
#include <ctype.h>
#include <iostream>

Automat::Automat() {
	this->currentState = Start;
	this->lastFinalState = NULL;
	this->back = 0;
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

void Automat::read(char c) {
	switch (currentState) {
		case Start:
			if (isalpha(c)) {
				this->currentState = Identifier;
			} else if (isdigit(c)) {
				this->currentState = Integer;
			} else {
				this->lastFinalState = Error;
				this->currentState = Start;
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

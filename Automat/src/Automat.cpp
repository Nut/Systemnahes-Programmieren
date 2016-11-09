/*
 * Automat.cpp
 *
 */

#include "../includes/Automat.h"
#include <ctype.h>
#include <cstring>

Automat::Automat() {
	this->currentState = Start;
	this->lastFinalState = Null;
	this->back = 0;
	this->stop = false;
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

void Automat::reset() {
	this->currentState = Start;
	this->lastFinalState = Null;
	this->back = 0;
	this->stop = false;
}

void Automat::read(char c) {
	switch (currentState) {
		case Start:
			if (isalpha(c)) {
				this->currentState = Identifier;
				this->lastFinalState = Identifier;
			} else if (isdigit(c)) {
				this->currentState = Integer;
				this->lastFinalState = Integer;
			} else if (c == '='){
				this->lastFinalState = Equal;
			} else if (c == '&'){
				this->currentState = And;
			} else if (c == ':'){
				this->lastFinalState = Colon;
			} else if (c == '+' || c == '-' || c == '<' || c == '>' || c == '!' || c == ';' ||
					   c == '(' || c == ')' || c == '{' || c == '}' || c == '[' || c == ']') {
				this->lastFinalState = Sign;
			} else if (c == ' '){
				this->lastFinalState = Start;
			} else {
				this->lastFinalState = Error;
			}
			break;
		case Identifier:
			if (!(isalpha(c) || isdigit(c))) {
				stop = true;
				this->back++;
			}
			break;
		case Integer:
			if (isdigit(c)) {
				this->currentState = Integer;
			} else {
				this->lastFinalState = Integer;
				this->currentState = Error;
			}
			break;
		case Colon:
			break;
		case Assign:
			break;
		case Equal:
			break;
		case And:
			break;
		case DoubleAnd:
			break;
		case ColonBetweenEqual:
			break;
		case ColonBetweenEqualFinal:
			break;
		case CommentStart:
			break;
		case CommentClose:
			break;
		case CommentFinal:
			break;
		case Sign:
			break;
		case Eof:
			break;
		case Null:
			break;
		default:
			break;
	}
}

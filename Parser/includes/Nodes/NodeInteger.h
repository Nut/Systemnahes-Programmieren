/*
 * NodeInteger.h
 *
 *  Created on: 14.01.2017
 *      Author: yannick
 */

#ifndef PARSER_INCLUDES_NODES_NODEINTEGER_H_
#define PARSER_INCLUDES_NODES_NODEINTEGER_H_

#include "../../../Scanner/includes/Token.h"

class NodeInteger: public Node {
private:
	long int value;
	Token* token;

public:
	NodeInteger(long int value, Token* token) {
		this->value = value;
	}

	~NodeInteger() {}

	void addInteger(long int value) {
		this->value = value;
	}

	void accept(ParseTreeVisitor* visitor) {
		visitor->visitNode(this);
	}

	long int getValue() {
		return this->value;
	}

	unsigned int getLine() {
		return this->token->getLine();
	}

	unsigned int getColumn() {
		return this->token->getColumn();
	}
};


#endif /* PARSER_INCLUDES_NODES_NODEINTEGER_H_ */

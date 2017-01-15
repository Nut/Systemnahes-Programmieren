/*
 * NodeInteger.h
 *
 *  Created on: 14.01.2017
 *      Author: yannick
 */

#ifndef PARSER_INCLUDES_NODES_NODEINTEGER_H_
#define PARSER_INCLUDES_NODES_NODEINTEGER_H_


class NodeInteger: public Node {
private:
	long int value;
public:
	NodeInteger(long int value) {
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
};


#endif /* PARSER_INCLUDES_NODES_NODEINTEGER_H_ */

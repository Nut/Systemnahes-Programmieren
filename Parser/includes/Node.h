/*
 * Node.h
 *
 *  Created on: 13.01.2017
 *      Author: yannick
 */

#ifndef PARSER_INCLUDES_NODES_NODE_H_
#define PARSER_INCLUDES_NODES_NODE_H_

#include "ParseTreeVisitor.h"

class Node {
public:
	enum NodeType {
		intType,
		intArrayType,
		arrayType,
		noType,
		errorType,
		opPlus,
		opMinus,
		opMult,
		opDiv,
		opLess,
		opGreater,
		opEqual,
		opUnEqual,
		opAnd
	};

	Node();
	virtual ~Node();
	virtual void setType(Node::NodeType type);
	virtual Node::NodeType getType();
	virtual void accept(ParseTreeVisitor* visitor);
	unsigned int getLine();
	unsigned int getColumn();

	Node::NodeType type;

private:
	//Token* token;
};



#endif /* PARSER_INCLUDES_NODES_NODE_H_ */

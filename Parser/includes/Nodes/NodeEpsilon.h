/*
 * NodeEpsilon.h
 *
 *  Created on: 13.01.2017
 *      Author: yannick
 */

#ifndef PARSER_INCLUDES_NODES_NODEEPSILON_H_
#define PARSER_INCLUDES_NODES_NODEEPSILON_H_

//#include "NodeIndex.h"

class NodeEpsilon: public NodeDecls, public NodeArray, public NodeStatements, public NodeIndex, public NodeOpExp {
public:
	virtual ~NodeEpsilon () {}

	void accept(ParseTreeVisitor* visitor) {
		visitor->visitNode(this);
	}

	void setEpsilonType(Node::NodeType type) {
		this->type = type;
	}

	Node::NodeType getEpsilonType() {
		return this->type;
	}

private:
	Node::NodeType type;
};


#endif /* PARSER_INCLUDES_NODES_NODEEPSILON_H_ */

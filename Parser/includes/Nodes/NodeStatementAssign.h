/*
 * NodeStatementAssign.h
 *
 *  Created on: 08.01.2017
 *      Author: yannick
 */

#ifndef PARSER_INCLUDES_NODES_NODESTATEMENTASSIGN_H_
#define PARSER_INCLUDES_NODES_NODESTATEMENTASSIGN_H_

#include "NodeIndex.h"
#include "NodeExp.h"

class NodeStatementAssign: public NodeStatement {
private:
	NodeIdentifier* identifier;
	NodeIndex* index;
	NodeExp* exp;

public:
	void addNode(NodeIdentifier* identifier) {
		this->identifier = identifier;
	}

	void addNode(NodeIndex* index) {
		this->index = index;
	}

	void addNode(NodeExp* exp) {
		this->exp = exp;
	}
};


#endif /* PARSER_INCLUDES_NODES_NODESTATEMENTASSIGN_H_ */

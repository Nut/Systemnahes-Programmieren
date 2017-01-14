/*
 * NodeStatements.h
 *
 *  Created on: 08.01.2017
 *      Author: yannick
 */

#ifndef PARSER_INCLUDES_NODES_NODEINDEX_H_
#define PARSER_INCLUDES_NODES_NODEINDEX_H_

#include "NodeExp.h"

class NodeIndex: public Node {
private:
	NodeExp* exp;

public:

	~NodeIndex() {
		delete exp;
	}

	void addNode(NodeExp* exp) {
		this->exp = exp;
	}
};

#endif /* PARSER_INCLUDES_NODES_NODEINDEX_H_ */

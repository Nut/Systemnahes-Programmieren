/*
 * NodeExp.h
 *
 *  Created on: 08.01.2017
 *      Author: yannick
 */

#ifndef PARSER_INCLUDES_NODES_NODEEXP_H_
#define PARSER_INCLUDES_NODES_NODEEXP_H_

#include "NodeExp2.h"
#include "NodeOpExp.h"

class NodeExp: public Node {
private:
	NodeExp2* exp2;
	NodeOpExp* opExp;

public:

	~NodeExp() {
		delete exp2;
		delete opExp;
	}

	void addNode(NodeExp2* exp2) {
		this->exp2 = exp2;
	}

	void addNode(NodeOpExp* opExp) {
		this->opExp = opExp;
	}
};

#endif /* PARSER_INCLUDES_NODES_NODEEXP_H_ */

/*
 * NodeDecl.h
 *
 *  Created on: 08.01.2017
 *      Author: yannick
 */

#ifndef PARSER_INCLUDES_NODES_NODEDECL_H_
#define PARSER_INCLUDES_NODES_NODEDECL_H_

#include "NodeArray.h"

class NodeDecl: public Node {
private:
	NodeArray* array;
	//missing identifier

public:
	virtual ~NodeDecl() {
		delete this->array;
	}

	using Node::addNode;
	virtual void addNode(NodeArray* array) {
		this->array = array;
	}
};


#endif /* PARSER_INCLUDES_NODES_NODEDECL_H_ */

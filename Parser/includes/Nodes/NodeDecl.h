/*
 * NodeDecl.h
 *
 *  Created on: 08.01.2017
 *      Author: yannick
 */

#ifndef PARSER_INCLUDES_NODES_NODEDECL_H_
#define PARSER_INCLUDES_NODES_NODEDECL_H_

#include "Node.h"
#include "NodeArray.h"
#include "NodeIdentifier.h"

class NodeDecl: public Node {
private:
	NodeArray* array;
	NodeIdentifier* identifier;

public:
	void addNode(NodeArray* array) {
		this->array = array;
	}

	void addNode(NodeIdentifier* identifier) {
		this->identifier = identifier;
	}
};


#endif /* PARSER_INCLUDES_NODES_NODEDECL_H_ */

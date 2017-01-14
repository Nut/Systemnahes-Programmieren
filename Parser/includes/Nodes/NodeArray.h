/*
 * NodeArray.h
 *
 *  Created on: 08.01.2017
 *      Author: yannick
 */

#ifndef PARSER_INCLUDES_NODES_NODEARRAY_H_
#define PARSER_INCLUDES_NODES_NODEARRAY_H_

#include "NodeInteger.h"

class NodeArray: public Node {
private:
	NodeInteger* integer;

public:
	void addInteger(NodeInteger* integer) {
		this->integer = integer;
	}

	NodeInteger* getInteger() {
		return this->integer;
	}
};


#endif /* PARSER_INCLUDES_NODES_NODEARRAY_H_ */

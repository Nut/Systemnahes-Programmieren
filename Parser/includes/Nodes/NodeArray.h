/*
 * NodeArray.h
 *
 *  Created on: 08.01.2017
 *      Author: yannick
 */

#ifndef PARSER_INCLUDES_NODES_NODEARRAY_H_
#define PARSER_INCLUDES_NODES_NODEARRAY_H_

class NodeArray: public Node {
private:
	unsigned long integer;
public:
	void addInteger(unsigned long integer) {
		this->integer = integer;
	}
	unsigned long getInteger() {
		return this->integer;
	}
};


#endif /* PARSER_INCLUDES_NODES_NODEARRAY_H_ */

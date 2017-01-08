/*
 * Node.h
 *
 *  Created on: 20.12.2016
 *      Author: Denis
 */

#ifndef PARSER_INCLUDES_NODE_H_
#define PARSER_INCLUDES_NODE_H_


class Node {
public:
	virtual ~Node();
	virtual void addNode(Node* node);
};


#endif /* PARSER_INCLUDES_NODE_H_ */

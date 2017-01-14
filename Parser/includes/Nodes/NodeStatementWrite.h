/*
 * NodeStatementWrite.h
 *
 *  Created on: 08.01.2017
 *      Author: yannick
 */

#ifndef PARSER_INCLUDES_NODES_NODESTATEMENTWRITE_H_
#define PARSER_INCLUDES_NODES_NODESTATEMENTWRITE_H_

class NodeStatementWrite: public NodeStatement {
private:
	NodeExp* exp;

public:
	~NodeStatementWrite() {
		delete this->exp;
	}

	void addNode(NodeExp* exp) {
		this->exp = exp;
	}

};


#endif /* PARSER_INCLUDES_NODES_NODESTATEMENTWRITE_H_ */

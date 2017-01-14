/*
 * NodeStatementWhile.h
 *
 *  Created on: 08.01.2017
 *      Author: yannick
 */

#ifndef PARSER_INCLUDES_NODES_NODESTATEMENTWHILE_H_
#define PARSER_INCLUDES_NODES_NODESTATEMENTWHILE_H_

class NodeStatementWhile: public NodeStatement {
private:
	NodeExp* exp;
	NodeStatement* statement;

public:
	~NodeStatementWhile() {
		delete this->exp;
		delete this->statement;
	}

	void addNode(NodeExp* exp) {
		this->exp = exp;
	}

	void addNode(NodeStatement* statement) {
		this->statement = statement;
	}

};


#endif /* PARSER_INCLUDES_NODES_NODES_NODESTATEMENTWHILE_H_ */

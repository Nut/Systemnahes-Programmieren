/*
 * NodeStatementIf.h
 *
 *  Created on: 08.01.2017
 *      Author: yannick
 */

#ifndef PARSER_INCLUDES_NODES_NODESTATEMENTIF_H_
#define PARSER_INCLUDES_NODES_NODESTATEMENTIF_H_

class NodeStatementIf: public NodeStatement {
private:
	NodeExp* exp;
	NodeStatement* statementIf;
	NodeStatement* statementElse;

public:
	~NodeStatementIf() {
		delete this->exp;
		delete this->statementIf;
		delete this->statementElse;
	}

	void addNode(NodeExp* exp) {
		this->exp = exp;
	}

	void addNodeIf(NodeStatement* statementIf) {
		this->statementIf = statementIf;
	}

	void addNodeElse(NodeStatement* statementElse) {
		this->statementElse = statementElse;
	}

};


#endif /* PARSER_INCLUDES_NODES_NODESTATEMENTIF_H_ */

/*
 * NodeStatements.h
 *
 *  Created on: 08.01.2017
 *      Author: yannick
 */

#ifndef PARSER_INCLUDES_NODES_NODESTATEMENTS_H_
#define PARSER_INCLUDES_NODES_NODESTATEMENTS_H_

class NodeStatements {
private:
	//NodeStatement* statement;
	NodeStatements* statements;

public:

	~NodeStatements() {
		//delete this->statement;
		delete this->statements;
	}

	/*virtual void addNode(NodeStatement* statement) {
		this->statement = statement;
	}*/

	void addNode(NodeStatements* statements) {
		this->statements = statements;
	}
};

#endif /* PARSER_INCLUDES_NODES_NODESTATEMENTS_H_ */

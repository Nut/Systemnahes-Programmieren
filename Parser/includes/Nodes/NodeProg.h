/*
 * NodeProg.h
 *
 *  Created on: 07.01.2017
 *      Author: yannick
 */

#ifndef PARSER_INCLUDES_NODES_NODEPROG_H_
#define PARSER_INCLUDES_NODES_NODEPROG_H_

#include "NodeDecls.h"
#include "NodeStatements.h"

class NodeProg {
private:
	NodeDecls* decls;
	NodeStatements* statements;

public:
	~NodeProg() {
		delete this->decls;
		delete this->statements;
	}

	void addNode(NodeDecls* decls) {
		this->decls = decls;
	}

	void addNode(NodeStatements* statements) {
		this->statements = statements;
	}
};


#endif /* PARSER_INCLUDES_NODES_NODEPROG_H_ */

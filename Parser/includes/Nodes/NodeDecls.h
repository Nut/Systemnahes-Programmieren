/*
 * NodeDecls.h
 *
 *  Created on: 08.01.2017
 *      Author: yannick
 */

#ifndef PARSER_INCLUDES_NODES_NODEDECLS_H_
#define PARSER_INCLUDES_NODES_NODEDECLS_H_

#include "NodeDecl.h"

class NodeDecls {
private:
	NodeDecl* decl;
	NodeDecls* decls;

public:
	~NodeDecls() {
		delete this->decl;
		delete this->decls;
	}

	void addNode(NodeDecl* decl) {
		this->decl = decl;
	}

	void addNode(NodeDecls* decls) {
		this->decls = decls;
	}
};

#endif /* PARSER_INCLUDES_NODES_NODEDECLS_H_ */

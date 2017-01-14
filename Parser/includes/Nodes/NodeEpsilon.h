/*
 * NodeEpsilon.h
 *
 *  Created on: 13.01.2017
 *      Author: yannick
 */

#ifndef PARSER_INCLUDES_NODES_NODEEPSILON_H_
#define PARSER_INCLUDES_NODES_NODEEPSILON_H_

//#include "NodeIndex.h"

class NodeEpsilon: public NodeDecls, public NodeArray, public NodeStatements, public NodeIndex, public NodeOpExp {
public:
	virtual ~NodeEpsilon () {}
};



#endif /* PARSER_INCLUDES_NODES_NODEEPSILON_H_ */

/*
 * NodeIdentifier.h
 *
 *  Created on: 08.01.2017
 *      Author: yannick
 */

#ifndef PARSER_INCLUDES_NODES_NODEIDENTIFIER_H_
#define PARSER_INCLUDES_NODES_NODEIDENTIFIER_H_

#include "../../../Symboltable/includes/Information.h"

class NodeIdentifier: public Node {
private:
	Information* information;
public:
	void addInformation(Information* information) {
		this->information = information;
	}

	void accept(ParseTreeVisitor* visitor) {
		visitor->visitNode(this);
	}

	Information* getInformation() {
		return this->information;
	}
};


#endif /* PARSER_INCLUDES_NODES_NODEIDENTIFIER_H_ */

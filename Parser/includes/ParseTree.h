#ifndef PARSETREE_H_
#define PARSETREE_H_

#include "Node.h"

class ParseTree {

public:
	ParseTree();
	void addProg(Node* node);
	Node getNodeProg();
private:
	Node nodeProg;
};


#endif /* PARSETREE_H_ */

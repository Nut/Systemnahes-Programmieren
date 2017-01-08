#ifndef PARSER_H_
#define PARSER_H_

#include "../../Scanner/includes/Token.h"
#include "../../Scanner/includes/Scanner.h"
#include "Nodes/Node.h"
#include "Nodes/NodeProg.h"
#include "Nodes/NodeDecls.h"
#include "Nodes/NodeDecl.h"
#include "Nodes/NodeArray.h"
#include "Nodes/NodeStatements.h"
#include "ParseTree.h"

class Parser {
public:
	Parser(char* filename);
	virtual ~Parser();
	ParseTree* parse();

private:
	Scanner* scanner;
	ParseTree* tree;
	NodeProg* prog();
	NodeDecls* decls();
	NodeDecl* decl();
	NodeArray* array();
	NodeStatements* statements();
};


#endif /* PARSER_H_ */

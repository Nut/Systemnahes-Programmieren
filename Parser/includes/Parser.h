#ifndef PARSER_H_
#define PARSER_H_

#include "../../Scanner/includes/Token.h"
#include "../../Scanner/includes/Scanner.h"
#include "Nodes/NodeProg.h"
#include "Nodes/NodeDecls.h"
#include "Nodes/NodeDecl.h"
#include "Nodes/NodeArray.h"
#include "Nodes/NodeStatements.h"
#include "Nodes/NodeIdentifier.h"
#include "Nodes/NodeStatement.h"
#include "Nodes/NodeStatementAssign.h"
#include "Nodes/NodeIndex.h"
#include "Nodes/NodeExp.h"
#include "Nodes/NodeOpExp.h"
#include "Nodes/NodeExp2.h"
#include "Nodes/NodeOp.h"
#include "Nodes/NodeEpsilon.h"
#include "ParseTree.h"

class Parser {
public:
	Parser(char* filename);
	virtual ~Parser();
	ParseTree* parse();

private:
	Token* currentToken;
	Scanner* scanner;
	ParseTree* tree;
	void nextToken();
	bool checkToken(Token::TType token);
	NodeProg* prog();
	NodeDecls* decls();
	NodeDecl* decl();
	NodeArray* array();
	NodeStatements* statements();
	NodeStatement* statement();
	NodeIndex* index();
	NodeExp* exp();
	NodeExp2* exp2();
	NodeOpExp* opExp();
	NodeOp* op();
};


#endif /* PARSER_H_ */

/*
 * ParseTreeVisitor.h
 *
 *  Created on: 14.01.2017
 *      Author: yannick
 */

#ifndef PARSER_INCLUDES_PARSETREEVISITOR_H_
#define PARSER_INCLUDES_PARSETREEVISITOR_H_
/*
#include "Nodes/Node.h"
#include "Nodes/NodeProg.h"
#include "Nodes/NodeDecls.h"
#include "Nodes/NodeDecl.h"
#include "Nodes/NodeArray.h"
#include "Nodes/NodeStatements.h"
#include "Nodes/NodeIdentifier.h"
#include "Nodes/NodeStatement.h"
#include "Nodes/NodeStatementAssign.h"
#include "Nodes/NodeStatementBlock.h"
#include "Nodes/NodeStatementIf.h"
#include "Nodes/NodeStatementRead.h"
#include "Nodes/NodeStatementWhile.h"
#include "Nodes/NodeStatementWrite.h"
#include "Nodes/NodeIndex.h"
#include "Nodes/NodeExp.h"
#include "Nodes/NodeOpExp.h"
#include "Nodes/NodeExp2.h"
#include "Nodes/NodeExp2Bracket.h"
#include "Nodes/NodeExp2Exclamation.h"
#include "Nodes/NodeExp2Identifier.h"
#include "Nodes/NodeExp2Integer.h"
#include "Nodes/NodeExp2Minus.h"
#include "Nodes/NodeInteger.h"
#include "Nodes/NodeOp.h"
#include "Nodes/NodeEpsilon.h"*/

class Node;
class NodeProg;
class NodeArray;
class NodeDecl;
class NodeDecls;
class NodeEpsilon;
class NodeExp;
class NodeExp2;
class NodeExp2Bracket;
class NodeExp2Exclamation;
class NodeExp2Identifier;
class NodeExp2Integer;
class NodeExp2Minus;
class NodeIdentifier;
class NodeIndex;
class NodeInteger;
class NodeOp;
class NodeOpExp;
class NodeStatement;
class NodeStatementAssign;
class NodeStatementBlock;
class NodeStatementIf;
class NodeStatementRead;
class NodeStatementWhile;
class NodeStatementWrite;
class NodeStatements;


class NodeOpExp;

class ParseTreeVisitor {
public:
	virtual ~ParseTreeVisitor();
	virtual void visitNode(Node* node) = 0;
	virtual void visitNode(NodeProg* node) = 0;
	virtual void visitNode(NodeArray* node) = 0;
	virtual void visitNode(NodeDecl* node) = 0;
	virtual void visitNode(NodeDecls* node) = 0;
	virtual void visitNode(NodeEpsilon* node) = 0;
	virtual void visitNode(NodeExp* node) = 0;
	virtual void visitNode(NodeExp2* node) = 0;
	virtual void visitNode(NodeExp2Bracket* node) = 0;
	virtual void visitNode(NodeExp2Exclamation* node) = 0;
	virtual void visitNode(NodeExp2Identifier* node) = 0;
	virtual void visitNode(NodeExp2Integer* node) = 0;
	virtual void visitNode(NodeExp2Minus* node) = 0;
	virtual void visitNode(NodeIdentifier* node) = 0;
	virtual void visitNode(NodeIndex* node) = 0;
	virtual void visitNode(NodeInteger* node) = 0;
	virtual void visitNode(NodeOp* node) = 0;
	virtual void visitNode(NodeOpExp* node) = 0;
	virtual void visitNode(NodeStatement* node) = 0;
	virtual void visitNode(NodeStatementAssign* node) = 0;
	virtual void visitNode(NodeStatementBlock* node) = 0;
	virtual void visitNode(NodeStatementIf* node) = 0;
	virtual void visitNode(NodeStatementRead* node) = 0;
	virtual void visitNode(NodeStatementWhile* node) = 0;
	virtual void visitNode(NodeStatementWrite* node) = 0;
	virtual void visitNode(NodeStatements* node) = 0;
};


#endif /* PARSER_INCLUDES_PARSETREEVISITOR_H_ */

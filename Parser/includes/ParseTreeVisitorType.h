/*
 * ParseTreeVisitorType.h
 *
 *  Created on: 14.01.2017
 *      Author: yannick
 */

#ifndef PARSER_INCLUDES_PARSETREEVISITORTYPE_H_
#define PARSER_INCLUDES_PARSETREEVISITORTYPE_H_


class ParseTreeVisitorType: public ParseTreeVisitor {
public:
	virtual ~ParseTreeVisitorType();

	void typeCheck(ParseTree* tree);
	void visitNode(NodeProg* node);
	void visitNode(NodeArray* node);
	void visitNode(NodeDecl* node);
	void visitNode(NodeDecls* node);
	void visitNode(NodeEpsilon* node);
	void visitNode(NodeExp* node);
	void visitNode(NodeExp2* node);
	void visitNode(NodeExp2Bracket* node);
	void visitNode(NodeExp2Exclamation* node);
	void visitNode(NodeExp2Identifier* node);
	void visitNode(NodeExp2Integer* node);
	void visitNode(NodeExp2Minus* node);
	void visitNode(NodeIdentifier* node);
	void visitNode(NodeIndex* node);
	void visitNode(NodeInteger* node);
	void visitNode(NodeOp* node);
	void visitNode(NodeOpExp* node);
	void visitNode(NodeStatement* node);
	void visitNode(NodeStatementAssign* node);
	void visitNode(NodeStatementBlock* node);
	void visitNode(NodeStatementIf* node);
	void visitNode(NodeStatementRead* node);
	void visitNode(NodeStatementWhile* node);
	void visitNode(NodeStatementWrite* node);
	void visitNode(NodeStatements* node);
};


#endif /* PARSER_INCLUDES_PARSETREEVISITORTYPE_H_ */

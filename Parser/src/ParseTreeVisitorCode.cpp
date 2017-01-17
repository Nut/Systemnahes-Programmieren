/*
 * ParseTreeVisitorCode.cpp
 *
 *  Created on: 15.01.2017
 *      Author: yannick
 */

#include "../includes/ParseTreeVisitorCode.h"
#include "../includes/Node.h"
#include <iostream>

using namespace std;

void ParseTreeVisitorCode::makeCode(ParseTree* tree) {
	tree->getProg()->accept(this);
}

/**
 * PROG ::= DECLS STATEMENTS
 */
void ParseTreeVisitorCode::visitNode(NodeProg* node) {
	node->getDecls()->accept(this);
	node->getStatements()->accept(this);
}

/**
 * DECLS ::= DECL ; DECLS
 */
void ParseTreeVisitorCode::visitNode(NodeDecls* node) {
	node->getDecl()->accept(this);
	node->getDecls()->accept(this);
}

void ParseTreeVisitorCode::visitNode(NodeEpsilon* node) {

}

/**
 * DECL ::= int ARRAY identifier
 */
void ParseTreeVisitorCode::visitNode(NodeDecl* node) {

}

/**
 * ARRAY ::= [integer]
 */
void ParseTreeVisitorCode::visitNode(NodeArray* node) {

}

/**
 * STATEMENTS ::= STATEMENT ; STATEMENTS
 */
void ParseTreeVisitorCode::visitNode(NodeStatements* node) {
	node->getStatement()->accept(this);
	node->getStatements()->accept(this);
}

/**
 * STATEMENT ::= identifier INDEX := EXP
 */
void ParseTreeVisitorCode::visitNode(NodeStatementAssign* node) {

}

/**
 * STATEMENT ::= write(EXP)
 */
void ParseTreeVisitorCode::visitNode(NodeStatementWrite* node) {

}

/**
 * STATEMENT ::= read(identifier INDEX)
 */
void ParseTreeVisitorCode::visitNode(NodeStatementRead* node) {

}

/**
 * STATEMENT ::= {STATEMENTS}
 */
void ParseTreeVisitorCode::visitNode(NodeStatementBlock* node) {

}

/**
 * STATEMENT ::= if (EXP) STATEMENT else STATEMENT
 */
void ParseTreeVisitorCode::visitNode(NodeStatementIf* node) {

}

/**
 * STATEMENT ::= while (EXP) STATEMENT
 */
void ParseTreeVisitorCode::visitNode(NodeStatementWhile* node) {

}

/**
 * INDEX ::= [EXP]
 */
void ParseTreeVisitorCode::visitNode(NodeIndex* node) {

}

/**
 * EXP ::= EXP2 OP_EXP
 */
void ParseTreeVisitorCode::visitNode(NodeExp* node) {

}

/**
 * EXP2 ::= (EXP)
 */
void ParseTreeVisitorCode::visitNode(NodeExp2Bracket* node) {

}

/**
 * EXP2 ::= identifier INDEX
 */
void ParseTreeVisitorCode::visitNode(NodeExp2Identifier* node) {

}

/**
 * EXP2 ::= integer
 */
void ParseTreeVisitorCode::visitNode(NodeExp2Integer* node) {

}

/**
 * EXP2 ::= -EXP2
 */
void ParseTreeVisitorCode::visitNode(NodeExp2Minus* node) {

}

/**
 * EXP2 ::= !EXP2
 */
void ParseTreeVisitorCode::visitNode(NodeExp2Exclamation* node) {

}

/**
 * OP_EXP ::= OP EXP
 */
void ParseTreeVisitorCode::visitNode(NodeOpExp* node) {

}

/**
 * OP ::= + | - | * | : | < | > | = | =:= | &&
 */
void ParseTreeVisitorCode::visitNode(NodeOp* node) {
	switch (node->getToken()->getType()) {
		case Token::Plus:

			break;
		case Token::Minus:

			break;
		case Token::Star:

			break;
		case Token::Colon:

			break;
		case Token::LessThan:

			break;
		case Token::GreaterThan:

			break;
		case Token::Equal:

			break;
		case Token::ColonBetweenEqual:

			break;
		case Token::And:

			break;
	}
}

void ParseTreeVisitorCode::visitNode(NodeExp2* node) {
}

void ParseTreeVisitorCode::visitNode(NodeIdentifier* node) {
}

void ParseTreeVisitorCode::visitNode(NodeInteger* node) {
}

void ParseTreeVisitorCode::visitNode(NodeStatement* node) {
}

void ParseTreeVisitorCode::visitNode(Node* node) {
}

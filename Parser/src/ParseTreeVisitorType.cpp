/*
 * ParseTreeVisitorType.cpp
 *
 *  Created on: 15.01.2017
 *      Author: yannick
 */

#include "../includes/ParseTreeVisitorType.h"
#include "../includes/Node.h"
#include <iostream>

using namespace std;

/*ParseTreeVisitorType::ParseTreeVisitorType() {}

ParseTreeVisitorType::~ParseTreeVisitorType() {}*/

void ParseTreeVisitorType::typeCheck(ParseTree* tree) {
	tree->getProg()->accept(this);
}

/**
 * PROG ::= DECLS STATEMENTS
 */
void ParseTreeVisitorType::visitNode(NodeProg* node) {
	node->getDecls()->accept(this);
	node->getStatements()->accept(this);
	node->setType(Node::noType);
}

/**
 * DECLS ::= DECL ; DECLS
 */
void ParseTreeVisitorType::visitNode(NodeDecls* node) {
	node->getDecl()->accept(this);
	node->getDecls()->accept(this);
	node->setType(Node::noType);
}

void ParseTreeVisitorType::visitNode(NodeEpsilon* node) {
	node->setEpsilonType(Node::noType);
}

/**
 * DECL ::= int ARRAY identifier
 */
void ParseTreeVisitorType::visitNode(NodeDecl* node) {
	node->getArray()->accept(this);
	if (node->getIdentifier()->getType() != Node::noType) {
		cerr << "Identifier already defined" << endl;
		node->setType(Node::errorType);
	} else if (node->getArray()->getType() == Node::errorType) {
		node->setType(Node::errorType);
	} else {
		node->setType(Node::noType);
		if (node->getArray()->getType() == Node::arrayType) {
			//store
			node->getIdentifier()->setType(Node::intArrayType);
		} else {
			//store
			node->getIdentifier()->setType(Node::intType);
		}
	}
}

/**
 * ARRAY ::= [integer]
 */
void ParseTreeVisitorType::visitNode(NodeArray* node) {
	if (node->getInteger()->getValue() > 0) {
		node->setType(Node::arrayType);
	} else {
		cerr << "no valid dimension" << endl;
		node->setType(Node::errorType);
	}
}

/**
 * STATEMENTS ::= STATEMENT ; STATEMENTS
 */
void ParseTreeVisitorType::visitNode(NodeStatements* node) {
	node->getStatement()->accept(this);
	node->getStatements()->accept(this);
	node->setType(Node::noType);
}

/**
 * STATEMENT ::= identifier INDEX := EXP
 */
void ParseTreeVisitorType::visitNode(NodeStatementAssign* node) {
	node->getExp()->accept(this);
	node->getIndex()->accept(this);
	if (node->getIdentifier()->getType() == Node::noType) {
		cerr << "identifier not defined" << endl;
		node->setType(Node::errorType);
	} else if (node->getExp()->getType() == Node::intType && (
			(node->getIdentifier()->getType() == Node::intType && node->getIndex()->getType() == Node::noType) ||
			(node->getIdentifier()->getType() == Node::intArrayType && node->getIndex()->getType() == Node::arrayType))) {
		node->setType(Node::noType);
	} else {
		cerr << "incompatible types" << endl;
		node->setType(Node::errorType);
	}
}

/**
 * STATEMENT ::= write(EXP)
 */
void ParseTreeVisitorType::visitNode(NodeStatementWrite* node) {
	node->getExp()->accept(this);
	node->setType(Node::noType);
}

/**
 * STATEMENT ::= read(identifier INDEX)
 */
void ParseTreeVisitorType::visitNode(NodeStatementRead* node) {
	node->getIndex()->accept(this);
	if (node->getIdentifier()->getType() == Node::noType) {
		cerr << "identifier not defined" << endl;
		node->setType(Node::errorType);
	} else if (((node->getIdentifier()->getType() == Node::intType) && node->getIndex()->getType() == Node::noType) ||
			((node->getIdentifier()->getType() == Node::intArrayType) && node->getIndex()->getType() == Node::arrayType)) {
		node->setType(Node::noType);
	} else {
		cerr << "incompatible types" << endl;
		node->setType(Node::errorType);
	}
}

/**
 * STATEMENT ::= {STATEMENTS}
 */
void ParseTreeVisitorType::visitNode(NodeStatementBlock* node) {
	node->getStatements()->accept(this);
	node->setType(Node::noType);
}

/**
 * STATEMENT ::= if (EXP) STATEMENT else STATEMENT
 */
void ParseTreeVisitorType::visitNode(NodeStatementIf* node) {
	node->getExp()->accept(this);
	node->getStatementIf()->accept(this);
	node->getStatementElse()->accept(this);
	if (node->getExp()->getType() == Node::errorType) {
		node->setType(Node::errorType);
	} else {
		node->setType(Node::noType);
	}
}

/**
 * STATEMENT ::= while (EXP) STATEMENT
 */
void ParseTreeVisitorType::visitNode(NodeStatementWhile* node) {
	node->getExp()->accept(this);
	node->getStatement()->accept(this);
	if (node->getExp()->getType() == Node::errorType) {
		node->setType(Node::errorType);
	} else {
		node->setType(Node::noType);
	}
}

/**
 * INDEX ::= [EXP]
 */
void ParseTreeVisitorType::visitNode(NodeIndex* node) {
	node->getExp()->accept(this);
	if (node->getExp()->getType() == Node::errorType) {
		node->setType(Node::errorType);
	} else {
		node->setType(Node::arrayType);
	}
}

/**
 * EXP ::= EXP2 OP_EXP
 */
void ParseTreeVisitorType::visitNode(NodeExp* node) {
	node->getExp2()->accept(this);
	node->getOpExp()->accept(this);
	if (node->getOpExp()->getType() == Node::noType) {
		node->setType(node->getExp2()->getType());
	} else if (node->getExp2()->getType() != node->getOpExp()->getType()) {
		node->setType(Node::errorType);
	} else {
		node->setType(node->getExp2()->getType());
	}
}

/**
 * EXP2 ::= (EXP)
 */
void ParseTreeVisitorType::visitNode(NodeExp2Bracket* node) {
	node->getExp()->accept(this);
	node->setType(node->getExp()->getType());
}

/**
 * EXP2 ::= identifier INDEX
 */
void ParseTreeVisitorType::visitNode(NodeExp2Identifier* node) {
	node->getIndex()->accept(this);
	if (node->getIdentifier()->getType() == Node::noType) {
		cerr << "identifier not defined" << endl;
		node->setType(Node::errorType);
	} else if (node->getIdentifier()->getType() == Node::intType && node->getIndex()->getType() == Node::noType) {
		node->setType(node->getIdentifier()->getType());
	} else if (node->getIdentifier()->getType() == Node::intArrayType && node->getIndex()->getType() == Node::arrayType) {
		node->setType(Node::intType);
	} else {
		cerr << "no primitv Type" << endl;
		node->setType(Node::errorType);
	}
}

/**
 * EXP2 ::= integer
 */
void ParseTreeVisitorType::visitNode(NodeExp2Integer* node) {
	node->setType(Node::intType);
}

/**
 * EXP2 ::= -EXP2
 */
void ParseTreeVisitorType::visitNode(NodeExp2Minus* node) {
	node->getExp2()->accept(this);
	node->setType(node->getExp2()->getType());
}

/**
 * EXP2 ::= !EXP2
 */
void ParseTreeVisitorType::visitNode(NodeExp2Exclamation* node) {
	node->getExp2()->accept(this);
	if (node->getExp2()->getType() != Node::intType) {
		node->setType(Node::errorType);
	} else {
		node->setType(Node::intType);
	}
}

/**
 * OP_EXP ::= OP EXP
 */
void ParseTreeVisitorType::visitNode(NodeOpExp* node) {
	node->getOp()->accept(this);
	node->getExp()->accept(this);
	node->setType(node->getExp()->getType());
}

/**
 * OP ::= + | - | * | : | < | > | = | =:= | &&
 */
void ParseTreeVisitorType::visitNode(NodeOp* node) {
	//node->setType(Node::opPlus);
}

void ParseTreeVisitorType::visitNode(NodeExp2* node) {
	//node->setType(Node::opPlus);
}

void ParseTreeVisitorType::visitNode(NodeIdentifier* node) {
	//node->setType(Node::opPlus);
}

void ParseTreeVisitorType::visitNode(NodeInteger* node) {
	//node->setType(Node::opPlus);
}

void ParseTreeVisitorType::visitNode(NodeStatement* node) {
	//node->setType(Node::opPlus);
}

void ParseTreeVisitorType::visitNode(Node* node) {
	//node->setType(Node::opPlus);
}

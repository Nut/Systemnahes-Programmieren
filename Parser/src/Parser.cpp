/*
 * Parser.cpp
 *
 *  Created on: 11.12.2016
 *      Author: Heinen Denis
 */

#include "../includes/Parser.h"
#include <iostream>
#include <stdlib.h>

/*
 * Konstruktor
 *
 * Erstellt eine Symboltabelle, den Scanner und einen neuen Parsebaum.
 * Die Symboltabelle wird dem Scanner übergeben inklusive der einzulesende Datei.
 * Die Variable currentToken wird mit dem ersten initialisiert.
 * Wenn dieser Token ein Kommentar ist, wird der nächste Token aufgerufen.
 */
Parser::Parser(char* filename) {
	Symboltable* symtab = new Symboltable;
	this->scanner = new Scanner(filename, symtab);
	this->tree = new ParseTree();
	this->currentToken = this->scanner->nextToken();
	if (currentToken->getType() == Token::Null) {
		nextToken();
	}
}

/*
 * Destruktor
 *
 * Löscht den Scanner und den Baum.
 */
Parser::~Parser() {
	delete this->scanner;
	delete this->tree;
}


/*
 * Holt den nächsten Token beim Scanner. Wenn der letzte Token ein "End of file" Token ist, beendet die Methode.
 * Wenn der neue Token ein Kommentar ist, wird die Methode automatisch nochmal aufgerufen.
 */
void Parser::nextToken() {
	if (currentToken->getType() != Token::Eof) {
		this->currentToken = this->scanner->nextToken();
		if (currentToken->getType() == Token::Null) {
			nextToken();
		}
	}
}

/*
 * Prüft den aktuellen Token mit dem übergebenen Typ.
 * Bei einer Übereinstimmung wird nextToken() aufgerufen, sonst wird error() aufgerufen.
 */
void Parser::checkTokenError(Token::TType type) {
	if (this->currentToken->getType() != type) {
		error();
	}
	nextToken();
}

/*
 * Prüft den aktuellen Token mit dem übergebenen Typ.
 * Bei einer Übereinstimmung wird nextToken() aufgerufen und true zurückgegeben,
 * sonst wird einfach nur false zurückgegeben.
 */
bool Parser::checkToken(Token::TType type) {
	if (this->currentToken->getType() == type) {
		nextToken();
		return true;
	} else {
		return false;
	}
}

/*
 * Gibt eine Fehlermeldung mit der Zeilen- & Spaltenangabe und dem Tokentyp aus.
 * Zusätzlich bricht das Programm ab.
 */
void Parser::error() {
	cerr << "unexpected Token Line: " << currentToken->getLine() << " Column: " << currentToken->getColumn() << " " << currentToken->typeToString() << endl;
	cerr << "stop" << endl;
	exit(EXIT_FAILURE);
}

/*
 *	Ruft prog() auf und gibt den Parsebaum zurück.
 */

ParseTree* Parser::parse() {
	this->tree->addProg(prog());
	return this->tree;
}

/**
 * PROG ::= DECLS STATEMENTS
 */
NodeProg* Parser::prog() {
	NodeProg* prog = new NodeProg();
	prog->addNode(decls());
	prog->addNode(statements());
	return prog;
}

/**
 * DECLS ::= DECL;DECLS | e
 */
NodeDecls* Parser::decls() {
	if (checkToken(Token::Int)) {
		NodeDecls* declarations = new NodeDecls();
		declarations->addNode(decl());
		checkTokenError(Token::Semicolon);
		declarations->addNode(decls());
		return declarations;
	} else {
		return new NodeEpsilon(NodeEpsilon::epsDecls);
	}

}

/**
 * DECL ::= int ARRAY identifier
 */
NodeDecl* Parser::decl() {
	NodeDecl* decl = new NodeDecl();
	decl->addNode(array());
	if (currentToken->getType() == Token::Identifier) {
		NodeIdentifier* identifier = new NodeIdentifier(currentToken);
		identifier->addInformation(currentToken->getSymtabEntry()->getInfo());
		decl->addNode(identifier);
		nextToken();
	} else {
		error();
	}
	return decl;
}

/**
 * ARRAY ::= [integer] | e
 */
NodeArray* Parser::array() {
	if (checkToken(Token::LeftBracket)) {
		NodeArray* array = new NodeArray();
		if (currentToken->getType() == Token::Integer) {
			array->addInteger(new NodeInteger(currentToken->getValue()));
			nextToken();
		} else {
			error();
		}
		checkTokenError(Token::RightBracket);
		return array;
	} else {
		return new NodeEpsilon(NodeEpsilon::epsArray);
	}
}

/**
 * STATEMENTS ::= STATEMENT;STATEMENTS | e
 */
NodeStatements* Parser::statements() {
	switch (currentToken->getType()) {
		case Token::Identifier:
		case Token::Write:
		case Token::Read:
		case Token::LeftCurved:
		case Token::If:
		case Token::While: {
			NodeStatements* statements_ = new NodeStatements();
			statements_->addNode(statement());
			checkTokenError(Token::Semicolon);
			statements_->addNode(statements());
			return statements_;
		}
		case Token::Int:
			error();
			break;
		default:
			return new NodeEpsilon(NodeEpsilon::epsStatements);
	}
}

/*
 *	STATEMENT ::= identifier INDEX := EXP | write(EXP) | read(identifier INDEX) |
 *				  {STATEMENTS} | if (EXP) STATEMENT else STATEMENT | while (EXP) STATEMENT
 *
 */
NodeStatement* Parser::statement() {
	switch (currentToken->getType()) {
		case Token::Identifier: {
			NodeStatementAssign* statement = new NodeStatementAssign();
			NodeIdentifier* identifier = new NodeIdentifier(currentToken);
			identifier->addInformation(currentToken->getSymtabEntry()->getInfo());
			statement->addNode(identifier);
			nextToken();
			statement->addNode(index());
			checkTokenError(Token::Assign);
			statement->addNode(exp());
			return statement;
		}
		case Token::Write: {
			NodeStatementWrite* statement = new NodeStatementWrite();
			nextToken();
			checkTokenError(Token::LeftParent);
			statement->addNode(exp());
			checkTokenError(Token::RightParent);
			return statement;
		}
		case Token::Read: {
			NodeStatementRead* statement = new NodeStatementRead();
			nextToken();
			checkTokenError(Token::LeftParent);
			if (currentToken->getType() == Token::Identifier) {
				NodeIdentifier* identifier = new NodeIdentifier(currentToken);
				identifier->addInformation(currentToken->getSymtabEntry()->getInfo());
				statement->addNode(identifier);
				nextToken();
			} else {
				error();
			}
			statement->addNode(index());
			checkTokenError(Token::RightParent);
			return statement;
		}
		case Token::LeftCurved: {
			NodeStatementBlock* statement = new NodeStatementBlock();
			nextToken();
			statement->addNode(statements());
			checkTokenError(Token::RightCurved);
			return statement;
		}
		case Token::If: {
			NodeStatementIf* statement_ = new NodeStatementIf();
			nextToken();
			checkTokenError(Token::LeftParent);
			statement_->addNode(exp());
			checkTokenError(Token::RightParent);
			statement_->addNodeIf(statement());
			checkTokenError(Token::Else);
			statement_->addNodeElse(statement());
			return statement_;
		}
		case Token::While: {
			NodeStatementWhile* statement_ = new NodeStatementWhile();
			nextToken();
			checkTokenError(Token::LeftParent);
			statement_->addNode(exp());
			checkTokenError(Token::RightParent);
			statement_->addNode(statement());
			return statement_;
		}
		default:
			error();
			return new NodeStatement();
	}
}

/*
 * INDEX ::= [EXP]
 */
NodeIndex* Parser::index() {
	if (checkToken(Token::LeftBracket)) {
		NodeIndex* index = new NodeIndex();
		index->addNode(exp());
		checkTokenError(Token::RightBracket);
		return index;
	} else {
		return new NodeEpsilon(NodeEpsilon::epsIndex);
	}

}

/**
 * EXP ::= EXP2 OP_EXP
 */
NodeExp* Parser::exp() {
	NodeExp* exp = new NodeExp();
	exp->addNode(exp2());
	exp->addNode(opExp());
	return exp;
}

/**
 * EXP2 ::= (EXP) | identifier INDEX | integer | -EXP2 | !EXP2
 */
NodeExp2* Parser::exp2() {
	switch (currentToken->getType()) {
		case Token::LeftParent: {
			nextToken();
			NodeExp2Bracket* exp2 = new NodeExp2Bracket();
			exp2->addNode(exp());
			checkTokenError(Token::RightParent);
			return exp2;
		}
		case Token::Identifier: {
			NodeExp2Identifier* exp2 = new NodeExp2Identifier();
			NodeIdentifier* identifier = new NodeIdentifier(currentToken);
			identifier->addInformation(currentToken->getSymtabEntry()->getInfo());
			exp2->addNode(identifier);
			nextToken();
			exp2->addNode(index());
			return exp2;
		}
		case Token::Integer: {
			NodeInteger* integer = new NodeInteger(currentToken->getValue());
			NodeExp2Integer* exp2 = new NodeExp2Integer();
			exp2->addNode(integer);
			nextToken();
			return exp2;
		}
		case Token::Minus: {
			NodeExp2Minus* exp2_ = new NodeExp2Minus();
			nextToken();
			exp2_->addNode(exp2());
			return exp2_;
		}
		case Token::Exclamation: {
			NodeExp2Exclamation* exp2_ = new NodeExp2Exclamation();
			nextToken();
			exp2_->addNode(exp2());
			return exp2_;
		}
		default:
			error();
			return new NodeExp2();
	}
}

/**
 * OP_EXP ::= OP EXP
 */
NodeOpExp* Parser::opExp() {
	switch (currentToken->getType()) {
		case Token::Plus:
		case Token::Minus:
		case Token::Star:
		case Token::Colon:
		case Token::LessThan:
		case Token::GreaterThan:
		case Token::Equal:
		case Token::ColonBetweenEqual:
		case Token::And: {
			NodeOpExp* opExp = new NodeOpExp();
			opExp->addNode(op());
			opExp->addNode(exp());
			return opExp;
		}
		default:
			return new NodeEpsilon(NodeEpsilon::epsOpExp);
	}
}

/**
 * OP ::= + | - | * | : | < | > | = | =:= | &&
 */
NodeOp* Parser::op() {
	NodeOp* op = new NodeOp(currentToken);
	nextToken();
	return op;
}

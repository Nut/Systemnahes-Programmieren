#include "../includes/Scanner.h"
#include <iostream>
#include <cstring>
#include <iomanip>

int main(int argc, char **argv) {

	Symboltable* symtab = new Symboltable;
	Scanner* scanner = new Scanner("Buffer/includes/test.txt", symtab);
	Token* t;
	while (t = scanner->nextToken()) {
		switch(t->getType()) {
			case Token::Identifier:
				cout << std::setw(14) << "Token " << std::setw(12) << t->typeToString() << " Line: " << t->getLine() << " Column: " << t->getColumn() << std::setw(10) << " Lexem: " << symtab->lookup(t->getInfoKey())->getInfo()->getName() << endl;
				break;
			case Token::Integer:
				cout << std::setw(14) << "Token " << std::setw(12) << t->typeToString() << " Line: " << t->getLine() << " Column: " << t->getColumn() << std::setw(10) << " Value: " << t->getValue()<< endl;
				break;
			case Token::And:
			case Token::Assign:
			case Token::Plus:
			case Token::Minus:
			case Token::Colon:
			case Token::Star:
			case Token::LessThan:
			case Token::GreaterThan:
			case Token::Equal:
			case Token::ColonBetweenEqual:
			case Token::Exclamation:
			case Token::Semicolon:
			case Token::LeftParent:
			case Token::RightParent:
			case Token::LeftCurved:
			case Token::RightCurved:
			case Token::LeftBracket:
			case Token::RightBracket:
				cout << std::setw(14) << "Token " << std::setw(12) << t->typeToString() << " Line: " << t->getLine() << " Column: " << t->getColumn() << endl;
				break;
			case Token::Unknown:
				cout << std::setw(14) << "Unknown Token " << " 		   Line: " << t->getLine() << " Column: " << t->getColumn() << std::setw(22) << "Symbol: " << t->getSymbol() << endl;
				break;
			case Token::Null:
				break;
		}
	}
}


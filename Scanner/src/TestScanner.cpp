#include "../includes/Scanner.h"
#include <iostream>
#include <cstring>

int main(int argc, char **argv) {

	Symboltable* symtab = new Symboltable;
	Scanner* scanner = new Scanner("Buffer/includes/test.txt", symtab);
	Token* t;
	while (t = scanner->nextToken()) {
		switch(t->getType()) {
			case Token::Identifier:
				cout << "Token " << t->typeToString() << " Lexem: " << symtab->lookup(t->getInfoKey())->getInfo()->getName() << endl;
				break;
			case Token::Integer:
				cout << "Token " << t->typeToString() << " " << endl;
				break;
			case Token::Unknown:
				cout << "Unknown Token Symbol: " << t->getSymbol() << endl;
				break;
		}
	}
}


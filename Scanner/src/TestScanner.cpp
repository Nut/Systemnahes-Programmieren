#include "../includes/Scanner.h"
#include <iostream>
#include <cstring>

int main(int argc, char **argv) {

	Symboltable* symtab = new Symboltable;
	Scanner* scanner = new Scanner("Buffer/includes/test.txt", symtab);
	Token* t;
	while (t = scanner->nextToken()) {
		if (t->getInfoKey() != NULL) {
			cout << "Token " << t->typeToString() << " " <<  symtab->lookup(t->getInfoKey())->getInfo()->getName() << endl;
		} else {
			cout << "Token " << t->typeToString() << endl;
		}
	}
}


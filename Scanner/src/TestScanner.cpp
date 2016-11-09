#include "../includes/Scanner.h"
#include <iostream>
#include <cstring>

int main(int argc, char **argv) {

	Symboltable* symtab = new Symboltable;
	Scanner* scanner = new Scanner("Buffer/includes/test.txt", symtab);
	Token* t = scanner->nextToken();
	cout << t->typeToString() << endl;
	cout << "test: " << t->getType() << endl;
	//while (t != NULL) {
	//	cout << "Token" << t->getType() <<  symtab->lookup(t->getInfoKey())->getInfo()->getName() << endl;
	//}
}


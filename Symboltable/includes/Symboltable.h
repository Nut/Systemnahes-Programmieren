#ifndef SYMBOLTABLE_H_
#define SYMBOLTABLE_H_

#include "../includes/SymtabEntry.h"
#include "StringTable.h"

class Symboltable {
public:
	Symboltable();
	virtual ~Symboltable();
	unsigned int insert(char* lexem);
	SymtabEntry* lookup(unsigned int key);

private:
	static const unsigned TABLE_SIZE = 1024;
	StringTable* stringTable;
	SymtabEntry** table;
	unsigned int hash(const char* s, unsigned int seed = 0);
	bool strCmp(char* s1, char* s2);
};

#endif /* SYMBOLTABLE_H_ */

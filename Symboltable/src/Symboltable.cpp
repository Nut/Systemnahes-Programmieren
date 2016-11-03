#include "../includes/Symboltable.h"
#include <cstring>

Symboltable::Symboltable() {
	stringTable = new StringTable();
	table = new SymtabEntry*[TABLE_SIZE];
	for (unsigned int i = 0; i < TABLE_SIZE; i++) {
		table[i] = NULL;
	}
}

Symboltable::~Symboltable() {
	delete stringTable;
	for (unsigned int i = 0; i < TABLE_SIZE; i++) {
		if (table[i] != NULL) {
			SymtabEntry *prevEntry = NULL;
			SymtabEntry *entry = table[i];
			while (entry != NULL) {
				prevEntry = entry;
				entry = entry->getNext();
				delete prevEntry;
			}
		}
	}
	delete[] table;
}

unsigned int Symboltable::insert(char* lexem) {
	unsigned int hashValue = hash(lexem);
	SymtabEntry* tmpSymtabEntry = lookup(hashValue);

	if (tmpSymtabEntry == NULL) { //noch keinen Eintrag in der HashTable gefunden
		char* p = stringTable->insert(lexem, strlen(lexem));
		table[hashValue % TABLE_SIZE] = new SymtabEntry(new Information(p));
	} else {
		while (tmpSymtabEntry->getNext() != NULL) {
			if (tmpSymtabEntry->getInfo()->compareLex(lexem)) {
				return hashValue;
			}
			tmpSymtabEntry = tmpSymtabEntry->getNext();
		}

		char* p = stringTable->insert(lexem, strlen(lexem));
		SymtabEntry* newEntry = new SymtabEntry(new Information(p));
		tmpSymtabEntry->setNext(newEntry);
	}

	return hashValue;
}

SymtabEntry* Symboltable::lookup(unsigned int key) {
	return table[key % TABLE_SIZE];
}

unsigned int Symboltable::hash(const char* s, unsigned int seed) {
	unsigned int hash = seed;
	while (*s) {
		hash = hash * 101 + *s++;
	}
	return hash;
}

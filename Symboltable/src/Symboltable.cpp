/*
 * Symboltable.cpp
 *
 *  Created on: Sep 26, 2012
 *      Author: knad0001
 */

#include "../includes/Symboltable.h"

Symboltable::Symboltable() {

}

Symboltable::~Symboltable() {
	// TODO Auto-generated destructor stub
}

unsigned int Symboltable::insert(char* lexem) {
	unsigned int hashValue = hash(lexem);
	SymtabEntry* existantSymtabEntry = lookup(hashValue);
	if (!existantSymtabEntry || !strCmp(existantSymtabEntry->getName(), lexem)) {
		table[hashValue % TABLE_SIZE] = new SymtabEntry(lexem);
	}
	return hashValue;
}

SymtabEntry* Symboltable::lookup(int key) {
	return table[key % TABLE_SIZE];
}

unsigned int Symboltable::hash(const char* s, unsigned int seed) {
	unsigned int hash = seed;
	while (*s) {
		hash = hash * 101  +  *s++;
	}
	return hash;
}

bool strCmp(char* s1, char* s2) {
    bool x = true;
    while(*s1 != '\0' && *s2 != '\0') {
        if (*s1 != *s2) {
            return false;
        }
        s1++;
        s2++;
    }
    if (*s1 != *s2) {
        x = false;
    }
    return x;
}

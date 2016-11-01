/*
 * SymtabEntry.cpp
 *
 *  Created on: 01.11.2016
 *      Author: Denis
 */
#include "../includes/SymtabEntry.h"

SymtabEntry::SymtabEntry(char* lexem) {
	name = lexem;
}

SymtabEntry::~SymtabEntry() {
	// TODO Auto-generated destructor stub
}

char* SymtabEntry::getName() {
	return name;
}



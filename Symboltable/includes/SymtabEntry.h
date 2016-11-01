/*
 * SymtabEntry.h
 *
 *  Created on: 01.11.2016
 *      Author: Denis
 */

#ifndef SYMBOLTABLE_INCLUDES_SYMTABENTRY_H_
#define SYMBOLTABLE_INCLUDES_SYMTABENTRY_H_


class SymtabEntry {
public:
	SymtabEntry(char* lexem);
	virtual ~SymtabEntry();
	char* getName();

private:
	char* name;

};



#endif /* SYMBOLTABLE_INCLUDES_SYMTABENTRY_H_ */

#include "../includes/Information.h"

Information::Information(char* lexem) {
	this->name = lexem;
}

Information::~Information() {
}

char* Information::getName() {
	return this->name;
}

bool Information::compareLex(char* lexem) {
	bool x = true;
	while (*name != '\0' && *lexem != '\0') {
		if (*name != *lexem) {
			return false;
		}
		name++;
		lexem++;
	}
	if (*name != *lexem) {
		x = false;
	}
	return x;
}

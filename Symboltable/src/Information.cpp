#include "../includes/Information.h"
#include <string.h>

Information::Information(char* lexem) {
	this->name = lexem;
}

Information::~Information() {
}

char* Information::getName() {
	return this->name;
}

bool Information::compareLex(char* lexem) {
	int x = myStrCmp(lexem, name);
	if (x == 0) {
		return true;
	}

	return false;
}

int Information::myStrCmp(const char *s1, const char *s2) {
    const unsigned char *p1 = (const unsigned char *)s1;
    const unsigned char *p2 = (const unsigned char *)s2;

    while (*p1 != '\0') {
        if (*p2 == '\0') return  1;
        if (*p2 > *p1)   return -1;
        if (*p1 > *p2)   return  1;

        p1++;
        p2++;
    }

    if (*p2 != '\0') return -1;

    return 0;
}

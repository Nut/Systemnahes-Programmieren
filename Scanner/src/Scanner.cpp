/*
 * Scanner.cpp
 *
 *  Created on: Sep 26, 2012
 *      Author: knad0001
 */

#include "../includes/Scanner.h"
#include "../../Automat/includes/Automat.h"
#include "../../Buffer/includes/Buffer.h"

Scanner::Scanner(char* filename) {
	Automat* automat = new Automat();
	Buffer* buffer = new Buffer(filename);
}

Scanner::~Scanner() {
	// TODO Auto-generated destructor stub
}

Token Scanner::nextToken() {
	while()
}

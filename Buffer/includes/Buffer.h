/*
 * Buffer.h
 *
 *  Created on: Sep 26, 2012
 *      Author: knad0001
 */

#include <fstream>
#include <iostream>

using namespace std;

#ifndef BUFFER_H_
#define BUFFER_H_

class Buffer {
	public:
		Buffer(const char* filename);
		virtual ~Buffer();
		char getChar();
		void ungetChar(unsigned int steps);

	private:
		static const unsigned BUFFER_SIZE = 5;
		const char* fileName;
		ifstream file;
		char* current_buffer;
		char* previous_buffer;
		unsigned int index;
		bool isEndOfFile;
		void readFile();
};

#endif /* BUFFER_H_ */

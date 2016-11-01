/*
 * Buffer.cpp
 *
 *  Created on: Sep 26, 2012
 *      Author: knad0001
 */

#include "../includes/Buffer.h"

Buffer::Buffer(const char* fileName) {
	this->fileName = fileName;
	this->current_buffer = new char[BUFFER_SIZE];
	this->previous_buffer = new char[BUFFER_SIZE];

	file.open(this->fileName);

	this->index = 0;
	this->isEndOfFile = false;

	readFile();
}

Buffer::~Buffer() {
	delete[] current_buffer;
	delete[] previous_buffer;
	this->file.close();
}

void Buffer::readFile() {
	fill_n(current_buffer, BUFFER_SIZE, '\0');
	file.read(current_buffer, BUFFER_SIZE - 1);

	if (file.eof()) {
		this->isEndOfFile = true;
	}
}

char Buffer::getChar() {
	if (this->current_buffer[index] == '\0') {
		if (isEndOfFile) {
			return '\0';
		}
		char* temp = previous_buffer;
		previous_buffer = current_buffer;
		current_buffer = temp;
		index = 0;
		readFile();
	}
	return this->current_buffer[index++];
}

void Buffer::ungetChar(unsigned int steps) {
	steps++;
	if (steps > index) {
		steps -= index;
		index = BUFFER_SIZE - 1;
		char* temp = previous_buffer;
		previous_buffer = current_buffer;
		current_buffer = temp;
		if (steps > index) {
			throw "You cannot go back so far!";
		}
	}
	index -= steps;
}

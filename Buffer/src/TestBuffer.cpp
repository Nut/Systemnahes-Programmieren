#include <iostream>
#include "../includes/Buffer.h"

using namespace std;

int main(int argc, char **argv) {

	Buffer*  buffer;

	buffer = new Buffer("Buffer/includes/test.txt");
	char test;

	while ((test = buffer->getChar()) != '\0') {
		cout << test << endl;
	}

	/*for (int i = 0; i < 10; ++i) {
		cout << i << ". " << buffer->getChar() << endl;
	}*/
}

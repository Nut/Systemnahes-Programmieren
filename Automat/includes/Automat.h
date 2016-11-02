/*
 * Automat.h
 *
 *  Created on: Jul 5, 2012
 *      Author: knad0001
 */

#ifndef Automat_H_
#define Automat_H_

class Automat {
public:
	Automat(Buffer buffer);
	virtual ~Automat();
	void read(char* c);
private:
	Buffer buffer;
};

#endif /* Automat_H_ */

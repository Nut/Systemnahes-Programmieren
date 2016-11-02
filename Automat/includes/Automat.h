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
	Automat();
	virtual ~Automat();
	void read(char c);
	void setBack(int steps);
	int getBack();
private:
	enum State {
		Start,
		Null,
		Identifier,
		Integer,
		Error,
		Colon,
		Assign,
		Equal,
		And,
		DoubleAnd,
		ColonBetweenEqual,
		ColonBetweenEqualFinal,
		CommentStart,
		CommentClose,
		CommentFinal,
		Sign
	};
	State currentState;
	State lastFinalState;
	int back;
};

#endif /* Automat_H_ */

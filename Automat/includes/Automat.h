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
	enum State {
			Start,
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
			Sign,
			Eof,
			Null
		};
	Automat();
	virtual ~Automat();
	void read(char c);
	State getCurrentState();
	State getLastFinalState();
	void setLastFinalState(Automat::State state);
	void setBack(int steps);
	int getBack();
	bool isStop();
	void reset();
private:
	State currentState;
	State lastFinalState;
	int back;
	bool stop;
};

#endif /* Automat_H_ */

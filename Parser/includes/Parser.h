#ifndef PARSER_H_
#define PARSER_H_

#include "Token.h"
#include "../../Scanner/includes/Scanner.h"

class Parser {
public:
	Parser(Scanner scanner);
	virtual ~Parser();
	ParseTree parse();

private:
	Scanner scanner;
};


#endif /* PARSER_H_ */

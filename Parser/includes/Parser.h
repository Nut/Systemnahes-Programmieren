#ifndef PARSER_H_
#define PARSER_H_

#include "../../Scanner/includes/Token.h"
#include "../../Scanner/includes/Scanner.h"

class Parser {
public:
	Parser(const char* filename);
	virtual ~Parser();
	ParseTree* parse();

private:
	Scanner scanner;
	void prog();
	void decls();
};


#endif /* PARSER_H_ */

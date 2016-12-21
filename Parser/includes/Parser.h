#ifndef PARSER_H_
#define PARSER_H_

#include "../../Scanner/includes/Token.h"
#include "../../Scanner/includes/Scanner.h"
#include "ParseTree.h"

class Parser {
public:
	Parser(const char* filename);
	virtual ~Parser();
	ParseTree* parse();

private:
	Scanner scanner;
	ParseTree* tree;
	void prog();
	Node* decls();
	Node* decl();
	Node* statements();
	Node* array();
};


#endif /* PARSER_H_ */

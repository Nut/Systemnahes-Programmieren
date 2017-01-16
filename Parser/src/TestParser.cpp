/*
 * TestParser.cpp
 *
 *  Created on: 08.01.2017
 *      Author: yannick
 */

#include "../includes/Parser.h"
#include "../includes/ParseTree.h"
#include "../includes/ParseTreeVisitor.h"
#include "../includes/ParseTreeVisitorType.h"
#include <iostream>

using namespace std;

int main(int argc, char **argv) {
	cout << "parsing..." << endl;
	Parser* parser = new Parser(argv[1]);
	ParseTree* tree = parser->parse();

	cout << "type checking..." << endl;
	ParseTreeVisitorType tc;
	tc.typeCheck(tree);
}




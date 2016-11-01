#include "../includes/Symboltable.h"
#include <iostream>

using namespace std;

int main(int argc, char **argv) {

	Symboltable st;

   char* str1 = "hello";
   int key1 = st.insert(str1);
   cout << "sym1:"<< st.lookup(key1)->getName() << endl;
  return 0;


}

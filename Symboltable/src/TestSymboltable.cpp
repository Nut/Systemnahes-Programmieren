#include "../includes/Symboltable.h"
#include <iostream>

using namespace std;

int main(int argc, char **argv) {

	Symboltable st;

	cout << "Start" << endl;

   char* str1 = "hello";
   char* str2 = "hello";

   int key1 = st.insert(str1);
   cout << "sym1:"<< st.lookup(key1)->getName() << endl;
   cout << "key1: " << key1 << endl;
   int key2 = st.insert(str2);
   cout << "key2: " << key2 << endl;
   cout << "sym1:"<< st.lookup(key2)->getName() << endl;
  return 0;


}

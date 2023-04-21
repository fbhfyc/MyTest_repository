#include "base.h"
#include "test_all.h"

//  vector test
// vec_test_find();
//vec_test_popback();


int main() {
    string str{"abcdefg"};
    string::iterator it;
    //str.append(" fbh");
    //str += " & fyc";
    //str.push_back('41');
   // str.insert( 3," insert");
    //str.erase(1,1);
   // int pos = str.rfind("b");
    //string temp = str.substr(2);
    str.replace(1,4,"hhhh");
    cout << str<<endl;
  /*  for ( it=str.begin();it != str.end();++it)
    cout   << *it ;*/
    return 0; 
}

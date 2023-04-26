#include "base.h"
#include "test_all.h"
////
//  vector test
// vec_test_find();
//vec_test_popback();
 /*   string str{"abcdefg"};
    string::iterator it;*/
    //str.append(" fbh");
    //str += " & fyc";
    //str.push_back('41');
   // str.insert( 3," insert");
    //str.erase(1,1);
   // int pos = str.rfind("b");
    //string temp = str.substr(2);
    //str.replace(1,4,"hhhh");
    //cout << str<<endl;
  /*  for ( it=str.begin();it != str.end();++it)
    cout   << *it ;*/

extern CMyVector vv;

class Student {
private:
    int m_id;
    string m_name;
public:
    Student(const string& name, int id):
        m_id(id),m_name(name)
    {}
    int getId() const;
    void introduce() const;
};
int Student::getId() const {
    return m_id;
}
void Student::introduce() const {
    cout << m_id<< ":" <<m_name << endl;
}

typedef bool(*func_t)(const Student&,const Student&);
bool stuCmp(const Student& s1,const Student& s2) {
    return s1.getId() < s2.getId();
}

struct MyString {
    string m_str;
    MyString(string str):m_str(str) {
        cout << "[Construct:] " << m_str <<endl;
    }
    ~MyString() {
        cout << "[Deconstruct:] " << m_str << endl;
    }
    string getStr() {
        return m_str;
    }
};

class CA {
public:
    int fun1() {
        return m_i;
    }
    int m_i;
};

int main() {
   
    stack<int> ss;
    queue<int> q;
    priority_queue<int> pq;
    set<int> s;
    
    CA ca;
    cout << sizeof(ca) << endl;

    unique_ptr<MyString> p1 = std::make_unique<MyString>("first string");
    //unique_ptr<MyString> p2 = std::make_unique<MyString>("jkjkj");
    p1.reset(new MyString("reset new"));
    cout << p1->getStr();
    return 0; 
} 

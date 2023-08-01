#include <iostream>
#include "vector"
#include "random"
#include "sstream"
#include "typeinfo"

template<typename T1, typename T2>
class MyClass
{

public:
    MyClass(){};

    MyClass(T1 inKey, T2 inValue)
    {
        key = inKey;
        value = inValue;
    }
    T1 key;
    T2 value;
    std::vector<MyClass> myVec;

};

template<typename T>
class MyClass2
{
private:

public:
    std::vector<T> vec;
    MyClass2() = default;
//    MyClass var;
};


int main() {
    std::cout << "Task 3" << std::endl;

    MyClass<int,std::string> a;

    for (int i=0; i<10; i++)
    {
        MyClass<int,std::string> tmp;
        tmp.key = i;
        tmp.value = "lalala";
        a.myVec.push_back(tmp);
    }

    for (int i=0; i<a.myVec.size(); i++)
    {
        std::cout << a.myVec[i].key << " " << a.myVec[i].value << std::endl;
    }

    double rrr = 0;
    MyClass<int,std::string> b;

    MyClass2<MyClass<int,std::string>> p;
    p.vec.push_back(a);

    return 0;
}

/*#include <iostream>
#include "vector"
#include "random"
#include "sstream"
#include "map"
#include "variant"


template <typename T1, typename T2>
struct Register
{

};

int main() {
    std::cout << "Task 3" << std::endl;

    std::variant<int,double,std::string> var;

    return 0;
}*/


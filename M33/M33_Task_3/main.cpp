#include <iostream>
#include "vector"
#include "random"
#include "sstream"

template<typename T1, typename T2>
struct Register
{
    T1 key;
    T2 value;

public:

    Register<T1,T2> aRegister(const T1& inKey, const T2& inValue)
    {
        Register<T1,T2> reg;
        reg.key=inKey;
        reg.value=inValue;
        return reg;
    };

    std::vector<Register<T1,T2>> vec;
};


int main() {
    std::cout << "Task 3" << std::endl;

    srand(time(nullptr));

    int a;

    /*Register<int,std::string> reg;
    reg.vec.push_back(reg.aRegister(10,"10"));

    for (int i=0; i<reg.vec.size(); i++)
    {
        std::cout << reg.vec[i].key << " " << reg.vec[i].value << std::endl;
    }*/


    for (int i=0; i<10; i++)
    {
        int a=rand()%100;
        double b=rand()%50;
        std::stringstream tmp;
        std::string c;
        tmp << a << b;
        c = tmp.str();
//        std::cout << a << " " << b << " " << c << std::endl;

        if (rand()%10+1 > 5)
        {
            Register<double,std::string> reg;
            reg.vec.push_back(reg.aRegister(a,c));

            for (int i=0; i<reg.vec.size(); i++)
            {
                std::cout << reg.vec[i].key << " " << reg.vec[i].value << std::endl;
            }
        }
        else
        {
            Register<std::string, double> reg;
            reg.vec.push_back(reg.aRegister(c,b));

            for (int i=0; i<reg.vec.size(); i++)
            {
                std::cout << reg.vec[i].key << " " << reg.vec[i].value << std::endl;
            }
        }
    }




    return 0;
}

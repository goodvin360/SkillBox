#include <iostream>
#include "vector"
#include "tuple"

class Data
{

public:
    Data(std::initializer_list<int>  inVec) : vec(inVec){}
    std::vector<int> vec;
    void printData()
    {
        for (auto it:vec)
        {
            std::cout << it << std::endl;
        }
    }
};

int main() {

    std::cout << "Task 1" << std::endl;
    Data d({1,2,3,4,5});
    d.printData();

    return 0;
}

#include <iostream>
#include "fstream"


int main() {
    std::cout << "Task 1" << std::endl;

    std::ifstream data;
    data.open("..\\words.txt");

    std::string target;
    int count=0;
    std::cout << "What we want to find?" << std::endl;
    std::cin >> target;
    std::string temp;
    while (!data.eof())
    {
        data >> temp;
        if (temp==target)
            count+=1;
    }

    std::cout << "Target was find " << count << " times.";

    return 0;
}

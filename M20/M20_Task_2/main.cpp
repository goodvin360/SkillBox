#include <iostream>
#include "fstream"
#include "cstdlib"


int main() {
    std::cout << "Task 2" << std::endl;

    srand(time(nullptr));
    std::ofstream data("..\\pic.txt", std::ios::out);
    int height, wight, var;
    std::cout << "enter 'height' and 'wight' of your picture: " << std::endl;
    std::cin >> height >> wight;

    for (int i=0; i<height*wight; i++)
        {
            var=rand()%10;
            if (var>4) data << 1;
            else data << 0;
            if ((i+1+wight)%wight==0) data << '\n';
        }

    return 0;
}

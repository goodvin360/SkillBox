#include "KBD.h"
#include "iostream"


void write(ram &ar)
{
    std::cout << "Enter your data (eight integer numbers):" << std::endl;
    for (int i=0; i<8; i++)
    {
        std::cin >> ar.buf[i];
    }
}
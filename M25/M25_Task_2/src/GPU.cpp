#include "GPU.h"
#include "iostream"


void read(ram &ar)
{
    for (int i=0; i<8; i++)
    {
        std::cout << ar.buf[i] << '\t';
    }
    std::cout << std::endl;
}
#include "GPU.h"
#include "iostream"

using namespace std;

void read(ram &ar)
{
    for (int i=0; i<8; i++)
    {
        cout << ar.buf[i] << '\t';
    }
    cout << endl;
}
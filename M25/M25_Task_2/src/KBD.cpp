#include "KBD.h"
#include "iostream"

using namespace std;

void write(ram &ar)
{
    cout << "Enter your data (eight integer numbers):" << endl;
    for (int i=0; i<8; i++)
    {
        cin >> ar.buf[i];
    }
}
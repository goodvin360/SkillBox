#include "CPU.h"
#include "iostream"

using namespace std;

void compute(ram &ar)
{
    int sum=0;
    for (int i=0; i<8; i++)
    {
        sum+=ar.buf[i];
    }

    cout << "Sum is: " << sum << endl;
}
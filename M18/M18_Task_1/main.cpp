#include <iostream>
#include "vector"

using namespace std;

void swapvec(vector<int>&v, int*p)
{
    int temp;
    for (int i=0; i<4; i++)
    {
        temp=v[i];
        v[i]=*(p+i);
        *(p+i)=temp;
    }
}

int main() {
    cout << "Task 1" << endl;

    vector<int>v={1,2,3,4};
    int ar[4]={2,4,6,8};

    swapvec(v,ar);

    for(int i = 0; i < 4; ++i)
        cout << v[i];

    cout << endl;

    for(int i = 0; i < 4; ++i)
        cout << ar[i];

    return 0;
}

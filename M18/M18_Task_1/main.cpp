#include <iostream>
#include "vector"


void swapvec(std::vector<int>&v, int*p)
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
    std::cout << "Task 1" << std::endl;

    std::vector<int>v={1,2,3,4};
    int ar[4]={2,4,6,8};

    swapvec(v,ar);

    for(int i = 0; i < 4; ++i)
        std::cout << v[i];

    std::cout << std::endl;

    for(int i = 0; i < 4; ++i)
        std::cout << ar[i];

    return 0;
}

#include <iostream>
#include "sstream"
#include "cmath"


void evenCalc(long long& a, int& b)
{
   /* stringstream ss;
    string temp, temp1;
    ss << a;
    temp=ss.str();
    int i=0;
    while (temp[i]!='\0')
    {
        temp1=temp[i];
        int tmp = stod(temp1);
            if (tmp%2==0) b++;
        i++;
    }*/

    if(a==0){}
    else {
        if ((a%10)%2 == 0) b++;
        evenCalc(a /= 10, b);
    }
}

int main() {
    std::cout << "Task 3" << std::endl;

    int ans=0;

    long long n = 9223372036854775806;

    evenCalc(n, ans);

    std::cout << "ans = " << ans;

    return 0;
}

#include <iostream>

using namespace std;

int main() {
    std::cout << "The number series" << std::endl;
    int numbers[15] = {114, 111, 106, 107, 108, 105, 115, 108, 110, 109, 112, 113, 116, 117, 118};
    int min =numbers[0], sum=0, sumRepeat=0, target=0;
    for (int i=0;i<15;i++)
    {if (numbers[i]<min) min=numbers[i];
    sumRepeat+=numbers[i];}
    sum=(2*min+13)*14/2;
    if (sumRepeat-sum>0) target = sumRepeat-sum;
    else target = sum-sumRepeat-1;
    cout << min << endl;
    cout << target;

    return 0;
}

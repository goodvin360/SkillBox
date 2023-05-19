#include <iostream>

using namespace std;

int main() {
    std::cout << "Sorting" << std::endl;
    float array[15];
    cout << "Enter 15 real numbers:" << endl;
    for (int i=0;i<15; i++)
        cin >> array[i];

    float min = 0;
    for (int j=0;j<15;j++)
    {for (int i=0; i<14; i++)
        {if (array[i]<array[i+1])
            {min=array[i];
            array[i]=array[i+1];
            array[i+1]=min;}
        }}

    for (int i=0;i<15; i++)
        cout << array[i] << endl;

    return 0;
}

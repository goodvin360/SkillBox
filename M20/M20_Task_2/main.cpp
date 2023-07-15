#include <iostream>
#include "fstream"
#include "cstdlib"

using namespace std;

int main() {
    cout << "Task 2" << endl;

    srand(time(nullptr));
    ofstream data("..\\pic.txt", ios::out);
    int height, wight, var;
    cout << "enter 'height' and 'wight' of your picture: " << endl;
    cin >> height >> wight;

    for (int i=0; i<height*wight; i++)
        {
            var=rand()%10;
            if (var>4) data << 1;
            else data << 0;
            if ((i+1+wight)%wight==0) data << '\n';
        }

    return 0;
}

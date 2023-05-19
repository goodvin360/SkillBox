#include <iostream>
#include "string"

using namespace std;

int main() {
    std::cout << "House" << std::endl;
    string lodgers[10];
    int apart;
    cout << "Enter the lodgers data:" << endl;
    for (int i=0; i<10; i++) cin >> lodgers[i];
    for (int i=0;i<3;i++)
    {
        cout << "Enter the apartment number (from 1 to 10):" << endl;
        cin >> apart;
        if (apart<1||apart>10) {cout << "Apartment number is incorrect" << endl;}
        else {cout << lodgers[apart-1] << endl;}
    }
    return 0;
}

#include <iostream>
#include "sstream"

using namespace std;

int main() {
    cout << "Task 2" << endl;
    int whole, fraction;
    stringstream temp;
    double num;

    cout << "Enter whole part of number: " << endl;
    cin >> whole;
    cout << "Enter fraction part of number: " << endl;
    cin >> fraction;
    temp << whole << "." << fraction;
    num = stod(temp.str());
    cout << "Your number is " << num << endl;

    return 0;
}

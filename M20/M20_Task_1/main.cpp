#include <iostream>
#include "fstream"

using namespace std;

int main() {
    cout << "Task 1" << endl;

    ofstream data("..\\statement.txt", ios::app);
    string stop, fname, sname, date, payment;

    while (stop!="stop")
    {
        cout << "Enter first name, second name, date and payment value" << endl;
        cin >> fname >> sname >> date >> payment;
        data << fname << " " << sname << " "<< date << " " << payment <<endl;
        cout << "Enter 'stop' if ypu want to exit, and 'next' if you want to continue." << endl;
        cin >> stop;
    }

    return 0;
}

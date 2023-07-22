#include <iostream>
#include "random"
#include "Phone.h"

using namespace std;

int main() {
    cout << "Task 2" << endl;
    srand(time(nullptr));

    Phone*ph=new Phone;
    ph->fillPhoneBook();

    cout << "Your current phonebook:" << endl;
    ph->showPhoneBook();

    string command;

    while (command!="exit")
    {
        cout << "Enter one of the next command: 'add', 'call', 'sms', 'exit'" << endl;
        cin>>command;

        if (command=="add")
            ph->addContact();
        else if (command=="call")
            ph->makeCall();
        else if (command=="sms")
            ph->makeSMS();
        else if (command=="exit")
            cout << "Good bye! :) " << endl;
    }

    delete ph;
    return 0;
}

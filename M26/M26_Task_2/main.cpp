#include <iostream>
#include "random"
#include "Phone.h"


int main() {
    std::cout << "Task 2" << std::endl;
    srand(time(nullptr));

    Phone*ph=new Phone;
    ph->fillPhoneBook();

    std::cout << "Your current phonebook:" << std::endl;
    ph->showPhoneBook();

    std::string command;

    while (command!="exit")
    {
        std::cout << "Enter one of the next command: 'add', 'call', 'sms', 'exit'" << std::endl;
        std::cin>>command;

        if (command=="add")
            ph->addContact();
        else if (command=="call")
            ph->makeCall();
        else if (command=="sms")
            ph->makeSMS();
        else if (command=="exit")
            std::cout << "Good bye! :) " << std::endl;
    }

    delete ph;
    return 0;
}

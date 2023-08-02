#include <iostream>
#include "map"


std::map<std::string, std::string> addCustomer(std::map<std::string,std::string> dir)
{
    std::string number, name;
    std::cout << "Enter customer phone number (format: xx-xx-xx):" << std::endl;
    std::cin >> number;
    std::cout << "Enter customer second name: " << std::endl;
    std::cin >> name;
    dir.insert(std::pair<std::string, std::string>(number,name));
    return dir;
};

void findCustomer(std::map<std::string,std::string> dir)
{
    std::string name;
    std::cout << "Enter customer second name: " << std::endl;
    std::cin >> name;
    std::map<std::string,std::string>::iterator it;
    for (it=dir.begin(); it!=dir.end();it++)
    {
        if(name==it->second)
        {
            std::cout << it->first << std::endl;
            continue;
        }
        if (it==dir.end()) std::cout << "There is no match." << std::endl;
    }
};

void findNumber(std::map<std::string,std::string> dir)
{
    std::string number;
    std::cout << "Enter customer phone number (format: xx-xx-xx):" << std::endl;
    std::cin >> number;
    std::map<std::string,std::string>::iterator it;
    if(number==dir.find(number)->first) std::cout << dir.find(number)->second << std::endl;
    else std::cout << "There is no match." << std::endl;
};

int main() {
    std::cout << "Task 1" << std::endl;

    std::map<std::string,std::string>directory;

    int command=0;
    bool condition = true;
    while (condition)
    {
        std::cout << "Choose command: '1 - add new entry', '2 - find number by customer second name', '3 - find customer by number' " << std::endl;
        std::cin >> command;
        if (command==1) directory=addCustomer(directory);
        else if (command==2) findCustomer(directory);
        else if (command==3) findNumber(directory);
        if (command<1||command>3) {std::cerr << "Input command error!"; return 1;}
        std::cout << "If you want to continue, please enter '1'. If you want to stop, please enter '0'." << std::endl;
        std::cin >> condition;
    }

    return 0;
}

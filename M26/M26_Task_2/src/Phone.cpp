#include "Phone.h"
#include "sstream"
#include "iostream"


void Phone::makeCall()
{
    std::string var;
    std::map<std::string,std::string>tmp_cont;
    std::cout << "Enter contact name or number: " << std::endl;
    std::cin >> var;
    if (var[0]=='+')
        tmp_cont=bk->getContact(var, "null");
    else
        tmp_cont=bk->getContact("null",var);
    if (tmp_cont.begin()->first==var||tmp_cont.begin()->second==var)
    {
        std::cout << "Calling next contact: " << std::endl;
        std::cout << tmp_cont.begin()->first << " " <<  tmp_cont.begin()->second << std::endl;
    }
}

void Phone::makeSMS()
{
    std::string var;
    std::string message;
    std::map<std::string,std::string>tmp_cont;
    std::cout << "Enter contact name or number: " << std::endl;
    std::cin >> var;
    if (var[0]=='+')
        tmp_cont=bk->getContact(var, "null");
    else
        tmp_cont=bk->getContact("null",var);
    if (tmp_cont.begin()->first==var||tmp_cont.begin()->second==var)
    {
        std::cout << "Enter your message:" << std::endl;
        std::cin.ignore();
        getline(std::cin,message);
        std::cout << "To contact: " << std::endl;
        std::cout << tmp_cont.begin()->first << " " <<  tmp_cont.begin()->second << std::endl;
        std::cout << "Next message is send: " << std::endl << message << std::endl;
    }
}

void Phone::addContact()
{
    std::string number{}, name{};
    std::cout << "Enter new contact number (format is +7XXXXXXXXXX):" << std::endl;
    std::cin>>number;
    std::cout << "Enter contact name:" << std::endl;
    std::cin>>name;
    bk->setContact(number, name);

    showPhoneBook();
}

void Phone::showPhoneBook()
{
    std::map<std::string,std::string>tmp=bk->getContact();
    for (auto it = tmp.begin(); it!=tmp.end();it++)
    {
        std::cout << it->first << " " << it->second << std::endl;
    }
}

void Phone::fillPhoneBook()
{
    std::string number, name;

    for (int i=0; i<5; i++)
    {
        std::stringstream tmp1, tmp2;
        tmp2 << "contact_" << i+1;
        name = tmp2.str();
        tmp2.clear();
        tmp1 << "+7" << rand()%99+900 << rand()%99+500 << rand()%9+50 <<rand()%9+50;
        number = tmp1.str();
        tmp1.clear();
        bk->setContact(number, name);
    }
}
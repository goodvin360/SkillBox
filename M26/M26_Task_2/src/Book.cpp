#include "Book.h"
#include "iostream"

std::map<std::string,std::string> Book::getContact(std::string number, std::string name)
{
    if (number=="null"&&name=="null")
        return phoneBook;
    else if (name=="null")
    {
        std::map<std::string,std::string>tmp_cont;
        if (phoneBook.find(number)!=phoneBook.end())
        {auto it=phoneBook.find(number);
            tmp_cont.insert(std::pair<std::string,std::string>(it->first,it->second));
            return tmp_cont;}
        else
        {
            std::cout << "There is no such contact in PhoneBook." << std::endl;
            tmp_cont.insert(std::pair<std::string,std::string>("none","none"));
            return tmp_cont;
        }
    }
    else if (number=="null")
    {
        std::map<std::string,std::string>tmp_cont;
        bool check = false;
        for (auto it=phoneBook.begin(); it!=phoneBook.end();it++)
        {
            if(name==it->second)
            {
                tmp_cont.insert(std::pair<std::string,std::string>(it->first,it->second));
                check = true;
                return tmp_cont;
            }
        }
        if (!check)
        {
            std::cout << "There is no such contact in PhoneBook." << std::endl;
            tmp_cont.insert(std::pair<std::string,std::string>("none","none"));
            return tmp_cont;
        }
    }
}

void Book::setContact(std::string number, std::string name)
{
    phoneBook.insert(std::pair<std::string, std::string> (number, name));


}

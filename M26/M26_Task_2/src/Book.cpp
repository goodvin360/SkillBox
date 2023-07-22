#include "Book.h"
#include "iostream"

map<string,string> Book::getContact(string number, string name)
{
    if (number=="null"&&name=="null")
        return phoneBook;
    else if (name=="null")
    {
        map<string,string>tmp_cont;
        if (phoneBook.find(number)!=phoneBook.end())
        {auto it=phoneBook.find(number);
            tmp_cont.insert(pair<string,string>(it->first,it->second));
            return tmp_cont;}
        else
        {
            cout << "There is no such contact in PhoneBook." << endl;
            tmp_cont.insert(pair<string,string>("none","none"));
            return tmp_cont;
        }
    }
    else if (number=="null")
    {
        map<string,string>tmp_cont;
        bool check = false;
        for (auto it=phoneBook.begin(); it!=phoneBook.end();it++)
        {
            if(name==it->second)
            {
                tmp_cont.insert(pair<string,string>(it->first,it->second));
                check = true;
                return tmp_cont;
            }
        }
        if (!check)
        {
            cout << "There is no such contact in PhoneBook." << endl;
            tmp_cont.insert(pair<string,string>("none","none"));
            return tmp_cont;
        }
    }
}

void Book::setContact(string number, string name)
{
    phoneBook.insert(pair<string, string> (number, name));


}

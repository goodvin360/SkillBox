#include "Phone.h"
#include "sstream"
#include "iostream"

using namespace std;

void Phone::makeCall()
{
    string var;
    map<string,string>tmp_cont;
    cout << "Enter contact name or number: " << endl;
    cin >> var;
    if (var[0]=='+')
        tmp_cont=bk->getContact(var, "null");
    else
        tmp_cont=bk->getContact("null",var);
    if (tmp_cont.begin()->first==var||tmp_cont.begin()->second==var)
    {
        cout << "Calling next contact: " << endl;
        cout << tmp_cont.begin()->first << " " <<  tmp_cont.begin()->second << endl;
    }
}

void Phone::makeSMS()
{
    string var;
    string message;
    map<string,string>tmp_cont;
    cout << "Enter contact name or number: " << endl;
    cin >> var;
    if (var[0]=='+')
        tmp_cont=bk->getContact(var, "null");
    else
        tmp_cont=bk->getContact("null",var);
    if (tmp_cont.begin()->first==var||tmp_cont.begin()->second==var)
    {
        cout << "Enter your message:" << endl;
        cin.ignore();
        getline(cin,message);
        cout << "To contact: " << endl;
        cout << tmp_cont.begin()->first << " " <<  tmp_cont.begin()->second << endl;
        cout << "Next message is send: " << endl << message << endl;
    }
}

void Phone::addContact()
{
    string number{}, name{};
    cout << "Enter new contact number (format is +7XXXXXXXXXX):" << endl;
    cin>>number;
    cout << "Enter contact name:" << endl;
    cin>>name;
    bk->setContact(number, name);

    showPhoneBook();
}

void Phone::showPhoneBook()
{
    map<string,string>tmp=bk->getContact();
    for (auto it = tmp.begin(); it!=tmp.end();it++)
    {
        cout << it->first << " " << it->second << endl;
    }
}

void Phone::fillPhoneBook()
{
    string number, name;

    for (int i=0; i<5; i++)
    {
        stringstream tmp1, tmp2;
        tmp2 << "contact_" << i+1;
        name = tmp2.str();
        tmp2.clear();
        tmp1 << "+7" << rand()%99+900 << rand()%99+500 << rand()%9+50 <<rand()%9+50;
        number = tmp1.str();
        tmp1.clear();
        bk->setContact(number, name);
    }
}
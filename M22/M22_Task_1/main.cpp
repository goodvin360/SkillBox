#include <iostream>
#include "map"

using namespace std;

map<string, string> addCustomer(map<string,string> dir)
{
    string number, name;
    cout << "Enter customer phone number (format: xx-xx-xx):" << endl;
    cin >> number;
    cout << "Enter customer second name: " << endl;
    cin >> name;
    dir.insert(pair<string, string>(number,name));
    return dir;
};

void findCustomer(map<string,string> dir)
{
    string name;
    cout << "Enter customer second name: " << endl;
    cin >> name;
    map<string,string>::iterator it;
    for (it=dir.begin(); it!=dir.end();it++)
    {
        if(name==it->second)
        {
            cout << it->first << endl;
            continue;
        }
        if (it==dir.end()) cout << "There is no match." << endl;
    }
};

void findNumber(map<string,string> dir)
{
    string number;
    cout << "Enter customer phone number (format: xx-xx-xx):" << endl;
    cin >> number;
    map<string,string>::iterator it;
    if(number==dir.find(number)->first) cout << dir.find(number)->second << endl;
    else cout << "There is no match." << endl;
};

int main() {
    cout << "Task 1" << endl;

    map<string,string>directory;

    int command=0;
    bool condition = true;
    while (condition)
    {
        cout << "Choose command: '1 - add new entry', '2 - find number by customer second name', '3 - find customer by number' " << endl;
        cin >> command;
        if (command==1) directory=addCustomer(directory);
        else if (command==2) findCustomer(directory);
        else if (command==3) findNumber(directory);
        if (command<1||command>3) {cerr << "Input command error!"; return 1;}
        cout << "If you want to continue, please enter '1'. If you want to stop, please enter '0'." << endl;
        cin >> condition;
    }

    return 0;
}

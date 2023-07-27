#include <iostream>
#include "cpr/cpr.h"

using namespace std;
using namespace cpr;

int main() {
    cout << "Task 1" << endl;

    Response r;

    string command{};
    while(command!="exit")
    {
        cout << "enter one of the next command: 'get', 'post', 'put', 'delete', 'patch' or 'exit': " << endl;
        cin >> command;
        if (command!="get"&&command!="post"&&command!="put"&&command!="delete"&&command!="patch"&&command!="exit")
        {
            cout << "Wrong command. Try again." << endl;
            continue;
        }
        if (command=="get")
        {
            r = Get(Url("https://httpbin.org/get"));
            cout << r.text;

        }
        else if (command=="post")
        {
            string name="Somebody", city="Somewhere";
            r = Post(Url("https://httpbin.org/post"),Payload({{"name",name.c_str()},{"city", city.c_str()}}));
            cout << r.text;
        }
        else if (command=="put")
        {
            r = Put(Url("https://httpbin.org/put"));
            cout << r.text;
        }
        else if (command=="delete")
        {
            r = Delete(Url("https://httpbin.org/delete"));
            cout << r.text;
        }
        else if (command=="patch")
        {
            r = Patch(Url("https://httpbin.org/patch"));
            cout << r.text;
        }
    }

    return 0;
}

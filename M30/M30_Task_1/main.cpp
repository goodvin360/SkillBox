#include <iostream>
#include "cpr/cpr.h"


int main() {
    std::cout << "Task 1" << std::endl;

    cpr::Response r;

    std::string command{};
    while(command!="exit")
    {
        std::cout << "enter one of the next command: 'get', 'post', 'put', 'delete', 'patch' or 'exit': " << std::endl;
        std::cin >> command;
        if (command!="get"&&command!="post"&&command!="put"&&command!="delete"&&command!="patch"&&command!="exit")
        {
            std::cout << "Wrong command. Try again." << std::endl;
            continue;
        }
        if (command=="get")
        {
            r = Get(cpr::Url("https://httpbin.org/get"));
            std::cout << r.text;

        }
        else if (command=="post")
        {
            std::string name="Somebody", city="Somewhere";
            r = Post(cpr::Url("https://httpbin.org/post"),cpr::Payload({{"name",name.c_str()},{"city", city.c_str()}}));
            std::cout << r.text;
        }
        else if (command=="put")
        {
            r = Put(cpr::Url("https://httpbin.org/put"));
            std::cout << r.text;
        }
        else if (command=="delete")
        {
            r = Delete(cpr::Url("https://httpbin.org/delete"));
            std::cout << r.text;
        }
        else if (command=="patch")
        {
            r = Patch(cpr::Url("https://httpbin.org/patch"));
            std::cout << r.text;
        }
    }

    return 0;
}

#include <iostream>
#include "cpr/cpr.h"


int main() {
    std::cout << "Task 2" << std::endl;
    std::string title;
    cpr::Response r;
    r = cpr::Get(cpr::Url("https://httpbin.org/html"),
                 cpr::Header({{"Accept","text/html"}}));
    int start = r.text.find("<h1>")+4;
    int end = r.text.find("</h1>");
    int length = end-start;

    title = r.text.substr(start,length);
    std::cout << "Title is: " << title;

    return 0;
}

#include <iostream>
#include "cpr/cpr.h"

using namespace std;
using namespace cpr;

int main() {
    cout << "Task 2" << endl;
    string title;
    Response r;
    r = cpr::Get(cpr::Url("https://httpbin.org/html"),
                 Header({{"Accept","text/html"}}));
    int start = r.text.find("<h1>")+4;
    int end = r.text.find("</h1>");
    int length = end-start;

    title = r.text.substr(start,length);
    cout << "Title is: " << title;

    return 0;
}

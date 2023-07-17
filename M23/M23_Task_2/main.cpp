#include <iostream>
using namespace std;

#define SPRING
//#define SUMMER
//#define AUTUMN
//#define WINTER

int main() {
    cout << "Task 2" << endl;
    #ifdef SPRING
        cout << "Spring"<<endl;
    #endif
    #ifdef SUMMER
        cout << "Summer"<<endl;
    #endif
    #ifdef AUTUMN
        cout << "Autumn"<<endl;
    #endif
    #ifdef WINTER
        cout << "Winter"<<endl;
    #endif

    return 0;
}

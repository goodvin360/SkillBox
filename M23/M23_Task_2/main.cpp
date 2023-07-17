#include <iostream>
using namespace std;

#define SPRING
//#define SUMMER
//#define AUTUMN
//#define WINTER

int main() {
#ifdef SPRING
    std::cout << "Spring"<<std::endl;
#endif
#ifdef SUMMER
    std::cout << "Summer"<<std::endl;
#endif
#ifdef AUTUMN
    std::cout << "Autumn"<<std::endl;
#endif
#ifdef WINTER
    std::cout << "Winter"<<std::endl;
#endif
}

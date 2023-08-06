#include <iostream>

#define SPRING
//#define SUMMER
//#define AUTUMN
//#define WINTER

int main() {
    std::cout << "Task 2" << std::endl;
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

    return 0;
}

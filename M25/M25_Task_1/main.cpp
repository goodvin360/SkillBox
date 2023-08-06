#include <iostream>
#include "functions.h"


int main() {
    std::cout << "Task 1" << std::endl;
    int command;

    dot dot_1, dot_2, dot_tmp;

    bool check=false;
    while (!check)
    {
     std::cout << "Enter command (1 - scalpel, 2 - hemostat, 3 - tweezers, 4 - suture):" << std::endl;
     std::cin >> command;
     switch (command) {
        case 1: scalpel(dot_1, dot_2);break;
        case 2: hemostat(dot_tmp);break;
        case 3: tweezers(dot_tmp);break;
        case 4: check=suture(dot_1, dot_2);}
    }

    return 0;
}

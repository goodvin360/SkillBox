#include <iostream>
#include "CPU.h"
#include "RAM.h"
#include "DISK.h"
#include "KBD.h"
#include "GPU.h"


int main() {
    std::cout << "Task 2" << std::endl;

    ram array;
    int command=-1;

    while (command!=0)
    {
        std::cout << "Enter command: 1 - input, 2 - display, 3 - save, 4 - load, 5 - sum, 0 - exit" << std::endl;
        std::cin >> command;
        if (command<0||command>5) {std::cout << "Command entry error. Try again." << std::endl;
            continue;}
        switch (command) {
            case 1:write(array); break;
            case 2:read(array); break;
            case 3:save(array); break;
            case 4:load(array); break;
            case 5:compute(array); break;
        }
    }

    return 0;
}

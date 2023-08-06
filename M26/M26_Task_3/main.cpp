#include <iostream>
#include "Screen.h"
#include "Window.h"


int main() {
    std::cout << "Task 3" << std::endl;

    Screen*scr = new Screen;

    std::string command;

    while (command!="close")
    {
        std::cout << "Enter one of the next command: 'move', 'resize', 'display', 'close'" << std::endl;
        std::cin>>command;

        if (command=="move")
            scr->moveWindow();
        else if (command=="resize")
            scr->resizeWindow();
        else if (command=="display")
            scr->displayScreen();
        else if (command=="close")
            std::cout << "Good bye! :) " << std::endl;
    }

    delete scr;
    return 0;
}

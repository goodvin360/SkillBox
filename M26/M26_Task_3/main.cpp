#include <iostream>
#include "Screen.h"
#include "Window.h"

using namespace std;

int main() {
    cout << "Task 3" << endl;

    Screen*scr = new Screen;

    string command;

    while (command!="close")
    {
        cout << "Enter one of the next command: 'move', 'resize', 'display', 'close'" << endl;
        cin>>command;

        if (command=="move")
            scr->moveWindow();
        else if (command=="resize")
            scr->resizeWindow();
        else if (command=="display")
            scr->displayScreen();
        else if (command=="close")
            cout << "Good bye! :) " << endl;
    }

    delete scr;
    return 0;
}

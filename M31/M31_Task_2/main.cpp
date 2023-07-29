#include <iostream>
#include <memory>
#include "vector"
#include "Toy.h"
#include "Dog.h"
#include "Shared_ptr_toy.h"



int main() {
    std::cout << "Task 1" << std::endl;

    Shared_ptr_toy ball ("Ball");
    Shared_ptr_toy bone ("Bone");

    Dog a;
    Dog b;
    Dog c;

    // check old functional
    std::cout << " %%%%% check old functional %%%%% " << std::endl;
    a.getToy(ball);
    b.getToy(ball);
    a.dropToy();
    a.showToy();
    b.getToy(ball);
    b.showToy();
    std::cout << std::endl;

    // check make_shared_toy functional
    std::cout << " %%%%% check make_shared_toy functional %%%%% " << std::endl;
    c.getToy(bone);
    c.showToy();

    auto newToy1 = Shared_ptr_toy::make_shared_toy("Bear");
    c.getToy(newToy1);
    c.dropToy();
    c.getToy(newToy1);
    c.showToy();
    c.dropToy();

    auto newToy2 = Shared_ptr_toy::make_shared_toy(newToy1);
    c.getToy(newToy2);
    c.showToy();

    // check refs num
    std::cout << "Num of refs " << ball.obj->name << " toy: " << ball.getCount() << std::endl;
    std::cout << "Num of refs " << bone.obj->name << " toy: " << bone.getCount() << std::endl;
    std::cout << "Num of refs " << newToy1.obj->name << " toy: " << newToy1.getCount() << std::endl;// there is only toy, because of dropToy() for dog c
    std::cout << "Num of refs " << newToy2.obj->name << " toy: " << newToy2.getCount() << std::endl; // there is dog 'c' and toy


    /*std::string command;

    while (command!="exit")
    {
        for (int i=0; i<dogs.size(); i++)
        {
            std::cout << "Enter your command for " << i+1 << " dog: get ball, get bone, drop toy, show toy or exit" << std::endl;
            std::getline(std::cin,command);
            if (command=="exit") return 0;
            else if (command == "get ball") dogs[i]->getToy(ball);
            else if (command == "get bone") dogs[i]->getToy(bone);
            else if (command == "drop toy") dogs[i]->dropToy();
            else if (command == "show toy") dogs[i]->showToy();
            else if (command!="get ball" && command!="get bone" && command!="drop toy" && command!="show toy")
            {
                i=0;
                std::cout << "Error entering command. Try again." << std::endl;
                break;
            }
        }
    }*/


    return 0;
}

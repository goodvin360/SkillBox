#include <iostream>
#include <memory>
#include "vector"
#include "Toy.h"
#include "Dog.h"

int main() {
    std::cout << "Task 1" << std::endl;

    std::shared_ptr<Toy> ball = std::make_shared<Toy>("Ball");
    std::shared_ptr<Toy> bone = std::make_shared<Toy>("Bone");

    std::vector<Dog*> dogs {new Dog,new Dog,new Dog};

    std::string command;

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
    }

    for (auto &it:dogs)
        delete it;

    return 0;
}

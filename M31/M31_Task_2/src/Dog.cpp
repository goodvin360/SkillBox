#include "Dog.h"

void Dog::getToy(Shared_ptr_toy &toy)
{
    if(toy.getCount()==1&& myToy.obj== nullptr)
        myToy = toy;
    else if (toy.getCount()>1)
        std::cout << "Another dog is playing with this toy" << std::endl;
    else if (toy.obj->name==myToy.obj->name)
        std::cout << "I already have this toy" << std::endl;
    else if (toy.obj->name!=myToy.obj->name && myToy.obj!= nullptr)
        std::cout << "I already have another toy" << std::endl;
}


void Dog::dropToy()
{
    if (myToy.obj!= nullptr)
        myToy.destruct_ptr_toy();
    else std::cout << "I don't have any toy" << std::endl;
}

void Dog::showToy()
{
    if (myToy.obj!= nullptr)
        std::cout << myToy.obj->name << std::endl;
    else std::cout << "I don't have any toy" << std::endl;
}
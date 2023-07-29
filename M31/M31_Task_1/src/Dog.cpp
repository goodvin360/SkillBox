#include "Dog.h"

void Dog::getToy(std::shared_ptr<Toy> &toy)
{
    if(toy.use_count()==1 &&lovelyToy== nullptr)
        lovelyToy = toy;
    else if (toy.use_count()>1)
        std::cout << "Another dog is playing with this toy" << std::endl;
    else if (toy->name==lovelyToy->name)
        std::cout << "I already have this toy" << std::endl;
    else if (toy->name!=lovelyToy->name && lovelyToy!= nullptr)
        std::cout << "I already have another toy" << std::endl;
}

void Dog::dropToy()
{
    if (lovelyToy!= nullptr)
        lovelyToy.reset();
    else std::cout << "I don't have any toy" << std::endl;
}

void Dog::showToy()
{
    if (lovelyToy!= nullptr)
        std::cout << lovelyToy->name << std::endl;
    else std::cout << "I don't have any toy" << std::endl;
}
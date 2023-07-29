#ifndef M31_TASK_1_DOG_H
#define M31_TASK_1_DOG_H

#pragma once
#include "Toy.h"
#include "string"
#include "memory"
#include "iostream"

class Dog
{
private:
    std::shared_ptr<Toy> lovelyToy;
public:

    void getToy(std::shared_ptr<Toy> &toy);
    void dropToy();
    void showToy();
};


#endif //M31_TASK_1_DOG_H

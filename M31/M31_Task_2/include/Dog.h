#ifndef M31_TASK_1_DOG_H
#define M31_TASK_1_DOG_H

#pragma once
#include "Toy.h"
#include "Shared_ptr_toy.h"
#include "string"
#include "memory"
#include "iostream"

class Dog
{
private:
    Shared_ptr_toy myToy;
public:
    Dog()
    {
        myToy.obj = nullptr;
    }

    void getToy(Shared_ptr_toy &toy);
    void dropToy();
    void showToy();
};


#endif //M31_TASK_1_DOG_H

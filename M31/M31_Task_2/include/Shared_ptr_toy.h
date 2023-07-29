#ifndef M31_TASK_2_SHARED_PTR_TOY_H
#define M31_TASK_2_SHARED_PTR_TOY_H

#pragma once
#include "string"
#include "iostream"
#include "Toy.h"

class Shared_ptr_toy
{
private:
    int *refCount;
public:
    Toy*obj;

    Shared_ptr_toy();

    Shared_ptr_toy(std::string inName);

    Shared_ptr_toy(const Shared_ptr_toy &oth);

    Shared_ptr_toy &operator=(const Shared_ptr_toy &oth);

    ~Shared_ptr_toy();

    static Shared_ptr_toy make_shared_toy(std::string inName);

    static Shared_ptr_toy make_shared_toy(Shared_ptr_toy &inToy);

    void destruct_ptr_toy();

    void resetPtr();

    int getCount();
};

#endif //M31_TASK_2_SHARED_PTR_TOY_H

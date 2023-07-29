#ifndef M31_TASK_1_TOY_H
#define M31_TASK_1_TOY_H

#include "string"

#pragma once

class Toy
{
public:
    Toy(std::string inName):name(inName) {}
    Toy() : name("SomeToy") {}
    std::string name;
};


#endif //M31_TASK_1_TOY_H

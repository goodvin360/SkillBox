#ifndef M27_TASK_2_RECTANGLE_H
#define M27_TASK_2_RECTANGLE_H

#pragma once
#include "Figure.h"

using namespace std;

class Rectangle : public Figure
{
    double sideA;
    double sideB;

public:

    void setSide();
    double findArea();
    void showInfo();
    void findFigure();

};

#endif //M27_TASK_2_RECTANGLE_H

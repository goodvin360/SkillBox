#ifndef M27_TASK_2_TRIANGLE_H
#define M27_TASK_2_TRIANGLE_H

#pragma once
#include "Figure.h"

using namespace std;

class Triangle : public Figure
{
    double side;

public:

    void setSide();
    double findArea();
    void showInfo();
    void findFigure();

};

#endif //M27_TASK_2_TRIANGLE_H

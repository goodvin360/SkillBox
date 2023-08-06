#ifndef M27_TASK_2_CIRCLE_H
#define M27_TASK_2_CIRCLE_H

#pragma once
#include "Figure.h"


class Circle : public Figure
{
    double radius;

public:

    void setRadius();
    double findArea();
    void showInfo();
    void findFigure();

};

#endif //M27_TASK_2_CIRCLE_H

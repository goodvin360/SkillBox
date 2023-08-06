#ifndef M27_TASK_2_SQUARE_H
#define M27_TASK_2_SQUARE_H

#pragma once
#include "Figure.h"


class Square : public Figure
{
    double side;

public:

    void setSide();
    double findArea();
    void showInfo();
    void findFigure();

};

#endif //M27_TASK_2_SQUARE_H

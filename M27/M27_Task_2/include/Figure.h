#ifndef M27_TASK_2_FIGURE_H
#define M27_TASK_2_FIGURE_H

#pragma once
#include "iostream"
#include "assert.h"

using namespace std;

enum colours {red=1, blue, green, magenta};

struct center {int x0; int y0;};

class Figure
{
    center point;
    colours colour_type;
    string colour;


public:

    void setCenter();
    void setColour();
    string getColour();
    center getCenter();
    center a,b,c,d;
};

#endif //M27_TASK_2_FIGURE_H

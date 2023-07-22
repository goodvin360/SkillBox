#ifndef M26_TASK_3_WINDOW_H
#define M26_TASK_3_WINDOW_H

#pragma once
#include "vector"

using namespace std;

struct startPoint {int x=0; int y=0;};
struct windowSize {int h=0; int w=0;};

class Window
{
    startPoint point;
    windowSize size;

public:
    void setStartPoint(int screenWight, int screenHeight);
    void setWindowSize(int screenWight, int screenHeight);
    startPoint getStartPoint();
    windowSize getWindowSize();
};

#endif //M26_TASK_3_WINDOW_H

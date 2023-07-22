#ifndef M26_TASK_3_SCREEN_H
#define M26_TASK_3_SCREEN_H

#pragma once
#include "Window.h"

class Screen
{
public:
    void displayScreen();
    void moveWindow();
    void resizeWindow();
    Window*win=new Window;
    int screenHeight=80, screenWight=50;
};

#endif //M26_TASK_3_SCREEN_H

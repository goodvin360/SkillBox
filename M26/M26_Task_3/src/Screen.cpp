#include "Screen.h"
#include "iostream"


void Screen::displayScreen()
{
    int winWight=0, winHeight=0;
    int startX=0, startY=0;

    winHeight=win->getWindowSize().h;
    winWight=win->getWindowSize().w;

    startX = win->getStartPoint().x;
    startY = win->getStartPoint().y;

    for (int i=0; i<screenHeight; i++)
    {
        for (int j=0; j<screenWight; j++)
        {
            if((i>=startY&&i<(startY+winHeight))&&(j>=startX&&j<(startX+winWight)))
                std::cout << "1";
            else std::cout << "0";
        }
        std::cout << std::endl;
    }
}

void Screen::moveWindow()
{
    win->setStartPoint(screenWight, screenHeight);
}

void Screen::resizeWindow()
{
    win->setWindowSize(screenWight, screenHeight);
}
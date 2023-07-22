#include "Screen.h"
#include "iostream"

using namespace std;

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
                cout << "1";
            else cout << "0";
        }
        cout << endl;
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
#include "Window.h"
#include "iostream"


void Window::setStartPoint(int screenWight, int screenHeight)
{
    int x=-1,y=-1;
    while (x<0||y<0||(x+size.w)>screenWight||(y+size.h)>screenHeight)
    {
        std::cout << "Enter new window start point coordinates (x,y):" << std::endl;
        std::cin >> x >> y;
        if (x<0||y<0||(x+size.w)>screenWight||(y+size.h)>screenHeight) std::cout << "Incorrect input. Try again." << std::endl;
    }
    point.x=x;
    point.y=y;
}

void Window::setWindowSize(int screenWight, int screenHeight)
{
    int h=-1,w=-1;
    while (h<0||w<0||(point.x+w)>screenWight||(point.y+h)>screenHeight)
    {
        std::cout << "Enter new window height and wight:" << std::endl;
        std::cin >> h >> w;
        if (h<0||w<0||(point.x+w)>screenWight||(point.y+h)>screenHeight) std::cout << "Incorrect input. Try again." << std::endl;
    }
    size.h = h;
    size.w = w;
}

startPoint Window::getStartPoint()
{
    return point;
}

windowSize Window::getWindowSize()
{
    return size;
}
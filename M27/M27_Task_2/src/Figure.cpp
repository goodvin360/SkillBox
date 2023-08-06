#include "Figure.h"
#include "Circle.h"

void Figure::setCenter()
{
    int x=0,y=0;
    std::cout << "Enter center point coordinates (x, y): " << std::endl;
    std::cin >> x >> y;
    point.x0=x;
    point.y0=y;
}

void Figure::setColour()
{
    int var;
    std::cout << "Enter figure colour (1 - red, 2 - blue, 3 - green, 4 - magenta): " << std::endl;
    std::cin >> var;
    colour_type = static_cast<colours>(var);
    switch (var)
    {
        case colours::red: colour = "red"; break;
        case colours::blue: colour = "blue"; break;
        case colours::green: colour = "green"; break;
        case colours::magenta: colour = "magenta"; break;
    }
}

center Figure::getCenter()
{
    return point;
}

std::string Figure::getColour()
{
    return colour;
}
#include "Square.h"
#include "cmath"

void Square::setSide()
{
    double s;
    std::cout << "Enter square side : " << std::endl;
    std::cin >> s;
    assert(s>=0);
    side = s;
}

double Square::findArea()
{
    return pow(side,2);
}

void Square::findFigure()
{
    a.x0=getCenter().x0-side/2;
    a.y0=getCenter().y0-side/2;
    b.x0 = a.x0+side;
    b.y0 = a.y0;
    c.x0 = b.x0;
    c.y0 = b.y0+side;
    d.x0 = a.x0;
    d.y0 = c.y0;
}

void Square::showInfo()
{
    std::cout << "There is square with next parameters: " << std::endl;
    std::cout << "Center point is: " << getCenter().x0 << " " << getCenter().y0 << std::endl;
    std::cout << "Colour: " << getColour() << std::endl;
    std::cout << "Area: " << findArea() << std::endl;
    findFigure();
    std::cout << "Outer rectangle coordinates: a(" << a.x0 << ", " << a.y0 <<
         "), b(" <<b.x0 << ", " <<b.y0 << "), c(" <<c.x0 << ", " <<c.y0 << "), d(" <<d.x0 << ", " <<d.y0 << ")" << std::endl;
}
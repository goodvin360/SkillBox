#include "Rectangle.h"
#include "cmath"

void Rectangle::setSide()
{
    double a,b;
    std::cout << "Enter rectangle sides (a, b) : " << std::endl;
    std::cin >> a >> b;
    assert(a>=0);
    assert(b>=0);
    sideA = a;
    sideB = b;
}

double Rectangle::findArea()
{
    return sideA*sideB;
}

void Rectangle::findFigure()
{
    a.x0=getCenter().x0-sideA/2;
    a.y0=getCenter().y0-sideB/2;
    b.x0 = a.x0+sideA;
    b.y0 = a.y0;
    c.x0 = b.x0;
    c.y0 = b.y0+sideB;
    d.x0 = a.x0;
    d.y0 = c.y0;
}

void Rectangle::showInfo()
{
    std::cout << "There is rectangle with next parameters: " << std::endl;
    std::cout << "Center point is: " << getCenter().x0 << " " << getCenter().y0 << std::endl;
    std::cout << "Colour: " << getColour() << std::endl;
    std::cout << "Area: " << findArea() << std::endl;
    findFigure();
    std::cout << "Outer rectangle coordinates: a(" << a.x0 << ", " << a.y0 <<
         "), b(" <<b.x0 << ", " <<b.y0 << "), c(" <<c.x0 << ", " <<c.y0 << "), d(" <<d.x0 << ", " <<d.y0 << ")" << std::endl;
}
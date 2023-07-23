#include "Circle.h"
#include "cmath"

double Circle::findArea()
{
    return M_PI*pow(radius,2);
}

void Circle::setRadius()
{
    double r;
    cout << "Enter circle radius: " << endl;
    cin >> r;
    assert(r>=0);
    radius=r;

}

void Circle::findFigure()
{
    a.x0=getCenter().x0-radius;
    a.y0=getCenter().y0-radius;
    b.x0 = a.x0+2*radius;
    b.y0 = a.y0;
    c.x0 = b.x0;
    c.y0 = b.y0+2*radius;
    d.x0 = a.x0;
    d.y0 = c.y0;
}

void Circle::showInfo()
{
    cout << "There is circle with next parameters: " << endl;
    cout << "Center point is: " << getCenter().x0 << " " << getCenter().y0 << endl;
    cout << "Colour: " << getColour() << endl;
    cout << "Area: " << findArea() << endl;
    findFigure();
    cout << "Outer rectangle coordinates: a(" << a.x0 << ", " << a.y0 <<
    "), b(" <<b.x0 << ", " <<b.y0 << "), c(" <<c.x0 << ", " <<c.y0 << "), d(" <<d.x0 << ", " <<d.y0 << ")" << endl;
}
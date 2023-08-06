#include <iostream>
#include "Figure.h"
#include "Circle.h"
#include "Square.h"
#include "Triangle.h"
#include "Rectangle.h"


int main() {
    std::cout << "Task 2" << std::endl;
    Circle*circle=new Circle;
    Square*square=new Square;
    Triangle*triangle=new Triangle;
    Rectangle*rectangle=new Rectangle;

    std::string command;

    std::cout << "Enter figure name: 'circle', 'square', 'triangle', 'rectangle': " << std::endl;
    std::cin >> command;

    if (command=="circle")
    {
        circle->setCenter();
        circle->setColour();
        circle->setRadius();
        circle->showInfo();
    }
    else if (command=="square")
    {
        square->setCenter();
        square->setColour();
        square->setSide();
        square->showInfo();
    }
    else if (command=="triangle")
    {
        triangle->setCenter();
        triangle->setColour();
        triangle->setSide();
        triangle->showInfo();
    }
    else if(command=="rectangle")
    {
        rectangle->setCenter();
        rectangle->setColour();
        rectangle->setSide();
        rectangle->showInfo();
    }

    delete circle;
    delete square;
    delete triangle;
    delete rectangle;
    return 0;
}

#include "iostream"
#include "functions.h"


void scalpel(dot &dot_1, dot &dot_2)
{
    std::cout << "Enter start Incision dot coordinates (x1,y1):" << std::endl;
    std::cin >> dot_1.coordinate_x >> dot_1.coordinate_y;
    std::cout << "Enter end Incision dot coordinates (x2,y2):" << std::endl;
    std::cin >> dot_2.coordinate_x >> dot_2.coordinate_y;

    std::cout << "Incision made from a point " << dot_1.coordinate_x << "," << dot_1.coordinate_y <<
    " to the point " << dot_2.coordinate_x << "," << dot_2.coordinate_y << std::endl;
}

void hemostat(dot dot_tmp)
{
    std::cout << "Enter Hemostat dot coordinates (x,y):" << std::endl;
    std::cin >> dot_tmp.coordinate_x >> dot_tmp.coordinate_y;
    std::cout << "Hemostat placed at point " << dot_tmp.coordinate_x << "," << dot_tmp.coordinate_y << std::endl;
}

void tweezers(dot dot_tmp)
{
    std::cout << "Enter Tweezers dot coordinates (x,y):" << std::endl;
    std::cin >> dot_tmp.coordinate_x >> dot_tmp.coordinate_y;
    std::cout << "Tweezers placed at point " << dot_tmp.coordinate_x << "," << dot_tmp.coordinate_y << std::endl;
}

bool suture(dot &dot_1, dot &dot_2)
{
    double x1=0,y1=0,x2=0,y2=0;

    while (x1!=dot_1.coordinate_x && y1!=dot_1.coordinate_y &&
           x2!=dot_2.coordinate_x && y2!=dot_2.coordinate_y)
    {
        std::cout << "Enter start Suture dot coordinates (x1,y1):" << std::endl;
        std::cin >> x1 >> y1;
        std::cout << "Enter end Suture dot coordinates (x2,y2):" << std::endl;
        std::cin >> x2 >> y2;
        if (x1!=dot_1.coordinate_x || y1!=dot_1.coordinate_y ||
         x2!=dot_2.coordinate_x || y2!=dot_2.coordinate_y) std::cout << "Wrong dot coordinates, please try again." << std::endl;
    }

    std::cout << "Stitching made from a point " << dot_1.coordinate_x << "," << dot_1.coordinate_y <<
         " to the point " << dot_2.coordinate_x << "," << dot_2.coordinate_y << std::endl;
        return true;
}
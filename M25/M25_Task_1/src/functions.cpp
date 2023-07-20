#include "iostream"
#include "functions.h"

using namespace std;

void scalpel(dot &dot_1, dot &dot_2)
{
    cout << "Enter start Incision dot coordinates (x1,y1):" << endl;
    cin >> dot_1.coordinate_x >> dot_1.coordinate_y;
    cout << "Enter end Incision dot coordinates (x2,y2):" << endl;
    cin >> dot_2.coordinate_x >> dot_2.coordinate_y;

    cout << "Incision made from a point " << dot_1.coordinate_x << "," << dot_1.coordinate_y <<
    " to the point " << dot_2.coordinate_x << "," << dot_2.coordinate_y << endl;
}

void hemostat(dot dot_tmp)
{
    cout << "Enter Hemostat dot coordinates (x,y):" << endl;
    cin >> dot_tmp.coordinate_x >> dot_tmp.coordinate_y;
    cout << "Hemostat placed at point " << dot_tmp.coordinate_x << "," << dot_tmp.coordinate_y << endl;
}

void tweezers(dot dot_tmp)
{
    cout << "Enter Tweezers dot coordinates (x,y):" << endl;
    cin >> dot_tmp.coordinate_x >> dot_tmp.coordinate_y;
    cout << "Tweezers placed at point " << dot_tmp.coordinate_x << "," << dot_tmp.coordinate_y << endl;
}

bool suture(dot &dot_1, dot &dot_2)
{
    double x1=0,y1=0,x2=0,y2=0;

    while (x1!=dot_1.coordinate_x && y1!=dot_1.coordinate_y &&
           x2!=dot_2.coordinate_x && y2!=dot_2.coordinate_y)
    {
        cout << "Enter start Suture dot coordinates (x1,y1):" << endl;
        cin >> x1 >> y1;
        cout << "Enter end Suture dot coordinates (x2,y2):" << endl;
        cin >> x2 >> y2;
        if (x1!=dot_1.coordinate_x || y1!=dot_1.coordinate_y ||
         x2!=dot_2.coordinate_x || y2!=dot_2.coordinate_y) cout << "Wrong dot coordinates, please try again." << endl;
    }

        cout << "Stitching made from a point " << dot_1.coordinate_x << "," << dot_1.coordinate_y <<
         " to the point " << dot_2.coordinate_x << "," << dot_2.coordinate_y << endl;
        return true;
}
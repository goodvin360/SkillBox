#include <iostream>
#include "vector"
#include "cmath"

using namespace std;

struct vector_struct
{
    vector<double> x,y;
};

vector<double> add()
{
    double x1,y1,x2,y2;
    vector<double>res;
    cout << "Enter first vector coordinates (x1, y1):" << endl;
    cin >> x1 >> y1;
    cout << "Enter second vector coordinates (x2, y2):" << endl;
    cin >> x2 >> y2;

    res.push_back(x1+x2);
    res.push_back(y1+y2);
    return res;
}

vector<double> subtract()
{
    double x1,y1,x2,y2;
    vector<double>res;
    cout << "Enter first vector coordinates (x1, y1):" << endl;
    cin >> x1 >> y1;
    cout << "Enter second vector coordinates (x2, y2):" << endl;
    cin >> x2 >> y2;

    res.push_back(x1-x2);
    res.push_back(y1-y2);
    return res;
}

vector<double> scale()
{
    double x1,y1,k;
    vector<double>res;
    cout << "Enter first vector coordinates (x1, y1):" << endl;
    cin >> x1 >> y1;
    cout << "Enter scale factor (k):" << endl;
    cin >> k;

    res.push_back(x1*k);
    res.push_back(y1*k);
    return res;
}

double length()
{
    double x1,y1;
    cout << "Enter vector coordinates (x1, y1):" << endl;
    cin >> x1 >> y1;
    double res = sqrt(pow(x1,2)+pow(y1,2));
    return res;
}

vector<double> normalize()
{
    double x1,y1;
    vector<double>res;
    cout << "Enter vector coordinates (x1, y1):" << endl;
    cin >> x1 >> y1;
    double l = sqrt(pow(x1,2)+pow(y1,2));
    res.push_back(x1/l);
    res.push_back(y1/l);
    return res;
}

int main() {
    cout << "Task 3" << endl;

    string command;
    cout << "Enter command: 'add', 'subtract', 'scale', 'length', 'normalize': " <<endl;
    cin >> command;
    vector<double>res;

    if (command=="add")
    {
        res=add();
        cout << res[0] << " " << res[1] << endl;
    }
    else if (command=="subtract")
    {
        res=subtract();
        cout << res[0] << " " << res[1] << endl;
    }
    else if (command=="scale")
    {
        res=scale();
        cout << res[0] << " " << res[1] << endl;
    }
    else if (command=="length")
    {
        double res=length();
        cout << res << endl;
    }
    else if (command=="normalize")
    {
        res=normalize();
        cout << res[0] << " " << res[1] << endl;
    }

    return 0;
}

#include <iostream>
#include "vector"
#include "cmath"


struct vector_struct
{
    std::vector<double> x,y;
};

std::vector<double> add()
{
    double x1,y1,x2,y2;
    std::vector<double>res;
    std::cout << "Enter first vector coordinates (x1, y1):" << std::endl;
    std::cin >> x1 >> y1;
    std::cout << "Enter second vector coordinates (x2, y2):" << std::endl;
    std::cin >> x2 >> y2;

    res.push_back(x1+x2);
    res.push_back(y1+y2);
    return res;
}

std::vector<double> subtract()
{
    double x1,y1,x2,y2;
    std::vector<double>res;
    std::cout << "Enter first vector coordinates (x1, y1):" << std::endl;
    std::cin >> x1 >> y1;
    std::cout << "Enter second vector coordinates (x2, y2):" << std::endl;
    std::cin >> x2 >> y2;

    res.push_back(x1-x2);
    res.push_back(y1-y2);
    return res;
}

std::vector<double> scale()
{
    double x1,y1,k;
    std::vector<double>res;
    std::cout << "Enter first vector coordinates (x1, y1):" << std::endl;
    std::cin >> x1 >> y1;
    std::cout << "Enter scale factor (k):" << std::endl;
    std::cin >> k;

    res.push_back(x1*k);
    res.push_back(y1*k);
    return res;
}

double length()
{
    double x1,y1;
    std::cout << "Enter vector coordinates (x1, y1):" << std::endl;
    std::cin >> x1 >> y1;
    double res = sqrt(pow(x1,2)+pow(y1,2));
    return res;
}

std::vector<double> normalize()
{
    double x1,y1;
    std::vector<double>res;
    std::cout << "Enter vector coordinates (x1, y1):" << std::endl;
    std::cin >> x1 >> y1;
    double l = sqrt(pow(x1,2)+pow(y1,2));
    res.push_back(x1/l);
    res.push_back(y1/l);
    return res;
}

int main() {
    std::cout << "Task 3" << std::endl;

    std::string command;
    std::cout << "Enter command: 'add', 'subtract', 'scale', 'length', 'normalize': " << std::endl;
    std::cin >> command;
    std::vector<double>res;

    if (command=="add")
    {
        res=add();
        std::cout << res[0] << " " << res[1] << std::endl;
    }
    else if (command=="subtract")
    {
        res=subtract();
        std::cout << res[0] << " " << res[1] << std::endl;
    }
    else if (command=="scale")
    {
        res=scale();
        std::cout << res[0] << " " << res[1] << std::endl;
    }
    else if (command=="length")
    {
        double res=length();
        std::cout << res << std::endl;
    }
    else if (command=="normalize")
    {
        res=normalize();
        std::cout << res[0] << " " << res[1] << std::endl;
    }

    return 0;
}

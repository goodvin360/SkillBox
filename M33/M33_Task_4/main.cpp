#include <iostream>
#include "vector"
#include "random"

template<typename T>
T middleSum(std::vector<T> &v)
{
    T midS=0;
    int k=0;
    for (int i=0; i<v.size(); i++)
    {
        midS+=v[i];
        k++;
    }
    v.clear();
    return midS/k;
}

template<typename T>
void fillData(std::vector<T> &v)
{
    for (int i=0; i<5; i++)
    {
        T tmp;
        std::cout << "Enter " << i+1 << " value of the data array: " << std::endl;
        std::cin >> tmp;
        v.push_back((T)tmp);
    }
}

template<typename T>
void fillData(std::vector<T> &v, std::string flag)
{
    for (int i=0; i<5; i++)
    {
        v.push_back(rand()%10);
    }
}

template<typename T>
void showData(std::vector<T> &v)
{
    std::cout << "Your data array: " << std::endl;
    for (int i=0; i<v.size(); i++)
    {
        std::cout << v[i] << std::endl;
    }
    std::cout << std::endl;
}

int main() {
    std::cout << "Task 4" << std::endl;

    srand(time(nullptr));

//    std::vector<double> data{0, 2.5, 1, 1.8, 2.0};
//    std::vector<float> data{0.8, 25, 1.41, 4.8, 9};
//    std::vector<int> data{0, 5, 1, 3, 5};

    std::vector<int> data;

//    fillData(data);
    fillData(data, "rand"); // if you want to fill array with random values
    showData(data);
    std::cout << "Middle value of data array is: " << middleSum(data) << std::endl;

    return 0;
}

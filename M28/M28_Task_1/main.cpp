#include <iostream>
#include "thread"
#include "mutex"
#include "vector"
#include "map"


std::mutex thisMutex;

std::map<int,std::string>result;

void swimmer_dist(std::string name, double speed)
{
    int time = 1;
    double dist = speed;
    do
    {   std::this_thread::sleep_for(std::chrono::seconds(1));
        time++;
        thisMutex.lock();
        std::cout << name << " swam " << dist << " meters" << std::endl;
        dist=time*speed;
        thisMutex.unlock();
    }  while (dist<=100);
    thisMutex.lock();
        result.insert({time, name});
    thisMutex.unlock();
}

int main() {
    std::cout << "Task 1" << std::endl;

    std::vector<std::string> names;
    std::vector<double>speeds;
    for (int i=0; i<6;i++)
    {
        std::string name; double speed;
        std::cout << "Enter " << i+1 << " swimmer name and his speed in m/s:" << std::endl;
        std::cin >> name >> speed;
        names.push_back(name);
        speeds.push_back(speed);
    }

    std::thread swimmer1(swimmer_dist, names[0], speeds[0]);
    std::thread swimmer2(swimmer_dist, names[1], speeds[1]);
    std::thread swimmer3(swimmer_dist, names[2], speeds[2]);
    std::thread swimmer4(swimmer_dist, names[3], speeds[3]);
    std::thread swimmer5(swimmer_dist, names[4], speeds[4]);
    std::thread swimmer6(swimmer_dist, names[5], speeds[5]);

    std::this_thread::sleep_for(std::chrono::seconds(2));

    swimmer1.join();
    swimmer2.join();
    swimmer3.join();
    swimmer4.join();
    swimmer5.join();
    swimmer6.join();

    thisMutex.lock();
    for (auto it=result.begin(); it!=result.end(); it++)
        std::cout << "Swimmer name: " << it->second << '\t' << " and his finish time: "<< it->first << " s" << std::endl;
    thisMutex.unlock();

    return 0;
}

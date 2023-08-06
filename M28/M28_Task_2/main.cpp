#include <iostream>
#include "thread"
#include "mutex"
#include "vector"


std::mutex thisMutex;
std::mutex thisMutex2;
bool flag = false;
std::vector<std::string>trains;

void travel_time(int time, std::string name)
{
    std::string command;
    std::this_thread::sleep_for(std::chrono::seconds(time));

    if (flag)
    {
        std::cout << "Train " << name << " is arrived but wait for access to train station." << std::endl;
        thisMutex2.lock();
        trains.push_back(name);
        thisMutex2.unlock();
    }
    thisMutex.lock();
        flag = true;
    std::cout << "Train " << name << " is arrived" << std::endl;
        if(!trains.empty()) trains.erase(trains.begin());
    do
    {
        for (int i=0; i<trains.size();i++)
            std::cout << "Train " << trains[i] << " is arrived but wait for access to train station." << std::endl;
        std::cout << "Train " << name << " is waiting for 'depart' command" << std::endl;
        std::cin >> command;
    } while (command!="depart");
    thisMutex.unlock();
    flag = false;
}

int main() {
    std::cout << "Task 2" << std::endl;

    std::thread train1(travel_time,5,"A");
    std::thread train2(travel_time,10,"B");
    std::thread train3(travel_time,15,"C");

    train1.join();
    train2.join();
    train3.join();

    return 0;
}

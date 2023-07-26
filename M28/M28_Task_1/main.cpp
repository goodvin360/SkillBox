#include <iostream>
#include "thread"
#include "mutex"
#include "vector"
#include "map"

using namespace std;

mutex thisMutex;

map<int,string>result;

void swimmer_dist(string name, double speed)
{
    int time = 1;
    double dist = speed;
    do
    {   this_thread::sleep_for(chrono::seconds(1));
        time++;
        thisMutex.lock();
        cout << name << " swam " << dist << " meters" << endl;
        dist=time*speed;
        thisMutex.unlock();
    }  while (dist<=100);
    thisMutex.lock();
        result.insert({time, name});
    thisMutex.unlock();
}

int main() {
    cout << "Task 1" << endl;

    vector<string> names;
    vector<double>speeds;
    for (int i=0; i<6;i++)
    {
        string name; double speed;
        cout << "Enter " << i+1 << " swimmer name and his speed in m/s:" << endl;
        cin >> name >> speed;
        names.push_back(name);
        speeds.push_back(speed);
    }

    thread swimmer1(swimmer_dist, names[0], speeds[0]);
    thread swimmer2(swimmer_dist, names[1], speeds[1]);
    thread swimmer3(swimmer_dist, names[2], speeds[2]);
    thread swimmer4(swimmer_dist, names[3], speeds[3]);
    thread swimmer5(swimmer_dist, names[4], speeds[4]);
    thread swimmer6(swimmer_dist, names[5], speeds[5]);

    this_thread::sleep_for(chrono::seconds(2));

    swimmer1.join();
    swimmer2.join();
    swimmer3.join();
    swimmer4.join();
    swimmer5.join();
    swimmer6.join();

    thisMutex.lock();
    for (auto it=result.begin(); it!=result.end(); it++)
        cout << "Swimmer name: " << it->second << '\t' << " and his finish time: "<< it->first << " s" <<endl;
    thisMutex.unlock();

    return 0;
}

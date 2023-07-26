#include <iostream>
#include "thread"
#include "mutex"
#include "vector"

using namespace std;

mutex thisMutex;
mutex thisMutex2;
bool flag = false;
vector<string>trains;

void travel_time(int time, string name)
{
    string command;
    this_thread::sleep_for(chrono::seconds(time));

    if (flag)
    {
        cout << "Train " << name << " is arrived but wait for access to train station." << endl;
        thisMutex2.lock();
        trains.push_back(name);
        thisMutex2.unlock();
    }
    thisMutex.lock();
        flag = true;
        cout << "Train " << name << " is arrived" << endl;
        if(!trains.empty()) trains.erase(trains.begin());
    do
    {
        for (int i=0; i<trains.size();i++)
            cout << "Train " << trains[i] << " is arrived but wait for access to train station." << endl;
        cout << "Train " << name << " is waiting for 'depart' command" << endl;
        cin >> command;
    } while (command!="depart");
    thisMutex.unlock();
    flag = false;
}

int main() {
    cout << "Task 2" << endl;

    thread train1(travel_time,5,"A");
    thread train2(travel_time,10,"B");
    thread train3(travel_time,15,"C");

    train1.join();
    train2.join();
    train3.join();

    return 0;
}

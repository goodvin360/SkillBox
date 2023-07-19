#include <iostream>
#include "ctime"
#include "vector"
#include "iomanip"

using namespace std;

void task_start(vector<string> &v1, string &task, time_t &start)
{
    cout << "Enter task name: " << endl;
    getline(cin, task);
    start=time(nullptr);
    v1.push_back(task);
}

void task_stop(vector<double> &v2, string &task, time_t &start, time_t &stop)
{
    double diff;
    task.clear();
    stop = time(nullptr);
    diff = difftime(stop,start);
    v2.push_back(diff);
}


int main() {
    cout << "Task 1" << endl;

    string command{}, task{};
    vector<string> task_list;
    vector<double> duration;
    time_t start, stop;

    do {
        cout << "Enter your command ('begin', 'end' or 'exit'): " << endl;

        getline(cin, command);

        if (command == "begin")
        {
            if (task.length()!=0)
            {
                task_stop(duration,task,start,stop);
                task_start(task_list,task,start);
            }
            else if (task.length()==0)
            {
                task_start(task_list,task,start);
            }
        }
        else if (command=="end")
        {
            if (task.length()!=0)
            {
                task_stop(duration,task,start,stop);
            }
        }
        else if (command=="status")
        {
            int k=0;
            if (task.length()!=0)
                k = task_list.size()-1;
            else k = task_list.size();

            for (int i=0; i<k; i++)
            {
                cout << "Task name: " << task_list[i] << ", and task duration in hours: " << setprecision(4) << fixed << duration[i]/3600 << endl;
            }
            if (task.length()!=0)
            {
                cout << "Current task name is: " << task << endl;
            }
        }

    } while (command!="exit");

    return 0;
}

#include <iostream>
#include "ctime"
#include "vector"
#include "iomanip"


void task_start(std::vector<std::string> &v1, std::string &task, time_t &start)
{
    std::cout << "Enter task name: " << std::endl;
    std::getline(std::cin, task);
    start=time(nullptr);
    v1.push_back(task);
}

void task_stop(std::vector<double> &v2, std::string &task, time_t &start, time_t &stop)
{
    double diff;
    task.clear();
    stop = time(nullptr);
    diff = difftime(stop,start);
    v2.push_back(diff);
}


int main() {
    std::cout << "Task 1" << std::endl;

    std::string command{}, task{};
    std::vector<std::string> task_list;
    std::vector<double> duration;
    time_t start, stop;

    do {
        std::cout << "Enter your command ('begin', 'end' or 'exit'): " << std::endl;

        std::getline(std::cin, command);

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
                std::cout << "Task name: " << task_list[i] << ", and task duration in hours: " << std::setprecision(4) << std::fixed << duration[i]/3600 << std::endl;
            }
            if (task.length()!=0)
            {
                std::cout << "Current task name is: " << task << std::endl;
            }
        }

    } while (command!="exit");

    return 0;
}

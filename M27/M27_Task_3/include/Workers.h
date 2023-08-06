#ifndef M27_TASK_3_WORKERS_H
#define M27_TASK_3_WORKERS_H

#pragma once
#include "vector"
#include "iostream"
#include "sstream"
#include "random"


class Workers
{
    Workers*mids = nullptr;
    std::vector<Workers*> teams;
    int numOfWorkers = 0;
    bool isNotBusy = true;
    std::string task = "none";
    int mission=0;
    int workerID;
    int numOfBusyWorkers=0;
    std::string workerName;
    std::vector<std::string> tasks = {"A","B","C"};

public:
    void infill();
    void missionDist();
    void tasksDist();
    void numOfBusy();
    void showTeams();
    bool checkTeamsIsFullBusy();
};

#endif //M27_TASK_3_WORKERS_H

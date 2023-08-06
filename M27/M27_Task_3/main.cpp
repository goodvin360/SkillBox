#include <iostream>
#include "Workers.h"


int main() {
    std::cout << "Task 3" << std::endl;

    Workers*teams = new Workers;

    teams->infill();
    while(!teams->checkTeamsIsFullBusy())
    {
        teams->missionDist();
        teams->tasksDist();
        teams->showTeams();
    }

    return 0;
}

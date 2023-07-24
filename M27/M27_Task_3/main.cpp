#include <iostream>
#include "Workers.h"

using namespace std;


int main() {
    cout << "Task 3" << endl;

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

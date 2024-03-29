#include "Workers.h"

void Workers::infill()
{
    int numOfTeams = 0;
    std::cout << "Enter num of teams: " << std::endl;
    std::cin >> numOfTeams;
    for (int i=1; i<=numOfTeams; i++)
    {
        Workers*midWorker = new Workers;
        midWorker->mids = this;
        std::stringstream workerTempName;
        workerTempName << i;
        midWorker->workerName=workerTempName.str();
        midWorker->workerID=stoi(midWorker->workerName);
        std::cout << "Enter num of workers in " << i << " team:" << std::endl;
        std::cin >> numOfWorkers;
        for (int j=1; j<=numOfWorkers; j++)
        {
            Workers*junWorker = new Workers;
            junWorker->mids=midWorker;
            std::stringstream workerTempName;
            workerTempName << i << j;
            junWorker->workerName=workerTempName.str();
            junWorker->workerID=stoi(junWorker->workerName);
            midWorker->teams.push_back(junWorker);
        }
        teams.push_back(midWorker);
    }
}

void Workers::missionDist()
{
    for (int i=0; i<teams.size(); i++)
    {
        numOfBusy();
        if (teams[i]->numOfBusyWorkers!=teams[i]->teams.size())
        {
            int last_mission=teams[i]->mission;
            int mission_value=0;
            do
            {
                std::cout << "Enter mission value for " << i+1 << " team:" << std::endl;
                std::cin >> mission_value;
                if (mission_value==last_mission) std::cout << "This mission have been used. Enter another one." << std::endl;
                else if(mission_value!=last_mission) teams[i]->mission=mission_value;
            } while(last_mission==mission_value);
        }
    }
}

void Workers::tasksDist()
{
    for (int i=0; i<teams.size(); i++)
    {
        srand(teams[i]->workerID+teams[i]->mission);
        numOfBusy();
        int tmp = rand()%teams[i]->teams.size()-teams[i]->numOfBusyWorkers+1;
        int cnt=0;
        for (int j=0; j<teams[i]->teams.size(); j++)
        {

            if (teams[i]->teams[j]->isNotBusy)
            {
                teams[i]->teams[j]->task=tasks.at(rand()%3);
                teams[i]->teams[j]->isNotBusy=false;
                cnt++;
            }
            if(cnt==tmp) break;
        }
    }
}

void Workers::numOfBusy()
{
    int counter=0;
    for (int i=0; i<teams.size(); i++)
    {
        for (int j=0; j<teams[i]->teams.size(); j++)
        {
            if(!(teams[i]->teams[j]->isNotBusy)) counter++;
        }
        teams[i]->numOfBusyWorkers=counter;
        counter=0;
    }
}

bool Workers::checkTeamsIsFullBusy()
{
    int counter=0;
    for (int i=0; i<teams.size(); i++)
    {
        for (int j=0; j<teams[i]->teams.size(); j++)
        {
            if(teams[i]->teams[j]->isNotBusy) counter++;
        }
    }
    if (counter!=0) return false;
    else return true;
}

void Workers::showTeams()
{
    for (int i=0; i<teams.size(); i++)
    {
        std::cout << "Middle worker ID: " << teams[i]->workerID <<
             ", his mission: " << teams[i]->mission << std::endl;
        for (int j=0; j<teams[i]->teams.size(); j++)
        {
            std::cout << "Junior worker ID: " << teams[i]->teams[j]->workerID <<
                 ", his task is: " << teams[i]->teams[j]->task << std::endl;
        }
    }
}
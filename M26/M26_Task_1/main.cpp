#include <iostream>
#include "Player.h"
#include "Track.h"
#include "sstream"
#include "random"


int main() {
    std::cout << "Task 1" << std::endl;
    srand(time(nullptr));

    Player*pl = new Player;

    for (int i=0; i<5; i++)
    {
        std::stringstream track_name;
        track_name << "track_no_" << i;
        time_t t = time(nullptr);
        tm date = *localtime(&t);
        pl->Infill(track_name.str(), date, rand()%100);
    }

    std::cout << "This is your playlist: " << std::endl;
    pl->ShowPlaylist();

    std::string command;
    while (command!="exit")
    {
        std::cout << "Enter one of the next command: 'play', 'pause', 'next', 'stop', exit'" << std::endl;
        std::cin>>command;

        if (command=="play")
            pl->Play();
        else if (command=="pause")
            pl->Pause();
        else if (command=="next")
            pl->Next();
        else if (command=="stop")
            pl->Stop();
        else if (command=="exit")
            std::cout << "Good bye! :) " << std::endl;
    }

    delete pl;
    return 0;
}

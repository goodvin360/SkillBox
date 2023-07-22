#include <iostream>
#include "Player.h"
#include "Track.h"
#include "sstream"
#include "random"

using namespace std;


int main() {
    cout << "Task 1" << endl;
    srand(time(nullptr));

    Player*pl = new Player;

    for (int i=0; i<5; i++)
    {
        stringstream track_name;
        track_name << "track_no_" << i;
        time_t t = time(nullptr);
        tm date = *localtime(&t);
        pl->Infill(track_name.str(), date, rand()%100);
    }

    cout << "This is your playlist: " << endl;
    pl->ShowPlaylist();

    string command;
    while (command!="exit")
    {
        cout << "Enter one of the next command: 'play', 'pause', 'next', 'stop', exit'" << endl;
        cin>>command;

        if (command=="play")
            pl->Play();
        else if (command=="pause")
            pl->Pause();
        else if (command=="next")
            pl->Next();
        else if (command=="stop")
            pl->Stop();
        else if (command=="exit")
            cout << "Good bye! :) " << endl;
    }

    delete pl;
    return 0;
}

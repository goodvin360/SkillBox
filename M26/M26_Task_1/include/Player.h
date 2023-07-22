#ifndef M26_TASK_1_PLAYER_H
#define M26_TASK_1_PLAYER_H

#pragma once
#include "vector"
#include "Track.h"

using namespace std;

class Player
{
    vector <class Track> playlist;
    Track*track = new Track;

    string status;

public:
    void Play();
    void Pause();
    void Next();
    void Stop();
    void Infill(string name, tm date, int duration);
    void ShowPlaylist();
    void ShowInfo(int track_num);

};

#endif //M26_TASK_1_PLAYER_H

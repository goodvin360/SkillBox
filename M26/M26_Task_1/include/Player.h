#ifndef M26_TASK_1_PLAYER_H
#define M26_TASK_1_PLAYER_H

#pragma once
#include "vector"
#include "Track.h"


class Player
{
    std::vector <class Track> playlist;
    Track*track = new Track;

    std::string status;

public:
    void Play();
    void Pause();
    void Next();
    void Stop();
    void Infill(std::string name, tm date, int duration);
    void ShowPlaylist();
    void ShowInfo(int track_num);

};

#endif //M26_TASK_1_PLAYER_H

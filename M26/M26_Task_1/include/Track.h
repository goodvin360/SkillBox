#ifndef M26_TASK_1_TRACK_H
#define M26_TASK_1_TRACK_H

#pragma once
#include "ctime"
#include "string"

using namespace std;

class Track
{
    string trackName;
    tm trackDate;
    int trackDuration;

public:
    void setTrackData(string name, tm date, int duration);
    void ShowTrackInfo();
    string getName();
};

#endif //M26_TASK_1_TRACK_H

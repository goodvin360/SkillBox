#ifndef M26_TASK_1_TRACK_H
#define M26_TASK_1_TRACK_H

#pragma once
#include "ctime"
#include "string"


class Track
{
    std::string trackName;
    tm trackDate;
    int trackDuration;

public:
    void setTrackData(std::string name, tm date, int duration);
    void ShowTrackInfo();
    std::string getName();
};

#endif //M26_TASK_1_TRACK_H

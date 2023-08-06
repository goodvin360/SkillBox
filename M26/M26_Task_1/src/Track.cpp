#include "Track.h"
#include "iostream"
#include "iomanip"

void Track::setTrackData(std::string name, tm date, int duration)
{
    trackDuration = duration;
    trackDate = date;
    trackName = name;
}

void Track::ShowTrackInfo()
{
    std::cout << "Track name: " << trackName << ", " << "Track date: " << std::put_time(&trackDate, "%Y/%m/%d") << ", " << " track duration: " << trackDuration << " s" << std::endl;
}

std::string Track::getName()
{
    return trackName;
}
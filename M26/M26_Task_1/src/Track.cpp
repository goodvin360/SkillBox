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
    cout << "Track name: " << trackName << ", " << "Track date: " << put_time(&trackDate, "%Y/%m/%d") << ", " << " track duration: " << trackDuration << " s" << endl;
}

string Track::getName()
{
    return trackName;
}
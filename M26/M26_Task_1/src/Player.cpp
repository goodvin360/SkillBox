#include "Player.h"
#include "iostream"

void Player::Infill(string name, tm date, int duration)
{
    track->setTrackData(name, date, duration);
    playlist.push_back(*track);
};

void Player::ShowPlaylist()
{
    for (int i=0; i<playlist.size(); i++)
    {
        track = &playlist[i];
        track->ShowTrackInfo();
    }
}

void Player::ShowInfo(int track_num)
{
    track = &playlist[track_num];
    track->ShowTrackInfo();
}

void Player::Play()
{
    if (status!="playing")
    {
        string name;
        vector<string>track_names;
        bool check = false;
        cout << "Enter track name you want to play:" << endl;
        cin >> name;
        for (int i=0; i<playlist.size(); i++)
        {
            track = &playlist[i];
            track_names.push_back(track->getName());
            if (name==track->getName())
            {ShowInfo(i);
                check = true;}
            if (!check && i==playlist.size()-1)
            {cout << "There is no track with this name." << endl;
                return;}
        }

    }
    status = "playing";
}

void Player::Pause()
{
    if (status=="playing")
        cout << "Track on pause!" << endl;
    status = "on pause";
}

void Player::Next()
{
    int i = rand()%5;
    track = &playlist[i];
    ShowInfo(i);
    status = "playing";
}

void Player::Stop()
{
    if (status=="playing")
        cout << "Playing is stopped." << endl;
    status="stopped";
}
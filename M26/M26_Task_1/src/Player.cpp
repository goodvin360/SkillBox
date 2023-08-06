#include "Player.h"
#include "iostream"

void Player::Infill(std::string name, tm date, int duration)
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
        std::string name;
        std::vector<std::string>track_names;
        bool check = false;
        std::cout << "Enter track name you want to play:" << std::endl;
        std::cin >> name;
        for (int i=0; i<playlist.size(); i++)
        {
            track = &playlist[i];
            track_names.push_back(track->getName());
            if (name==track->getName())
            {ShowInfo(i);
                check = true;}
            if (!check && i==playlist.size()-1)
            {std::cout << "There is no track with this name." << std::endl;
                return;}
        }

    }
    status = "playing";
}

void Player::Pause()
{
    if (status=="playing")
        std::cout << "Track on pause!" << std::endl;
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
        std::cout << "Playing is stopped." << std::endl;
    status="stopped";
}
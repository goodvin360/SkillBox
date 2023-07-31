#include <iostream>
#include "fstream"
#include "map"
#include "vector"
#include "sstream"
#include "random"
#include "ctime"
#include "windows.h"
#include "nlohmann/json.hpp"

struct Record
{
    std::string title;
    std::string country;
    int year;
    std::string production;
    std::string script;
    std::string director;
    std::string producer;
    std::map<std::string, std::string> actors;
};

void fillLibData(std::vector<Record> &records)
{
    Record record;
    for (int i=0; i<5; i++)
    {
        std::stringstream tmp1;
        tmp1 << "film " << i+1;
        record.title = tmp1.str();
        record.country = "England";
        record.year = 1984;
        record.production = "20 century fox";
        record.script = "Chuck Palahniuk";
        record.director = "David Fincher";
        record.producer = "Harvi Vainstein";
        for (int j=0; j<4; j++)
        {
            std::stringstream tmp2, tmp3;
            int var = rand()%4+1;
            tmp2 << "role number " << j+1;
            tmp3 << "actor number " << var;
            record.actors.insert({tmp2.str(), tmp3.str()}); // one actor really could play all roles in the movie :)
        }
        records.push_back(record);
        record.actors.clear();
    }
}

void fillJsonData(std::map<std::string,nlohmann::json> &movieLibData, std::vector<Record> &records)
{
    for (int i=0; i<5; i++)
    {
        nlohmann::json dict;
        dict["title"] = records[i].title;
        dict["country"] = records[i].country;
        dict["year"] = records[i].year;
        dict["production"] = records[i].production;
        dict["script"] = records[i].script;
        dict["director"] = records[i].director;
        dict["producer"] = records[i].producer;
        dict["actors"] = records[i].actors;
        movieLibData.insert({records[i].title, dict});
    }
}

void fileWrite(nlohmann::json &lib)
{
    std::ofstream file("library.json", std::ios::out);
    file << lib;
    file.close();
}

void searchActor()
{
    std::ifstream fileRead("library.json");
    nlohmann::json libRead;
    fileRead >> libRead;
    std::cout << "Enter actor name:" << std::endl;
    std::string actor_name;
//    actor_name = "actor number 2";
    std::getline(std::cin,actor_name);

    for (auto it = libRead.begin().value().begin(); it!= libRead.begin().value().end(); it++)
    {
        for (auto it2 = it.value().begin().value().begin(); it2!= it.value().begin().value().end(); it2++)
        {
            if (it2.value()==actor_name)
            {
                std::cout << it.key() << std::endl;
                std::cout << it2.key() << std::endl;
            }
        }
    }
}

int main() {
    std::cout << "Task 2" << std::endl;

    std::vector<Record> records;
    std::map<std::string,nlohmann::json> movieLibData;

    fillLibData(records);
    fillJsonData(movieLibData, records);

    nlohmann::json lib;
    lib["movie library"] = movieLibData;
    fileWrite(lib);
    searchActor();

    return 0;
}

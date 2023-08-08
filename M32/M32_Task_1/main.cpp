#include <iostream>
#include "fstream"
    #include "nlohmann/json.hpp"
#include "map"

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

int main() {
    std::cout << "Task 1" << std::endl;

    Record record;
    /*std::cout << "Enter title, country, year and production of the film:" << std::endl;
    std::cin >> record.title >> record.country >> record.year >> record.production;
    std::cout << "Enter script author, director and producer of the film:" << std::endl;
    std::cin >> record.script >> record.director >> record.producer;*/

    record.title = "film1";
    record.country = "England";
    record.year = 1984;
    record.production = "20 century fox";
    record.script = "Chuck Palahniuk";
    record.director = "David Fincher";
    record.producer = "harvi Vainstein";
    record.actors.insert({"role number 1", "actor number 1"});
    record.actors.insert({"role number 2", "actor number 2"});
    record.actors.insert({"role number 3", "actor number 3"});
    record.actors.insert({"role number 4", "actor number 4"});


    std::ofstream file("../record.json", std::ios::out);
    nlohmann::json dict;
    dict["title"] = record.title;
    dict["country"] = record.country;
    dict["year"] = record.year;
    dict["production"] = record.production;
    dict["script"] = record.script;
    dict["director"] = record.director;
    dict["producer"] = record.producer;
    dict["actors"] = record.actors;
    file << std::setw(4) << dict << std::endl;

    return 0;
}

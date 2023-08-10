#ifndef FINALPROJECT_CONVERTERJSON_H
#define FINALPROJECT_CONVERTERJSON_H

#pragma once
#include "nlohmann/json.hpp"
#include "vector"
#include "fstream"
#include "iostream"
#include "string"
#include "sstream"
#include "map"
#include "mutex"

struct Answer
{
    std::string requestNum;
    std::map<int, double> result;
    bool flag;
};

class ConverterJson
{
public:
    ConverterJson()
    {
        std::ifstream configRead("../config.json");
        if(!configRead.is_open())
        {
            std::cerr << "Error while opening file config.json."<<std::endl;
            std::terminate();
            //to do exception throw
        }
        configRead >> configFile;
        configRead.close();

        std::ifstream requestRead("../request.json");
        requestRead >> requestFile;
        requestRead.close();
    };

    std::vector<std::string> GetTextDocuments();
    int GetFilesNum();
    int GetResponseLimit();
    std::vector<std::string> GetRequests();
    void putAnswers(std::vector<std::vector<std::pair<int, float>>> answers);
    const std::vector<std::string> GetRequestsData();


private:
    int numOfFiles=0;
    int respLimit=0;
    std::vector<std::string> textFromDocs{};
    std::vector<std::string> requests{};
    std::vector<std::string> filePaths;

    nlohmann::json configFile;
    nlohmann::json requestFile;
    nlohmann::json answerFile;
    Answer ans;
};

#endif //FINALPROJECT_CONVERTERJSON_H

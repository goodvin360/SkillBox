#ifndef FINALPROJECT_SEARCHSERVER_H
#define FINALPROJECT_SEARCHSERVER_H

#pragma once
#include "vector"
#include "iostream"
#include "map"
#include "InvertedIndex.h"

struct RelativeIndex
{
    size_t doc_id;
    double rank;
};

class SearchServer
{
public:
    SearchServer(InvertedIndex& inIdx): index(inIdx) {};

    std::vector<std::vector<std::pair<int, float>>> searchFoo (const std::vector<std::string> &queries_input);
    void testFoo();

private:
    InvertedIndex index;
    std::map<std::string,int> uniqRequests;
    std::multimap<int,int> preRelevance;
    std::vector<std::vector<std::pair<int, float>>> result;
    std::vector<std::pair<int, float>> relativeIndex;

};

#endif //FINALPROJECT_SEARCHSERVER_H

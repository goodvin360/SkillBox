#include "SearchServer.h"

std::vector<std::vector<std::pair<int, float>>> SearchServer::searchFoo(const std::vector<std::string> &queries_input)
{
    for (int i=0; i<queries_input.size(); i++)
    {
        uniqRequestsFill(queries_input[i]);
        preRelevanceFill();
        maxAbsRelevance = findMaxAbsRel();
        result.push_back(sortRelativeIndex());
    }
    return result;
}

void SearchServer::uniqRequestsFill(const std::string& request)
{
    uniqRequests.clear();
    int i=0;
    std::string test;
    while (request[i])
    {
        if (request[i]!=' ' && request[i]!='\0')
        {
            test.push_back(request[i]);
        }
        if ((request[i]==' ' || request[i+1]=='\0') && test.size()!=0)
        {
            uniqRequests.insert({test,0});
            test.clear();
        }
        i++;
    }
}

void SearchServer::preRelevanceFill()
{
    preRelevance.clear();
    for (int i=0; i<dataJson.GetFilesNum(); i++)
    {
        int absRelevance=0;
        for (auto it:uniqRequests)
        {
            auto it2 = index.getFreqDictionary()->find(it.first);
            if (it2!=index.getFreqDictionary()->end())
            {
                for (int j=0; j<it2->second.size(); j++)
                {
                    if(it2->second[j].doc_id==i)
                    {
                        absRelevance+=it2->second[j].count;
                    }
                }
            }
        }
        preRelevance.insert({i,absRelevance});
    }
}

int SearchServer::findMaxAbsRel()
{
    for (auto it=preRelevance.begin(); it!=preRelevance.end(); it++)
    {
        if (it->second > maxAbsRelevance)
        {
            maxAbsRelevance = it->second;
        }
    }
    return maxAbsRelevance;
}

std::vector<std::pair<int, float>> SearchServer::sortRelativeIndex()
{
    int counter=0;
    relativeIndex.clear();

    std::multimap<int, int> reverseMyMap;
    for (auto it : preRelevance)
    {
        reverseMyMap.insert({it.second,it.first});
    }

    for (auto it=reverseMyMap.rbegin(); it!=reverseMyMap.rend(); it++)
    {
        std::pair<int,float> tempIndex;
        tempIndex.first = it->second;
        if (maxAbsRelevance!=0)
            tempIndex.second = floorf(100*(float)(it->first)/maxAbsRelevance)/100;
        else tempIndex.second = 0;
        if (tempIndex.second>0)
        {
            relativeIndex.push_back(tempIndex);
        }
    }

    std::vector<std::pair<int, float>> relativeIndexTemp1;
    std::vector<std::pair<int, float>> relativeIndexTemp2;

    for (int i=0; i<relativeIndex.size();i++)
    {
        while (relativeIndex[i].second==relativeIndex[i+1].second)
        {
            relativeIndexTemp1.push_back(relativeIndex[i]);
            i++;
        }
        relativeIndexTemp1.push_back(relativeIndex[i]);
        std::sort(relativeIndexTemp1.begin(), relativeIndexTemp1.end());
        for (auto it:relativeIndexTemp1)
        {
            if (counter<dataJson.GetResponseLimit())
            {
                relativeIndexTemp2.push_back(it);
                counter++;
            }
        }
        relativeIndexTemp1.clear();
    }

    return relativeIndexTemp2;
}

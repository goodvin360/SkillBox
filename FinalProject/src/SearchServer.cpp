#include "SearchServer.h"

std::vector<std::vector<std::pair<int, float>>> SearchServer::searchFoo(const std::vector<std::string> &queries_input)
{
    /*for (auto it=index.freq_dictionary.begin();it!=index.freq_dictionary.end();it++)
        {
            std::cout << it->first << std::endl;
            for (int i=0; i<it->second.size();i++)
            {
                std::cout << it->second[i].doc_id << " " << it->second[i].count << std::endl;
            }
            std::cout << std::endl;
        }*/

    for (int i=0; i<queries_input.size(); i++)
    {
        int j=0;
        std::string test;
        while (queries_input[i][j])
        {
            if (queries_input[i][j]!=' ' && queries_input[i][j]!='\0')
            {
                test.push_back(queries_input[i][j]);
            }
            if ((queries_input[i][j]==' ' || queries_input[i][j+1]=='\0') && test.size()!=0)
            {
/*                std::cout << test << '\t';
                std::cout << std::endl;*/
                uniqRequests.insert({test,0});
                test.clear();
            }
            j++;
        }

        for (int m=0; m<3; m++)
        {
            int absRelevance=0;
            for (auto it=uniqRequests.begin(); it!=uniqRequests.end();it++)
            {
                auto it2 = index.freq_dictionary.find(it->first);
                if (it2!=index.freq_dictionary.end())
                {
                    for (int k=0; k<it2->second.size(); k++)
                    {
                        if(it2->second[k].doc_id==m)
                        {
                            absRelevance+=it2->second[k].count;
                        }
                    }
                }
            }
            preRelevance.insert({m,absRelevance});
        }
        /*std::cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << std::endl;

        for (auto it=preRelevance.begin();it!=preRelevance.end();it++)
        {
            std::cout << it->first << " " << it->second << std::endl;
        }*/

        int maxAbsRelevance = 0;
        for (auto it=preRelevance.begin(); it!=preRelevance.end(); it++)
        {
            if (it->second > maxAbsRelevance)
            {
                maxAbsRelevance = it->second;
            }
        }

//        std::cout << "current max abs relevance: " << maxAbsRelevance << std::endl;

        for (auto it=preRelevance.begin(); it!=preRelevance.end(); it++)
        {
            std::pair<int,float> tempIndex;
            tempIndex.first = it->first;
            if (maxAbsRelevance!=0)
                tempIndex.second = floorf(100*(float)(it->second)/maxAbsRelevance)/100;
            else tempIndex.second = 0;
//            if (tempIndex.second!=0)
                relativeIndex.push_back(tempIndex);
        }



//        std::cout << relativeIndex.size() << std::endl;

        result.push_back(relativeIndex);
        uniqRequests.clear();
        preRelevance.clear();
        relativeIndex.clear();
    }

//    std::cout << "end of search: " << std::endl;

//    std::cout << result.size() << std::endl;

    for (int i=0; i<result.size(); i++)
    {
        std::cout << "request num " << i+1 << std::endl;
        for (int j=0; j<result[i].size(); j++)
        {
            std::cout << result[i][j].first << " " << result[i][j].second << std::endl;
        }
        std::cout << std::endl;
    }

    return result;
}

void SearchServer::testFoo()
{
    for (auto it=index.freq_dictionary.begin();it!=index.freq_dictionary.end();it++)
    {
        std::cout << it->first << std::endl;
        for (int i=0; i<it->second.size();i++)
        {
            std::cout << it->second[i].doc_id << " " << it->second[i].count << std::endl;
        }
        std::cout << std::endl;
    }
}

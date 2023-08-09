#include "ConverterJson.h"

std::vector<std::string> ConverterJson::GetTextDocuments()
{
    for (auto it = configFile.begin(); it!= configFile.end(); it++)
    {
        if (it.key()=="files")
        {
            for (auto it2 = it.value().begin(); it2!= it.value().end(); it2++)
            {
                filePaths.push_back(it2.value());
//                std::cout << it2.value() << std::endl;
            }
        }
    }

    for (auto it : filePaths)
    {
        std::ifstream file(it);
        std::string tmp1{},tmp2{};
        while (!file.eof()) {
            file >> tmp1;
            tmp2+=(" "+tmp1);
        }
        textFromDocs.push_back(tmp2);
    }

/*    for (auto it2:textFromDocs)
    {
        std::cout << it2 << std::endl;
        std::cout << std::endl;
    }*/

    return textFromDocs;
}

int ConverterJson::GetResponseLimit()
{
    for (auto it = configFile.begin(); it!= configFile.end(); it++)
    {
        if (it.key()=="config")
        {
            for (auto it2 = it.value().begin(); it2!= it.value().end(); it2++)
            {
                if (it2.key()=="max_responses")
                {
                    std::string tmp{};
                    tmp = it2.value();
                    respLimit = std::stoi(tmp);
                }
            }
        }
    }
    return respLimit;
}

std::vector<std::string> ConverterJson::GetRequests()
{
    for (auto it = requestFile.begin().value().begin(); it!= requestFile.begin().value().end(); it++)
    {
        requests.push_back(it.value());
//                std::cout << it.value() << std::endl;
    }
/*    for (auto it2:requests)
    {
        std::cout << it2 << std::endl;
        std::cout << std::endl;
    }*/
    return requests;
}

void ConverterJson::putAnswers(std::vector<std::vector<std::pair<int, float>>> answers)
{
    std::ofstream file("../answers.json", std::ios::out);
    file.precision(4);
    std::map<std::string,nlohmann::json> outerLayer;
    std::multimap<std::pair<std::string,int>,std::pair<std::string,float>> data;
    std::vector<std::pair<std::pair<std::string,int>,std::pair<std::string,float>>> vecData;
    for (int i=0; i<answers.size(); i++)
    {
        float var=0;
        for (int j=0; j<answers[i].size();j++)
        {
            var+=answers[i][j].second;
        }
        std::cout << var << std::endl;
        if (var>0)
            ans.flag = true;
        else ans.flag = false;

        nlohmann::json tmp;
        tmp[" result"] = ans.flag;

        if (ans.flag)
        {
            nlohmann::json tmp2;
            for (int j = 0; j < answers[i].size(); j++)
            {
                if (answers[i][j].second>0)
                {
                    constexpr auto max_digits10 = std::numeric_limits<decltype(answers[i][j].second)>::max_digits10;
                    std::setprecision(max_digits10);
                    std::pair<std::string, int> pair1;
                    std::pair<std::string, float> pair2;
                    pair1.first = "docID";
                    pair1.second = answers[i][j].first;
                    pair2.first = "rank";
                    pair2.second = answers[i][j].second;
                    data.insert(std::make_pair(pair1, pair2));
                    vecData.push_back(std::make_pair(pair1, pair2));

                    tmp2["docID"] = answers[i][j].first;
                    tmp2["rank"] = answers[i][j].second;
                }
            }

            tmp["relevance"] = vecData;
            data.clear();
            tmp2.clear();
            vecData.clear();
        }

        std::stringstream request;
        request << "request00" << i+1;
        outerLayer.insert({request.str(),tmp});
    }
    answerFile["answers"] = outerLayer;
    file.precision(4);
    file << std::setw(4) << answerFile << std::endl;

}

const std::vector<std::string> ConverterJson::GetRequestsData()
{
    return requests;
}

int ConverterJson::GetFilesNum() {
    return textFromDocs.size();
}

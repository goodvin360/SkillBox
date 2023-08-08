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

}

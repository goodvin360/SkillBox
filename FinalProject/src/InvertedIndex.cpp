#include "InvertedIndex.h"


std::mutex myMutex;

void InvertedIndex::UpdateDocumentBase(std::vector<std::string> input_docs)
{
    docs = input_docs;
/*        for (auto it2:docs)
    {
        std::cout << it2 << std::endl;
        std::cout << std::endl;
    }
    */
}

std::vector<Entry> InvertedIndex::GetWordCount(const std::string &word)
{
    std::vector<Entry> wordData{};
    for (int i=0; i<docs.size(); i++)
    {
        Entry temp;
        temp.doc_id = i;
        temp.count=0;

        int j=0;
        std::string test;
        while (docs[i][j])
        {
            if (docs[i][j]!=' '|| docs[i][j+1]=='\0')
            {
                test.push_back(docs[i][j]);
            }
            if (docs[i][j]==' '|| docs[i][j+1]=='\0')
            {
                if (std::strcmp(word.c_str(),test.c_str())==0)
                    temp.count++;
                test.clear();
            }
            j++;
        }
        if (temp.count!=0)
            wordData.push_back(temp);
    }
    return wordData;
}

void InvertedIndex::freqDictInfillThread(std::string &textFromDoc)
{
/*    myMutex.lock();
    std::cout << "This is thread number: " << std::this_thread::get_id() << std::endl;
    myMutex.unlock();*/
        int i=0;
        std::string test;
        while (textFromDoc[i])
        {
            if (textFromDoc[i]!=' ' && textFromDoc[i]!='\0')
            {
                test.push_back(textFromDoc[i]);
            }
            if ((textFromDoc[i]==' ' || textFromDoc[i+1]=='\0') && test.size()!=0)
            {
                freq_dictionary.insert({test, GetWordCount(test)});
                /*std::cout << test << '\t';
                std::cout << std::endl;*/
                test.clear();
            }
            i++;
        }
}

void InvertedIndex::dataMerge()
{
    for (auto it:classParts)
    {
        for (auto it2 = it.freq_dictionary.begin(); it2!=it.freq_dictionary.end(); it2++)
        {
//            std::cout << it2->first << std::endl;
            freq_dictionary.insert({it2->first,it2->second});
        }
    }
}

std::map<std::string, std::vector<Entry>> *InvertedIndex::getFreqDictionary()
{
    return &freq_dictionary;
}

void InvertedIndex::threadsDistribution()
{
    for (auto it:docs)
    {
        InvertedIndex tempPart(jsonData);
        tempPart.UpdateDocumentBase(docs);
        classParts.push_back(tempPart);
    }

#ifdef SingleThread
    for (int i = 0; i < classParts.size(); i++)
    {
        classParts[i].freqDictInfillThread(docs[i]);
    }
#endif

#ifdef MultiThread
    std::vector<std::thread> ThreadVector;
    for (int i = 0; i < classParts.size(); i++) {
        ThreadVector.emplace_back([&, i]() {
            classParts[i].freqDictInfillThread(docs[i]);
        });
    }

    for(auto& t: ThreadVector)
    {
        t.join();
    }
#endif

    dataMerge();
}





#include "InvertedIndex.h"

/*void InvertedIndex::UpdateDocumentBase(std::vector<std::string> input_docs)
{
    docs = input_docs;
}*/

void InvertedIndex::UpdateDocumentBase()
{
    docs = jsonData.GetTextDocuments();
/*    for (auto it2:docs)
    {
        std::cout << it2 << std::endl;
        std::cout << std::endl;
    }*/
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
/*    for (auto it:wordData)
        std::cout << it.doc_id << '\t' << it.count << std::endl;*/
    return wordData;
}

void InvertedIndex::freqDictionaryInfill()
{
    for (int i=0; i<docs.size(); i++)
    {
        int j=0;
        std::string test;
        while (docs[i][j])
        {
            if (docs[i][j]!=' ' && docs[i][j]!='\0')
            {
                test.push_back(docs[i][j]);
            }
            if ((docs[i][j]==' ' || docs[i][j+1]=='\0') && test.size()!=0)
            {
                freq_dictionary.insert({test, GetWordCount(test)});
                /*std::cout << test << '\t';
                std::cout << std::endl;*/
                test.clear();
            }
            j++;
        }
    }

/*    for (auto it=freq_dictionary.begin();it!=freq_dictionary.end();it++)
    {
        std::cout << it->first << std::endl;
        for (int i=0; i<it->second.size();i++)
        {
            std::cout << it->second[i].doc_id << " " << it->second[i].count << std::endl;
        }
        std::cout << std::endl;
    }*/
}

std::map<std::string, std::vector<Entry>> InvertedIndex::getFreqDictionary()
{
    return freq_dictionary;
}

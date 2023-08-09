#ifndef FINALPROJECT_INVERTEDINDEX_H
#define FINALPROJECT_INVERTEDINDEX_H

#pragma once
#include "vector"
#include "iostream"
#include "map"
#include "thread"
#include "mutex"
#include "ConverterJson.h"

struct Entry
{
    size_t doc_id, count;
};

class InvertedIndex
{
public:
    InvertedIndex() = default;

//    void UpdateDocumentBase(std::vector<std::string> input_docs);
    void UpdateDocumentBase();
    std::vector<Entry> GetWordCount (const std::string &word);
    void freqDictionaryInfill();
    std::map<std::string, std::vector<Entry>> getFreqDictionary();

    std::vector<std::string> docs;
    std::map<std::string, std::vector<Entry>> freq_dictionary;
    ConverterJson jsonData;

private:

};



#endif //FINALPROJECT_INVERTEDINDEX_H

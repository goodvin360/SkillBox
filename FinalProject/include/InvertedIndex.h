#ifndef FINALPROJECT_INVERTEDINDEX_H
#define FINALPROJECT_INVERTEDINDEX_H

#pragma once
#include "vector"
#include "iostream"
#include "map"
#include "thread"
#include "mutex"
#include "ConverterJson.h"
#include "pthread.h"
struct Entry
{
    size_t doc_id, count;
};

class InvertedIndex
{
public:
    InvertedIndex(ConverterJson &inJson): jsonData(inJson) {};

    void UpdateDocumentBase(std::vector<std::string> input_docs);
    std::vector<Entry> GetWordCount (const std::string &word);
    void freqDictionaryInfill();
    void freqDictInfillThread(std::string &textFromDoc);
    std::map<std::string, std::vector<Entry>>* getFreqDictionary();
    int pthread_mutex_init(pthread_mutex_t *mp, const pthread_mutexattr_t *mattr);

private:
    std::map<std::string, std::vector<Entry>> freq_dictionary;
    std::vector<std::string> docs;
    ConverterJson jsonData;

};



#endif //FINALPROJECT_INVERTEDINDEX_H

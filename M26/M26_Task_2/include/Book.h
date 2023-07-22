#ifndef M26_TASK_2_BOOK_H
#define M26_TASK_2_BOOK_H

#pragma once
#include "vector"
#include "map"
#include "string"

using namespace std;

class Book
{
    map<string, string>phoneBook;

public:
    void setContact(string number, string name);
    map<string,string> getContact(string number="null", string name="null");
};


#endif //M26_TASK_2_BOOK_H

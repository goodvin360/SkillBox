#ifndef M26_TASK_2_BOOK_H
#define M26_TASK_2_BOOK_H

#pragma once
#include "vector"
#include "map"
#include "string"


class Book
{
    std::map<std::string, std::string>phoneBook;

public:
    void setContact(std::string number, std::string name);
    std::map<std::string,std::string> getContact(std::string number="null", std::string name="null");
};


#endif //M26_TASK_2_BOOK_H

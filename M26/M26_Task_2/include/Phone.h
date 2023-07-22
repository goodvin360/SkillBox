#ifndef M26_TASK_2_PHONE_H
#define M26_TASK_2_PHONE_H

#pragma once
#include "Book.h"

class Phone
{
    Book*bk = new Book;
public:
    void makeCall();
    void makeSMS();
    void fillPhoneBook();
    void showPhoneBook();
    void addContact();
};

#endif //M26_TASK_2_PHONE_H

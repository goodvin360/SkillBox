#include <iostream>
#include "random"
#include "map"
#include "sstream"
#include "exception"

class ProductNameException : public std::exception
{
    const char* what() const noexcept override
    {
        return "Can't find this name in the product list";
    }
};

class ProductNumException : public std::exception
{
    const char* what() const noexcept override
    {
        return "Wrong number of product units";
    }
};

void dataBaseInFill(std::map<std::string,int> &dataBase, std::map<std::string,int> &basket)
{
    for (int i=0; i<5; i++)
    {
        std::stringstream prodName;
        prodName << "product number " << i+1;
        dataBase.insert({prodName.str(),rand()%10});
        basket.insert({prodName.str(),0});
    }
}

void showDataBase(std::map<std::string,int> &dataBase)
{
    std::cout << "current data base state: " << std::endl;
    for (auto it=dataBase.begin(); it!= dataBase.end(); it++)
    {
        std::cout << it->first << '\t' << it->second << std::endl;
    }
    std::cout << std::endl;
}

void showBasket(std::map<std::string,int> &basket)
{
    int total = 0;
    for (auto it=basket.begin(); it!= basket.end(); it++)
    {
        total+=it->second;
    }
    if (total==0)
    {
        std::cout << "Your current basket is empty. " << std::endl;
        return;
    }

    std::cout << "Your current basket state: " << std::endl;
    for (auto it=basket.begin(); it!= basket.end(); it++)
    {
        if(it->second>0)
            std::cout << it->first << '\t' << it->second << std::endl;
    }
    std::cout << std::endl;
}

void add(std::map<std::string,int> &dataBase, std::map<std::string,int> &basket)
{
    std::string name;
    std::cout << "Enter product name: " << std::endl;
    std::getline(std::cin, name);

    auto it1=dataBase.find(name);
    auto it2 = basket.find(name);

    if (it1==dataBase.end())
    {
        throw ProductNameException();
    }
    int num;
    std::cout << "Enter number of " << name << " you want to ADD to your basket: " << std::endl;
    std::cin >> num;

    if (num>it1->second)
    {
        std::cin.ignore();
        throw ProductNumException();
    }
    it1->second-=num;
    it2->second+=num;

    showDataBase(dataBase);
    showBasket(basket);
}

void remove(std::map<std::string,int> &dataBase, std::map<std::string,int> &basket)
{
    std::string name;
    std::cout << "Enter product name: " << std::endl;
    std::getline(std::cin, name);

    auto it1=dataBase.find(name);
    auto it2 = basket.find(name);

    if (it2==basket.end()||it2->second==0)
    {
        throw ProductNameException();
    }

    int num;
    std::cout << "Enter number of " << name << " you want to REMOVE from your basket: " << std::endl;
    std::cin >> num;

    if (num>it2->second)
    {
        std::cin.ignore();
        throw ProductNumException();
    }
    it1->second+=num;
    it2->second-=num;

    showDataBase(dataBase);
    showBasket(basket);
}

int main() {
    std::cout << "Task 1" << std::endl;

    srand(time(nullptr));
    std::map<std::string,int> dataBase;
    std::map<std::string,int> basket;

    dataBaseInFill(dataBase,basket);
    showDataBase(dataBase);
    showBasket(basket);

    std::string command;

    while(command!="stop")
    {
        std::cout << "Enter your command: 'add', 'remove' or 'stop': " << std::endl;
        std::getline(std::cin,command);
        try
        {
            if (command=="add")
            {
                add(dataBase,basket);
            }
            else if (command=="remove")
            {
                remove(dataBase, basket);
            }
            else if (command!="add" && command!="remove" && command != "stop")
            {
                std::cout << "Incorrect command. Try again." << std::endl;
                continue;
            }
        }
        catch(const std::exception& x)
        {
            std::cout << "Caught exception: " << x.what() << std::endl;
        }
    }

    return 0;
}

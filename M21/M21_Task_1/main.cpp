#include <iostream>
#include "fstream"
#include "vector"


struct statement
{
    std::vector<std::string> fname;
    std::vector<std::string> sname;
    std::vector<std::string> date;
    std::vector<double> payment;
};

void list(std::ifstream& data, statement *info)
{
    std::string tmp_fname,tmp_sname,tmp_date;
    double tmp_payment;

    if(!data.is_open()){
        std::cerr << "File open error!" << std::endl;
        exit(1);}

    info->fname.clear();
    info->sname.clear();
    info->date.clear();
    info->payment.clear();

    while (!data.eof())
    {
        data >> tmp_fname;
        if (data.eof()) break;
        data >> tmp_sname >> tmp_date >> tmp_payment;
        info->fname.push_back(tmp_fname);
        info->sname.push_back(tmp_sname);
        info->date.push_back(tmp_date);
        info->payment.push_back(tmp_payment);
    }
    data.close();

    for (int i=0; i<info->fname.size(); i++)
    {
        std::cout << info->fname[i] << " " << info->sname[i] << " " << info->date[i] << " " << info->payment[i] << std::endl;
    }
}

void add(std::ofstream& data, statement *info)
{
    std::string tmp_fname,tmp_sname,tmp_date;
    double tmp_payment;

    if(!data.is_open()){
        std::cerr << "File open error!" << std::endl;
        exit(1);}

    std::cout << "Enter first name, second name, date and payment value" << std::endl;
    std::cin >> tmp_fname >> tmp_sname >> tmp_date >> tmp_payment;
    data << tmp_fname << " " << tmp_sname << " "<< tmp_date << " " << tmp_payment << std::endl;
    data.close();
}

int main() {
    std::cout << "Task 1" << std::endl;
    std::string path = "..\\statement.txt";

    statement current_data;
    std::string command;
    while (true)
    {
        std::cout << "Choose option: 'list' or 'add'" << std::endl;
        std::cin >> command;
        if (command=="list") {std::ifstream data_read(path); list(data_read, &current_data);}
        else if (command=="add") {std::ofstream data_add(path, std::ios::app); add(data_add, &current_data);}

        std::cout << "Enter 'stop' if you want finish, or 'next' if you want to continue" << std::endl;
        std::cin >> command; if (command=="stop") break;
        command.clear();
    }
    return 0;
}

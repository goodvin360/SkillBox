#include <iostream>
#include "fstream"
#include "vector"

using namespace std;

struct statement
{
    vector<string> fname;
    vector<string> sname;
    vector<string> date;
    vector<double> payment;
};

void list(ifstream& data, statement *info)
{
    string tmp_fname,tmp_sname,tmp_date;
    double tmp_payment;

    if(!data.is_open()){
        cerr << "File open error!" << endl;
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
        cout << info->fname[i] << " " << info->sname[i] << " " << info->date[i] << " " << info->payment[i] << endl;
    }
}

void add(ofstream& data, statement *info)
{
    string tmp_fname,tmp_sname,tmp_date;
    double tmp_payment;

    if(!data.is_open()){
        cerr << "File open error!" << endl;
        exit(1);}

    cout << "Enter first name, second name, date and payment value" << endl;
    cin >> tmp_fname >> tmp_sname >> tmp_date >> tmp_payment;
    data << tmp_fname << " " << tmp_sname << " "<< tmp_date << " " << tmp_payment << endl;
    data.close();
}

int main() {
    cout << "Task 1" << endl;
    string path = "..\\statement.txt";

    statement current_data;
    string command;
    while (true)
    {
        cout << "Choose option: 'list' or 'add'" << endl;
        cin >> command;
        if (command=="list") {ifstream data_read(path); list(data_read, &current_data);}
        else if (command=="add") {ofstream data_add(path, ios::app); add(data_add, &current_data);}

        cout << "Enter 'stop' if you want finish, or 'next' if you want to continue" << endl;
        cin >> command; if (command=="stop") break;
        command.clear();
    }
    return 0;
}

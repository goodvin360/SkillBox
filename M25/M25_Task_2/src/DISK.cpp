#include "DISK.h"
#include "iostream"
#include "fstream"

using namespace std;

void save(ram &ar)
{
    ofstream save_data;
    string path;
    cout << "Enter path where you want to save data file:" << endl;
    cin >> path;
    save_data.open("..\\..\\data.txt", ios::out);
//    ofstream save_data(path, ios::app);
    for (int i=0; i<8; i++)
    {
        save_data << ar.buf[i] << endl;
    }
    save_data.close();
}

void load(ram &ar)
{
    ifstream load_data;
    string path;
    cout << "Enter path to the data file:" << endl;
    cin >> path;
    load_data.open("..\\..\\data.txt");
//    load_data.open(path);
    if (!load_data.is_open())
    {
        cerr << "Error while opening file." << endl;
    };
    int cnt=0;
    while (!load_data.eof())
    {
        load_data >> ar.buf[cnt];
        cnt++;
    }
    load_data.close();
}
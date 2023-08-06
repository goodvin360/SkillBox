#include "DISK.h"
#include "iostream"
#include "fstream"


void save(ram &ar)
{
    std::ofstream save_data;
    std::string path;
    std::cout << "Enter path where you want to save data file:" << std::endl;
    std::cin >> path;
    save_data.open("..\\..\\data.txt", std::ios::out);
//    ofstream save_data(path, ios::app);
    for (int i=0; i<8; i++)
    {
        save_data << ar.buf[i] << std::endl;
    }
    save_data.close();
}

void load(ram &ar)
{
    std::ifstream load_data;
    std::string path;
    std::cout << "Enter path to the data file:" << std::endl;
    std::cin >> path;
    load_data.open("..\\..\\data.txt");
//    load_data.open(path);
    if (!load_data.is_open())
    {
        std::cerr << "Error while opening file." << std::endl;
    };
    int cnt=0;
    while (!load_data.eof())
    {
        load_data >> ar.buf[cnt];
        cnt++;
    }
    load_data.close();
}
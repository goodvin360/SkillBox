#include <iostream>
#include "fstream"


int main() {
    std::cout << "Task 1" << std::endl;

    std::ofstream data("..\\statement.txt", std::ios::app);
    std::string stop, fname, sname, date, payment;

    while (stop!="stop")
    {
        std::cout << "Enter first name, second name, date and payment value" << std::endl;
        std::cin >> fname >> sname >> date >> payment;
        data << fname << " " << sname << " "<< date << " " << payment <<std::endl;
        std::cout << "Enter 'stop' if you want to exit, and 'next' if you want to continue." << std::endl;
        std::cin >> stop;
    }

    return 0;
}

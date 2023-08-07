#include <iostream>
#include "ctime"
#include "iomanip"
#include <cstdlib>
#include <unistd.h>
#include <thread>


int main() {
    std::cout << "Task 3" << std::endl;

    time_t t_delta;
    t_delta = time(nullptr);
    tm delta = *localtime(&t_delta);
    std::cout << "Enter time"<<std::endl;
    std::cin >> std::get_time(&delta,"%M:%S");
    std::cout <<std::endl;
    int n = delta.tm_min*60 + delta.tm_sec;
    int t = n;
    for(int i=0; i<n;i++){
        delta.tm_min=(int)(t*0.0167)%60;
        delta.tm_sec=t%60;
        std::cout <<delta.tm_min<<":"<<delta.tm_sec<<std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        t--;
    }
    std::cout << "DING! DING! DING!"<<std::endl;

    return 0;
}

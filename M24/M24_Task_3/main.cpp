#include <iostream>
#include "ctime"
#include "iomanip"


int main() {
    std::cout << "Task 3" << std::endl;

    time_t t_delta,t_start,t_end,t_now;
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
        t--;
    }
    std::cout << "DING! DING! DING!"<<std::endl;

    return 0;
}

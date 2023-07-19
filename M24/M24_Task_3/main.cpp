#include <iostream>
#include "ctime"
#include "iomanip"

using namespace std;

int main() {
    cout << "Task 3" << endl;

    time_t t_delta,t_start,t_end,t_now;
    t_delta = time(nullptr);
    tm delta = *localtime(&t_delta);
    cout << "Enter time"<<endl;
    cin >> get_time(&delta,"%M:%S");
    cout <<endl;
    int n = delta.tm_min*60 + delta.tm_sec;
    int t = n;
    for(int i=0; i<n;i++){
        delta.tm_min=(int)(t*0.0167)%60;
        delta.tm_sec=t%60;
        cout <<delta.tm_min<<":"<<delta.tm_sec<<endl;
        t--;
    }
    cout << "DING! DING! DING!"<<endl;

    return 0;
}

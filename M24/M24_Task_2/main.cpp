#include <iostream>
#include "ctime"
#include "map"
#include "iomanip"
#include "vector"
#include <algorithm>

using namespace std;

int main() {
    cout << "Task 2" << endl;


    multimap<pair<int,int>,int>Dates;
    vector<string>Names;
    string name;
    time_t t = time(nullptr);
    tm date = *localtime(&t);

    do
    {
        if (name =="end") break;
        cout << "Enter person name: " << endl;
        cin>>name;
        Names.push_back(name);
        cout << "Enter person birthday date (YYYY/MM/DD):" << endl;
        cin >> get_time(&date, "%Y/%m/%d");
        Dates.insert(pair<pair<int,int>,int>(make_pair(date.tm_mon+1,date.tm_mday),0));
    } while (name!="end");

    tm today = *localtime(&t);
    auto today_pair = make_pair(today.tm_mon+1,today.tm_mday);
    auto it = Dates.lower_bound(today_pair);
    int cnt = Dates.count(it->first);
    for (int i=0; i<cnt; i++)
    {
        int num = distance(Dates.begin(), it);
        cout << "Closest birthday is " << Names[num] << " and it is " <<it->first.first << "." << it->first.second << endl;
        if (it->first==today_pair) cout << "This day is today!";
        it++;
    }

    return 0;
}

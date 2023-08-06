#include <iostream>
#include "ctime"
#include "map"
#include "iomanip"
#include "vector"
#include <algorithm>


int main() {
    std::cout << "Task 2" << std::endl;


    std::multimap<std::pair<int,int>,int>Dates;
    std::vector<std::string>Names;
    std::string name;
    time_t t = time(nullptr);
    tm date = *localtime(&t);

    do
    {
        if (name =="end") break;
        std::cout << "Enter person name: " << std::endl;
        std::cin>>name;
        Names.push_back(name);
        std::cout << "Enter person birthday date (YYYY/MM/DD):" << std::endl;
        std::cin >> std::get_time(&date, "%Y/%m/%d");
        Dates.insert(std::pair<std::pair<int,int>,int>(std::make_pair(date.tm_mon+1,date.tm_mday),0));
    } while (name!="end");

    tm today = *localtime(&t);
    auto today_pair = std::make_pair(today.tm_mon+1,today.tm_mday);
    auto it = Dates.lower_bound(today_pair);
    int cnt = Dates.count(it->first);
    for (int i=0; i<cnt; i++)
    {
        int num = distance(Dates.begin(), it);
        std::cout << "Closest birthday is " << Names[num] << " and it is " <<it->first.first << "." << it->first.second << std::endl;
        if (it->first==today_pair) std::cout << "This day is today!";
        it++;
    }

    return 0;
}

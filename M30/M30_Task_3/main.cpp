#include <iostream>
#include "map"
#include "sstream"
#include "cpr/cpr.h"


void getRequest(cpr::Response &r,  std::map<std::string,std::string> &data)
{
    std::stringstream url;
    url << "https://httpbin.org/get?";
    for (auto it=data.begin(); it!=data.end(); it++)
    {
        url << it->first << "=" << it->second << "&";
    }
    r = Get(cpr::Url(url.str()));
    std::cout << r.text;
//    data.clear();
}

void postRequest(cpr::Response &r,  std::map<std::string,std::string> &data)
{
    std::vector<cpr::Pair> pairs;
    for (auto it=data.begin(); it!=data.end(); it++)
    {
        cpr::Pair pair(it->first, it->second);
        pairs.push_back(pair);
    }

    r = Post(cpr::Url("https://httpbin.org/post"),
             cpr::Payload(pairs.begin(),pairs.end()));
    std::cout << r.text;
//    data.clear();
}

void loadMap(cpr::Response &r, std::map<std::string,std::string> &data)
{
    std::string key, value;
    while (key!="exit")
    {
        std::cout << "Enter key (or 'exit' for finish program) : " << std::endl;
        std::cin >> key;
        if (key!="get"&&key!="post"&&key!="exit")
        {
            std::cout << "Enter value: " << std::endl;
            std::cin >> value;
            data.insert({key,value});
        }
        else if(key=="get")
        {
            getRequest(r,data);
        }
        else if(key=="post")
        {
            postRequest(r,data);
        }
        else if(key=="exit")
        {
            return;
        }
    }
}

int main() {
    std::cout << "Task 3" << std::endl;

    std::map<std::string,std::string> data;

    Response r;

    loadMap(r,data);

    return 0;
}

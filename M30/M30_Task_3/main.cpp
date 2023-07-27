#include <iostream>
#include "map"
#include "sstream"
#include "cpr/cpr.h"


using namespace std;
using namespace cpr;

void getRequest(Response &r,  map<string,string> &data)
{
    stringstream url;
    url << "https://httpbin.org/get?";
    for (auto it=data.begin(); it!=data.end(); it++)
    {
        url << it->first << "=" << it->second << "&";
    }
    r = Get(Url(url.str()));
    cout << r.text;
//    data.clear();
}

void postRequest(Response &r,  map<string,string> &data)
{
    vector<Pair> pairs;
    for (auto it=data.begin(); it!=data.end(); it++)
    {
        Pair pair(it->first, it->second);
        pairs.push_back(pair);
    }

    r = Post(Url("https://httpbin.org/post"),
                  Payload(pairs.begin(),pairs.end()));
    cout << r.text;
//    data.clear();
}

void loadMap(Response &r, map<string,string> &data)
{
    string key, value;
    while (key!="exit")
    {
        cout << "Enter key (or 'exit' for finish program) : " << endl;
        cin >> key;
        if (key!="get"&&key!="post"&&key!="exit")
        {
            cout << "Enter value: " << endl;
            cin >> value;
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
    cout << "Task 3" << endl;

    map<string,string> data;

    Response r;

    loadMap(r,data);

    return 0;
}

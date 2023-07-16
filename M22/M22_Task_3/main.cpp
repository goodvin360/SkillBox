#include <iostream>
#include <cstring>
#include "map"

using namespace std;

bool checkAnagram(string a, string b)
{
    bool condition = false;
    map<char, int> a_map, b_map;
    for(int i=0; i<a.length(); i++){
        if(!a_map.count(a[i])){
            a_map.insert(pair<char, int> (a[i], 1));
        }
        else{
            a_map.find(a[i])->second++;
        }
    }
    for(int i=0; i<b.length(); i++){
        if(!b_map.count(b[i])){
            b_map.insert(pair<char,  int> (b[i], 1));
        }
        else{
            b_map.find(b[i])->second++;
        }
    }
    if(a_map==b_map) condition=true;

    return condition;
}

int main() {
    cout << "Task 3" << endl;

    string a,b;

    cout << "Enter first word: " << endl;
    cin >> a;
    cout << "Enter second word: " << endl;
    cin >> b;

    if (a.length()!=b.length()) cout << "This words have different length. They can't be an anagram.";

    if (checkAnagram(a,b)) cout << "This is anagram" << endl;
    else if (!checkAnagram(a,b)) cout << "This is not anagram.";

    return 0;
}

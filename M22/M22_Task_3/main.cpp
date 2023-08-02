#include <iostream>
#include <cstring>
#include "map"


bool checkAnagram(std::string a, std::string b)
{
    bool condition = false;
    std::map<char, int> a_map, b_map;
    for(int i=0; i<a.length(); i++){
        if(!a_map.count(a[i])){
            a_map.insert(std::pair<char, int> (a[i], 1));
        }
        else{
            a_map.find(a[i])->second++;
        }
    }
    for(int i=0; i<b.length(); i++){
        if(!b_map.count(b[i])){
            b_map.insert(std::pair<char,  int> (b[i], 1));
        }
        else{
            b_map.find(b[i])->second++;
        }
    }
    if(a_map==b_map) condition=true;

    return condition;
}

int main() {
    std::cout << "Task 3" << std::endl;

    std::string a,b;

    std::cout << "Enter first word: " << std::endl;
    std::cin >> a;
    std::cout << "Enter second word: " << std::endl;
    std::cin >> b;

    if (a.length()!=b.length()) std::cout << "This words have different length. They can't be an anagram.";

    if (checkAnagram(a,b)) std::cout << "This is anagram" << std::endl;
    else if (!checkAnagram(a,b)) std::cout << "This is not anagram.";

    return 0;
}

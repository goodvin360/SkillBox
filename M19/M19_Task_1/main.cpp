#include <iostream>
#include "fstream"

using namespace std;

int main() {
    cout << "Task 1" << endl;

    ifstream data;
    data.open("..\\words.txt");

    string target;
    int count=0;
    cout << "What we want to find?" << endl;
    cin >> target;
    string temp;
    while (!data.eof())
    {
        data >> temp;
        if (temp==target)
            count+=1;
    }

    cout << "Target was find " << count << " times.";

    return 0;
}

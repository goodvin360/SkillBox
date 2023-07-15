#include <iostream>
#include "fstream"

using namespace std;

int main() {
    cout << "Fishing" << endl;

    string fishes_path = "..\\river.txt";
    ofstream haul ("..\\basket.txt", ios::app);

    string temp, target, condition;
    int count = 0, fishing = 0;

    while (true)
    {
        cout << "Enter fish type you want to catch: " << endl;
        fishing++;
        cin >> target;
        haul << "This is fishing number " << fishing << endl;

        ifstream fishes (fishes_path);
        while (!fishes.eof())
        {
            fishes>>temp;
            if (temp==target) {haul << target << endl; count++;}
        }
        fishes.close();

        haul << "Haul in the " << fishing << " fishing is " << count << endl;
        count=0;
        cout << "Enter 'stop' if you want to exit, and 'next' if you want to continue." << endl;
        cin >> condition; if (condition=="stop") break;
    }

    haul << endl << endl;

    return 0;
}

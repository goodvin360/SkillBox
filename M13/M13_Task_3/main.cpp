#include <iostream>
#include "vector"

using namespace std;

int main() {
    cout << "Ring buffer" << endl;
    vector<int> db(20);
    int var = 0;
    int iterator=0;
    while (var!=-2)
    {
        cin >> var;
        if (var!=-1 && var!=-2 && iterator<21)
        {db[iterator]=var;
            iterator++;}
        if (var!=-1 && var!=-2 && iterator>=21)
        {
            {for (int i = 0; i < db.size() - 1; i++)
            {
                swap(db[i], db[i + 1]);
            }
            db[19] = var;
            }
        }

        if (var==-1)
        {for (int i=0; i<db.size(); i++) cout << db[i] << " ";
        cout << endl;}
    }

    return 0;
}

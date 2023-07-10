#include <iostream>
#include "vector"

using namespace std;

int main() {
    cout << "Task 2" << endl;

    vector<int>V={2, 7, 11, 15};
    int res = 9;
    int ind1, ind2;
    bool stop = false;

    for (int i=0; i<V.size();i++)
    {
        for (int j=i+1; j<V.size();j++)
        {
            if(res==V[i]+V[j])
            {ind1=i; ind2=j;
                stop = true;
                break;}
        }
        if (stop) break;
    }

    cout << V[ind1] << " " << V[ind2] << endl;

    return 0;
}

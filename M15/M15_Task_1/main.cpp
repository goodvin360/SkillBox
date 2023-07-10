#include <iostream>
#include "vector"

using namespace std;

int main() {
    cout << "Task 1" << endl;

    vector<int> V={-2,1,-3,4,-1,2,1,-5,4};
    vector<int> Sum,ind1,ind2;

    int var=0;
    for (int i=0; i<V.size(); i++)
    {
        var=V[i];
        for (int j=i+1; j<V.size();j++)
        {
            var+=V[j];
            Sum.push_back(var);
            ind1.push_back(i);
            ind2.push_back(j);
        }
    }

    int max=Sum[0];
    int ind_num;

    for (int i=1; i<Sum.size(); i++)
    {
        if (max<Sum[i])
        {
            max=Sum[i];
            ind_num=i;
        }

    }
    cout << "Max sum is: " << max << endl;
    cout << "First index is: " << ind1[ind_num] << ", Second index is: " << ind2[ind_num] << endl;

    return 0;
}

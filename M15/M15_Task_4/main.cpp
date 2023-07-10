#include <iostream>
#include "vector"

using namespace std;

vector<int> sort(vector<int>data)
{
    int temp=0;
    for (int i=0; i<data.size(); i++)
    {
        for (int j=0; j<data.size()-1;j++)
        {
            if (data[j]>data[j+1])
            {
                temp=data[j];
                data[j]=data[j+1];
                data[j+1]=temp;
            }
        }
    }
    return data;
}

vector<int> math(vector<int>V_sort, vector<int>V_neg)
{
    for (int i=0; i<V_sort.size();i++)
    {
        for (int j=0; j<V_neg.size();j++)
        {
            if(V_sort[i]==-1*V_neg[j])
            {
                V_sort[i]=-1*V_sort[i];
            }
        }
    }
    return V_sort;
}

int main() {
    cout << "Task 4" << endl;

    vector<int>V={-100,-50, -5, 1, 10, 15};

    cout << "Input data: " ;
    for (int i=0; i<V.size(); i++)
        cout << V[i] << " ";

    vector<int>V_sort(V.size(),0);
    vector<int>V_neg;
    for (int i=0; i<V.size();i++)
    {
        if (V[i]<0) {V_neg.push_back(V[i]); V[i]=-1*V[i];}
    }

    V_sort=sort(V);
    V_sort= math(V_sort,V_neg);

    cout << endl << "Output data: " ;
    for (int i=0; i<V_sort.size(); i++)
        cout << V_sort[i] << " ";

    return 0;
}

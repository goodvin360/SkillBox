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

int main() {
    cout << "Task 3" << endl;

    vector<int>data;
    int var=0;

    cout << "Enter data vector values: " << endl;

    do
    {
        cin >> var;
        if (var!=-1 && var!=-2) data.push_back(var);

        if (var==-1 && data.size()>=5)
        {
            data = sort(data);
            cout << "Fifth element is: " << data[4] << endl;
        }
        else if (var==-1 && data.size()<5)
        {
            cout << "Data vector is too small. Enter more numbers." << endl;
        }

    } while (var!=-2);

    cout << "Sorted data vector: ";
    for (int i=0; i<data.size(); i++)
        cout << data[i] << " ";

    return 0;
}

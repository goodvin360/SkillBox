#include <iostream>
#include "vector"

using namespace std;

int main() {
    cout << "Filtering" << endl;
    int size, X_value;
    cout << "Enter vector size:" << endl;
    cin >> size;
    vector <int> vec(size);
    cout << "Enter vector elements values:" << endl;
    for (int i=0; i<size;i++)
        cin >> vec[i];
    cout << "enter X value to filter:" << endl;
    cin >> X_value;
    for (int i=0; i<vec.size(); i++)
    {if (vec[i]==X_value)
        {for (int j=i;j<vec.size()-1;j++)
            {
                swap(vec[j],vec[j+1]);
                /*int var = vec[j+1];
                vec[j+1]=vec[j];
                vec[j]=var;*/
            }
            i--;
            vec.pop_back();
        }
    }

    for (int i=0; i<vec.size(); i++)
        cout << vec[i] << " ";
    cout << endl;

    return 0;
}

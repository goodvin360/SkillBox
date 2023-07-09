#include <iostream>
#include "vector"

using namespace std;

void mult(float a[][4], vector<float>b, float c[])
{
    float var = 0;
    for (int i=0; i<4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            var+=a[i][j]*b.at(j);
        }
        c[i]=var;
        var=0;
    }
}

int main() {
    cout << "Multiplication" << endl;
    float a[4][4];
    vector<float> b;
    float c[4];
    float var = 0;

    cout << "Enter matrix 'a' values: 16 integers divided on 4 rows with 4 integers in each one, separated by space." << endl;
    for (int i=0; i<4; i++)
    {
        cin >> a[i][0] >> a[i][1] >> a[i][2] >> a[i][3];
    }

    cout << "Enter vector 'b' values: 4 integers, separated by 'Enter' button." << endl;
    for (int i=0; i<4; i++)
    {
        cin >> var;
        b.push_back(var);
    }

    mult(a,b,c);

    cout << "This is result of multiplication 'a' on 'b':" << endl;
    for (int i=0; i<4; i++)
    {
        cout << c[i] << endl;
    }

    return 0;
}

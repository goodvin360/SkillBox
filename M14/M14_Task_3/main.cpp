#include <iostream>

using namespace std;

bool check (int A[4][4], int B[4][4])
{
    for (int i=0; i<4; i++)
    {
        for (int j=0; j<4; j++)
        {
            if(A[i][j]!=B[i][j]) return 0;
        }
    }
    return 1;
}

void diag(int A[][4])
{
    for (int i=0; i<4; i++)
    {
        for (int j=0; j<4; j++)
        {
            if(i!=j) A[i][j]=0;
        }
    }
}

int main() {
    cout << "Matrix Comparison" << endl;
    int A[4][4];
    int B[4][4];
    
    cout << "Enter matrix A values: 16 integers divided on 4 rows with 4 integers in each one, separated by space." << endl;
    for (int i=0; i<4; i++)
    {
        cin >> A[i][0] >> A[i][1] >> A[i][2] >> A[i][3];
    }

    cout << "Enter matrix B values: 16 integers divided on 4 rows with 4 integers in each one, separated by space." << endl;
    for (int i=0; i<4; i++)
    {
        cin >> B[i][0] >> B[i][1] >> B[i][2] >> B[i][3];
    }

    if (check(A,B)) cout << "Matrices IS equal!" << endl;
    else cout << "Matrices IS NOT equal!" << endl;

    if (check(A,B))
        diag(A);

    for (int i=0; i<4; i++)
    {
        for (int j=0; j<4; j++)
        {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}

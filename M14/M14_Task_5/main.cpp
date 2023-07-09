#include <iostream>

using namespace std;

void draw(bool A[][12])
{
    for (int i=0; i<12; i++)
    {for (int j=0; j<12; j++)
        {
            if(A[i][j]) cout << " o ";
            else cout << " x ";
        }
        cout << endl;
    }
}

void coordinates(int V[])
{
    int x1=0,y1=0,x2=0,y2=0;

    do
    {cout << "Enter start point coordinates (x1, y1):" << endl;
        cin >> x1 >> y1;
        if (x1<0||x1>11||y1<0||y1>11) cout << "Incorrect coordinates. Try again." <<endl;
    } while (x1<0||x1>11||y1<0||y1>11);

    do
    {cout << "Enter end point coordinates (x2, y2):" << endl;
        cin >> x2 >> y2;
        if (x2<0||x2>11||y2<0||y2>11) cout << "Incorrect coordinates. Try again." <<endl;
    } while (x2<0||x2>11||y2<0||y2>11);

    if (x1>x2) V[0] = x2;
    else V[0] = x1;
    V[1] = max(x1,x2);
    V[2] = min(y1,y2);
    V[3] = max(y1,y2);
}

void pop(bool A[][12], int x_start, int x_end, int y_start, int y_end)
{
    for (int i=y_start;i<=y_end;i++)
    {
        for (int j=x_start;j<=x_end;j++)
        {
            if (A[i][j])
            {
                A[i][j]=false;
                cout << "Pop!" << endl;
            }
        }
    }
    draw(A);
}

bool check(bool A[][12])
{
    for (int i=0; i<12; i++)
    {for (int j=0; j<12; j++)
        {if(A[i][j])
            {
                cout << "There is left something else" << endl;
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    cout << "Pimple" << endl;
    bool A[12][12];
    int x_start=0,x_end=0,y_start=0,y_end=0;
    int V[4] ={x_start,x_end,y_start,y_end};

    for (int i=0; i<12; i++)
        {for (int j=0; j<12; j++)
            {
                A[i][j]=1;
            }
        }

    draw(A);

    coordinates(V);
    x_start=V[0];x_end=V[1];y_start=V[2];y_end=V[3];

    pop(A,x_start,x_end,y_start,y_end);

    while (check(A))
    {coordinates(V);
        x_start=V[0];x_end=V[1];y_start=V[2];y_end=V[3];
        pop(A,x_start,x_end,y_start,y_end);}

    return 0;
}

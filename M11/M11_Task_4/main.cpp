#include <iostream>
using namespace std;

int check (char arr[3][3], int O_cnt, int X_cnt, int dot_cnt)
{
    for (int i=0; i<3; i++)
    {
        if ((arr[i][0]=='X'&&arr[i][1]=='X'&&arr[i][2]=='X')
            ||(arr[0][i]=='X'&&arr[1][i]=='X'&&arr[2][i]=='X')
            ||(arr[0][0]=='X'&&arr[1][1]=='X'&&arr[2][2]=='X')
            ||(arr[2][0]=='X'&&arr[1][1]=='X'&&arr[0][2]=='X'))
        {if (O_cnt>=X_cnt) return 1;
            else  return 2;}
        else if ((arr[i][0]=='O'&&arr[i][1]=='O'&&arr[i][2]=='O')
                 ||(arr[0][i]=='O'&&arr[1][i]=='O'&&arr[2][i]=='O')
                 ||(arr[0][0]=='O'&&arr[1][1]=='O'&&arr[2][2]=='O')
                 ||(arr[2][0]=='O'&&arr[1][1]=='O'&&arr[0][2]=='O'))
        {if (X_cnt>O_cnt) return 1;
            else  return 3;}
        else return 4;
    }
}

int main() {
    std::cout << "Tic-Tac-Toe" << std::endl;
    string row;
    int O_cnt=0, X_cnt=0, dot_cnt=0;
    char arr[3][3];
    int check_result=0;
    cout << "Enter the game-board data:" << endl;

    for (int i=0;i<3;i++)
    {getline (cin, row);
        if (row.length()!=3) {cout << "Incorrect input." << endl; return 0;}
        for (int j=0;j<3;j++)
            arr[i][j]=row[j];
        row.clear();}
    
    for (int i=0;i<3;i++)
    {
        for (int j=0;j<3;j++)
           {if (arr[i][j]!='O'&&arr[i][j]!='X'&&arr[i][j]!='.') {cout << "Incorrect"; return 0;}
            else if (arr[i][j]=='O') O_cnt++;
            else if (arr[i][j]=='X') X_cnt++;
            else if (arr[i][j]=='.') dot_cnt++;}
    }
    if (O_cnt>X_cnt) {cout << "Incorrect"; return 0;}

    check_result = check(arr, O_cnt,X_cnt,dot_cnt);

    if (check_result==1) cout << "Incorrect" << endl;
    if (check_result==2) cout << "Petya won" << endl;
    if (check_result==3) cout << "Vanya won" << endl;
    if (check_result==4) cout << "Nobody" << endl;

    return 0;
}

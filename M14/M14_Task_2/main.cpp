#include <iostream>

using namespace std;

void draw_field (char game_field[3][3])
{
    cout << "-" << game_field[0][0] << "-" << "|" << "-" << game_field[0][1] << "-" << "|" << "-" << game_field[0][2] << "-"<< endl;
    cout << "-" << game_field[1][0] << "-" << "|" << "-" << game_field[1][1] << "-" << "|" << "-" << game_field[1][2] << "-"<< endl;
    cout << "-" << game_field[2][0] << "-" << "|" << "-" << game_field[2][1] << "-" << "|" << "-" << game_field[2][2] << "-"<< endl;
}

int check(char game_field[3][3], int moves)
{
    for (int i=0; i<3; i++)
    {
        if (((game_field[i][0]=='X'&&game_field[i][1]=='X'&&game_field[i][2]=='X')
            ||(game_field[0][i]=='X'&&game_field[1][i]=='X'&&game_field[2][i]=='X')
            ||(game_field[0][0]=='X'&&game_field[1][1]=='X'&&game_field[2][2]=='X')
            ||(game_field[2][0]=='X'&&game_field[1][1]=='X'&&game_field[0][2]=='X')) && moves>=5)
        {return 1;}
        else if (((game_field[i][0]=='O'&&game_field[i][1]=='O'&&game_field[i][2]=='O')
                 ||(game_field[0][i]=='O'&&game_field[1][i]=='O'&&game_field[2][i]=='O')
                 ||(game_field[0][0]=='O'&&game_field[1][1]=='O'&&game_field[2][2]=='O')
                 ||(game_field[2][0]=='O'&&game_field[1][1]=='O'&&game_field[0][2]=='O')) && moves>=5)
        {return 2;}
        else if (moves ==9) return 3;
    }
}

int main() {
    cout << "Tic-Tac-Toe" << endl;
    char game_field[3][3] =  {{' ',' ',' '},
                              {' ',' ',' '},
                              {' ',' ',' '}};
    draw_field(game_field);
    int i,j,moves;
    moves=0;
    char var = 'X';
    for (int iter=0; iter<9; iter++) {
        do {
            cout << "where to place '" << var << "'?" << " Please, enter two numbers " << endl;
            cout << "(each from 1 to 3), separated with 'enter' button." << endl;
            cin >> i >> j;}
        while (i < 1 || i > 3 || j < 1 || j > 3);

        do {
            if (game_field[i-1][j-1] == ' ') {game_field[i-1][j-1]=var;}
            else {cout << "This place is not empty already, please try another one numbers" << endl;
                cin >> i >> j;}}
        while (game_field[i-1][j-1]!=var);

        if (var == 'X') {var = 'O';}
        else { var = 'X';}
        draw_field(game_field);

    moves+=1;
    i=-1;
    j=-1;
    int res = check(game_field, moves);
        if (res==1)
            {
                cout << "X win";
                return 0;
            }
        else if (res==2)
            {
                cout << "O win";
                return 0;
            }
        else if (res==3)
        {
            cout << "pobedila druzhba";
            return 0;
        }
    }
    return 0;
}

#include <iostream>
#include "vector"

using namespace std;

int main() {
    cout << "Piano" << endl;

    enum notes{
        C=1, D=2, E=3, F=4, G=5, A=6, B=7
    };

    vector<int> note_part;

    vector<vector<int>> note;

    int var=0;

    for (int i=0; i<12; i++)
    {
        cout << "Enter your " << i+1 << " part of melody: C=1, D=2 E=3, F=4, G=5, A=6, B=7. Separate notes by space: 1 3 5 2 ... or by 'enter' button";
        cout << "To finish entering notes please enter either 0 or 8" << endl;
        do
        {cin >> var;
            if (var<1||var>7) cout << "There is some notes out of range" << endl;
        note_part.push_back(var);} while (cin.peek() != '\n');
        note.push_back(note_part);
        note_part.clear();
    }

    for (int i=0; i<note.size(); i++)
    {
        cout << "This is your " << i+1 << " part of melody: " << endl;
        for (int j=0; j<note[i].size(); j++)
        {
            if (note[i][j]==notes::C) cout << " C ";
            else if (note[i][j]==notes::D) cout << " D ";
            else if (note[i][j]==notes::E) cout << " E ";
            else if (note[i][j]==notes::F) cout << " F ";
            else if (note[i][j]==notes::G) cout << " G ";
            else if (note[i][j]==notes::A) cout << " A ";
            else if (note[i][j]==notes::B) cout << " B ";
        }
        cout << endl;
    }

    return 0;
}
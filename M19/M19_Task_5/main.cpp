#include <iostream>
#include "fstream"
#include "vector"

using namespace std;

void ques_disp(int ques_num)
{
    string path = "..\\game_data\\questions.txt";
    string tmp;
    vector<vector<string>>ques;
    vector<string>temp;
    ifstream data;
    data.open(path);

    while (!data.eof())
    {
        data >> tmp;
        temp.push_back(tmp);
        if (data.peek() == '\n' || data.peek() == EOF)
        {
            ques.push_back(temp);
            temp.clear();
        }
        tmp.clear();
    }

    cout << "Your sector is: ";
    for (int j=0; j<ques[ques_num-1].size(); j++)
        cout << ques[ques_num-1][j] << " ";
    cout << endl;
}

bool check_ans(int s)
{
    string path = "..\\game_data\\answers.txt";
    string ans, tmp;
    vector <string>answers;
    ifstream data;
    data.open(path);
    while (!data.eof())
    {
        data>>tmp;
        answers.push_back(tmp);
        tmp.clear();
    }
    cout << "Enter your answer:" << endl;
    cin >> ans;
    if (ans==answers[s-1]) return true;

    return false;
}

int check_if_played(vector<int>v, int new_s)
{
    for (int i=0; i<v.size()-1;i++)
    {
        if (new_s==v[i])
        {
            new_s+=1;
            if (new_s>=14) new_s=1;
            new_s = check_if_played(v,new_s);
        }
    }
    return new_s;
}

int main() {
    cout << "Task 5" << endl;
    int new_sector=1, offset=0;
    int connoisseurs_score=0, audience_score=0;
    vector<int>played;
    for (int i=0;i<13;i++)
    {
        cout << "Enter offset: (from 1 to 12)" << endl;
        while (offset<1||offset>12)
        {
            cin >> offset;
            if (offset<1||offset>12) cout <<"Incorrect offset value. Try again please." << endl;
        }
        new_sector+=offset;
        if (new_sector>13) new_sector-=13;
        played.push_back(new_sector);
        new_sector = check_if_played(played,new_sector);
        played.pop_back();
        played.push_back(new_sector);

        ques_disp(new_sector);

        if (check_ans(new_sector)) connoisseurs_score++;
        else audience_score++;

        offset=0;
    }

    if (connoisseurs_score>audience_score) cout << "Znatoki WIN" << endl;
    if (connoisseurs_score<audience_score) cout << "Telezriteli WIN" << endl;
    if (connoisseurs_score==audience_score) cout << "Pobedila dryzhba" << endl;

    return 0;
}

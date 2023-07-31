#include <iostream>
#include "fstream"
#include "vector"

void ques_disp(int ques_num)
{
    std::string path = "..\\game_data\\questions.txt";
    std::string tmp;
    std::vector<std::vector<std::string>>ques;
    std::vector<std::string>temp;
    std::ifstream data;
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

    std::cout << "Your sector is: ";
    for (int j=0; j<ques[ques_num-1].size(); j++)
        std::cout << ques[ques_num-1][j] << " ";
    std::cout << std::endl;
}

bool check_ans(int s)
{
    std::string path = "..\\game_data\\answers.txt";
    std::string ans, tmp;
    std::vector <std::string>answers;
    std::ifstream data;
    data.open(path);
    while (!data.eof())
    {
        data>>tmp;
        answers.push_back(tmp);
        tmp.clear();
    }
    std::cout << "Enter your answer:" << std::endl;
    std::cin >> ans;
    if (ans==answers[s-1]) return true;

    return false;
}

int check_if_played(std::vector<int>v, int new_s)
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
    std::cout << "Task 5" << std::endl;
    int new_sector=1, offset=0;
    int connoisseurs_score=0, audience_score=0;
    std::vector<int>played;
    for (int i=0;i<13;i++)
    {
        std::cout << "Enter offset: (from 1 to 12)" << std::endl;
        while (offset<1||offset>12)
        {
            std::cin >> offset;
            if (offset<1||offset>12) std::cout <<"Incorrect offset value. Try again please." << std::endl;
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

    if (connoisseurs_score>audience_score) std::cout << "Znatoki WIN" << std::endl;
    if (connoisseurs_score<audience_score) std::cout << "Telezriteli WIN" << std::endl;
    if (connoisseurs_score==audience_score) std::cout << "Pobedila dryzhba" << std::endl;

    return 0;
}

#include <iostream>
#include "vector"

using namespace std;

class Talent
{
public:
    virtual string Skill() = 0;
};

class Swimming : virtual public Talent
{
public:

    virtual string Skill()
    {
        return "swim";
    }
};

class Dancing : virtual public Talent
{
public:

    virtual string Skill()
    {
        return "dance";
    }
};

class Counting : virtual public Talent
{
public:

    virtual string Skill()
    {
        return "count";
    }
};

class Dog
{
    string name;
    vector<Talent*>talents;

public:
    void showTalents()
    {
        if(!talents.empty())
        {
            cout << "This is " << name << " and he has some talents:" << endl;
            for (int i=0; i<talents.size(); i++)
                cout << "It can " << talents[i]->Skill() << endl;
        }
        else cout << "This is " << name << " and he doesn't have any talents :(" << endl;
    }

    virtual void setTalents(Talent*talent)
    {
        talents.push_back(talent);
    }

    Dog(string inName):name(inName)
    {

    }
};

int main() {
    cout << "Task 1" << endl;

    Dog dogo("Steve");

    dogo.setTalents(new Swimming);
    dogo.setTalents(new Dancing);
    dogo.setTalents(new Counting);

    dogo.showTalents();

    return 0;
}
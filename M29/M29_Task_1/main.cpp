#include <iostream>
#include "vector"


class Talent
{
public:
    virtual std::string Skill() = 0;
};

class Swimming : virtual public Talent
{
public:

    virtual std::string Skill()
    {
        return "swim";
    }
};

class Dancing : virtual public Talent
{
public:

    virtual std::string Skill()
    {
        return "dance";
    }
};

class Counting : virtual public Talent
{
public:

    virtual std::string Skill()
    {
        return "count";
    }
};

class Dog
{
    std::string name;
    std::vector<Talent*>talents;

public:
    void showTalents()
    {
        if(!talents.empty())
        {
            std::cout << "This is " << name << " and he has some talents:" << std::endl;
            for (int i=0; i<talents.size(); i++)
                std::cout << "It can " << talents[i]->Skill() << std::endl;
        }
        else std::cout << "This is " << name << " and he doesn't have any talents :(" << std::endl;
    }

    virtual void setTalents(Talent*talent)
    {
        talents.push_back(talent);
    }

    Dog(std::string inName):name(inName)
    {

    }
};

int main() {
    std::cout << "Task 1" << std::endl;

    Dog dogo("Steve");

    dogo.setTalents(new Swimming);
    dogo.setTalents(new Dancing);
    dogo.setTalents(new Counting);

    dogo.showTalents();

    return 0;
}
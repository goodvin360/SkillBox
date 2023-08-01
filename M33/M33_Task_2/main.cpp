#include <iostream>
#include "random"
#include "exception"

class successTryException : public std::exception
{
    const char* what() const noexcept override
    {
        return "Congrats, you caught a fish!";
    }
};

class failTryException : public std::exception
{
    const char* what() const noexcept override
    {
        return "Sorry, there is no fish in this try";
    }
};

void fillPond(std::string pond[])
{
    for (int i=0; i<3; i++)
    {
        bool flag = false;
        while (!flag)
        {
            int var = rand()%9;
            if (pond[var]=="")
            {
                pond[var] = "boot";
                flag = true;
            }
        }
    }

    bool flag = false;
    while (!flag)
    {
        int var = rand()%9;
        if (pond[var]=="")
        {
            pond[var] = "fish";
            flag = true;
        }
    }
}

void showPond(std::string pond[])
{
    for (int i=0; i<9; i++)
    {
        std::cout << i << " " << pond[i] << std::endl;
    }
}

void fishing(std::string pond[], int &s, int &tries)
{
    if (s<0||s>8)
    {
        throw std::invalid_argument("wrong sector number");
    }

    if (pond[s]==""||pond[s]=="boot")
    {
        tries++;
        throw failTryException();
    }
    if (pond[s]=="fish")
    {
        tries++;
        throw successTryException();
    }
}

int main() {
    std::cout << "Task 2" << std::endl;

    srand(time(nullptr));

    std::string pond[9]{};
    fillPond(pond);
    showPond(pond);

    bool check = true;

    int s;
    int tries=0;

    while (check)
    {
        std::cout << "Enter pond sector number (from 0 to 8):" << std::endl;
        std::cin >> s;
        try
        {
            fishing(pond,s,tries);
        }
        catch (const failTryException &x)
        {
            std::cout << "Caught exception: Fail Try" << std::endl;
        }
        catch (const std::invalid_argument&x)
        {
            std::cout << "Invalid argument: " << x.what() << std::endl;
        }
        catch (const successTryException &x)
        {
            std::cout << "Success at try number: " << tries << std::endl;
            check = false;
        }
    }

    return 0;
}

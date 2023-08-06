#include <iostream>
#include "vector"
#include "map"


class Branch
{
    std::string elvesName;
    Branch*parent = nullptr;
    std::vector<Branch*> children;
    std::vector<Branch*> mains;
    int numOfMainBranches = 0;
    int numOfMiddleBranches = 0;

public:


    void inHouse()
    {
        numOfMainBranches = rand()%3+3;
//        numOfMainBranches = 2;
        for (int i=1; i<=numOfMainBranches; i++)
        {
            Branch*mainBranch = new Branch;
            mainBranch->parent = this;
            std::cout << "Enter elves name for " << i << " main branch :" << std::endl;
            std::cin >> mainBranch->elvesName;
            numOfMiddleBranches = rand()%2+2;
//            numOfMiddleBranches = 2;
            for (int j=1; j<=numOfMiddleBranches; j++)
            {
                Branch*middleBranch = new Branch;
                middleBranch->parent = mainBranch;
                std::cout << "Enter elves name for " << j << " middle branch :" << std::endl;
                std::cin >> middleBranch->elvesName;
                mainBranch->children.push_back(middleBranch);
            }
            children.push_back(mainBranch);
        }
    }

    int getNeighbours(std::string name, int index)
    {
        int count=0;

        if (children[index]->elvesName!="None") count++;
        for (int i=0; i<children[index]->children.size(); i++)
        {
            if(children[index]->children[i]->elvesName!="None") count++;
        }
        return count;
    }

    int findBranch(std::string name)
    {
        int index = -1;
        for (int i = 0; i < children.size(); i++)
        {
            if (children[i]->elvesName == name) {
                index = i;
                return index;
            }
            for (int j = 0; j < children[i]->children.size(); j++) {
                if (children[i]->children[j]->elvesName == name) {
                    index = i;
                    return index;
                }
            }
        }
        return index;
    }

    void showBranches()
    {
        for (int i=0; i<children.size(); i++)
        {
            std::cout << children[i]->elvesName << std::endl;
            for (int j=0; j<children[i]->children.size(); j++)
            {
                std::cout << children[i]->children[j]->elvesName << std::endl;
            }
        }
    }

};


int main() {
    std::cout << "Task 1" << std::endl;
    srand(time(nullptr));


    std::string name;
    int index=0;

    Branch*trees[2];
    for (int i=0; i<2; i++)
    {
        trees[i] = new Branch;
        std::cout << "This is " << i+1 << " tree" << std::endl;
        trees[i]->inHouse();
    }

    std::cout << "Enter name: " << std::endl;
    std::cin >> name;

    for (int i=0; i<2; i++)
    {
        int index=0;
        index = trees[i]->findBranch(name);
        if (index>=0)
        {
            std::cout << "Number of elves on the " << i+1 << " tree and on the " << index+1 << " main branch is: " << std::endl;
            std::cout << trees[i]->getNeighbours(name, index) << std::endl;
        }
        else std::cout << "There is no elves with this name on the " << i+1 << " tree." << std::endl;
    }

    return 0;
}

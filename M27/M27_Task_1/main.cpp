#include <iostream>
#include "vector"
#include "map"

using namespace std;

class Branch
{
    string elvesName;
    Branch*parent = nullptr;
    vector<Branch*> children;
    vector<Branch*> mains;
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
            cout << "Enter elves name for " << i << " main branch :" << endl;
            cin >> mainBranch->elvesName;
            numOfMiddleBranches = rand()%2+2;
//            numOfMiddleBranches = 2;
            for (int j=1; j<=numOfMiddleBranches; j++)
            {
                Branch*middleBranch = new Branch;
                middleBranch->parent = mainBranch;
                cout << "Enter elves name for " << j << " middle branch :" << endl;
                cin >> middleBranch->elvesName;
                mainBranch->children.push_back(middleBranch);
            }
            children.push_back(mainBranch);
        }
    }

    int getNeighbours(string name, int index)
    {
        int count=0;

        if (children[index]->elvesName!="None") count++;
        for (int i=0; i<children[index]->children.size(); i++)
        {
            if(children[index]->children[i]->elvesName!="None") count++;
        }
        return count;
    }

    int findBranch(string name)
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
            cout << children[i]->elvesName << endl;
            for (int j=0; j<children[i]->children.size(); j++)
            {
                cout << children[i]->children[j]->elvesName << endl;
            }
        }
    }

};


int main() {
    cout << "Task 1" << endl;
    srand(time(nullptr));


    string name;
    int index=0;

    Branch*trees[2];
    for (int i=0; i<2; i++)
    {
        trees[i] = new Branch;
        cout << "This is " << i+1 << " tree" << endl;
        trees[i]->inHouse();
    }

    cout << "Enter name: " << endl;
    cin >> name;

    for (int i=0; i<2; i++)
    {
        int index=0;
        index = trees[i]->findBranch(name);
        if (index>=0)
        {
            cout << "Number of elves on the " << i+1 << " tree and on the " << index+1 << " main branch is: " << endl;
            cout << trees[i]->getNeighbours(name, index) << endl;
        }
        else cout << "There is no elves with this name on the " << i+1 << " tree." << endl;
    }

    return 0;
}

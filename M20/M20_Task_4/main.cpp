#include <iostream>
#include "fstream"

using namespace std;

int main() {
    cout << "Cash machine" << endl;

    int bills[5] = {100,200,500,1000,5000};
    int money[1000];

    string operation;
    cout << "Enter operation: " <<endl;
    cin >> operation;

    ifstream in("..\\money.bin", ios::binary);
    if (in.is_open())
    {
        in.read((char*)money,sizeof (money));
        in.close();
    } else {
        for (int i=0; i< 1000; i++)
        {
            money[i]=0;
        }
    }

    if (operation=="+")
    {
        for (int i=0; i<1000; i++)
        {
            if (money[i]==0)
            {
                money[i] = bills[rand()%5];
            }
        }
        ofstream out("..\\money.bin", ios::binary);
        out.write((char*)money, sizeof (money));
        return 0;
    }

    else if (operation=="-")
    {
        cout << "Amount:" <<endl;
        int amount;
        cin >> amount;
        if ((amount%100)!=0)
        {
            cerr << "Invalid amount: " << amount << endl;
            return 1;
        }
        int amount_to_collect = amount;
        for (int i=4; i>=0; i--)
        {
            int bill = bills[i];
            for (int j=0; j<1000; j++)
            {
                if (money[j]==bill)
                {
                    if (amount_to_collect>=bill)
                    {
                        money[j]=0;
                        amount_to_collect-=bill;
                        if (amount_to_collect==0)
                        {
                            cout << "Amount taken: " << amount << endl;
                            ofstream out("..\\money.bin", ios::binary);
                            out.write((char*)money, sizeof (money));
                            return 0;
                        }
                    }
                }
            }
        }
    }

    return 0;
}

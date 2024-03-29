#include <iostream>
#include "fstream"


int main() {
    std::cout << "Cash machine" << std::endl;

    int bills[5] = {100,200,500,1000,5000};
    int money[1000];

    std::string operation;
    std::cout << "Enter operation: " <<std::endl;
    std::cin >> operation;

    std::ifstream in("..\\money.bin", std::ios::binary);
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
        std::ofstream out("..\\money.bin", std::ios::binary);
        out.write((char*)money, sizeof (money));
        return 0;
    }

    else if (operation=="-")
    {
        std::cout << "Amount:" <<std::endl;
        int amount;
        std::cin >> amount;
        if ((amount%100)!=0)
        {
            std::cerr << "Invalid amount: " << amount << std::endl;
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
                            std::cout << "Amount taken: " << amount << std::endl;
                            std::ofstream out("..\\money.bin", std::ios::binary);
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

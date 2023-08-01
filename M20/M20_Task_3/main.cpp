#include <iostream>
#include "fstream"


int main() {
    std::cout << "Fishing" << std::endl;

    std::string fishes_path = "..\\river.txt";
    std::ofstream haul ("..\\basket.txt", std::ios::app);

    std::string temp, target, condition;
    int count = 0, fishing = 0;

    while (true)
    {
        std::cout << "Enter fish type you want to catch: " << std::endl;
        fishing++;
        std::cin >> target;
        haul << "This is fishing number " << fishing << std::endl;

        std::ifstream fishes (fishes_path);
        while (!fishes.eof())
        {
            fishes>>temp;
            if (temp==target) {haul << target << std::endl; count++;}
        }
        fishes.close();

        haul << "Haul in the " << fishing << " fishing is " << count << std::endl;
        count=0;
        std::cout << "Enter 'stop' if you want to exit, and 'next' if you want to continue." << std::endl;
        std::cin >> condition; if (condition=="stop") break;
    }

    haul << std::endl << std::endl;

    return 0;
}

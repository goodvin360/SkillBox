#include <iostream>
#include "map"


int main() {
    std::cout << "Task 2" << std::endl;
    std::map<int,std::string>line;
    int counter=0, old_counter;
    std::string second_name;

    while (second_name!="Exit")
    {
        std::cin >> second_name;
        if(second_name!="Next")
        {
            for (int i=0; i<1; i++)
                {
                    counter+=second_name[i]-'0';
                }
            if (old_counter==counter) counter++;
            line.insert(std::pair<int,std::string>(counter,second_name));
            old_counter=counter;
            counter=0;
        }
        else if (second_name=="Next")
        {
            std::map<int,std::string>::iterator it;
            it=line.begin();
            std::cout << it->second << std::endl;
            line.erase(it);
        }
    }

    return 0;
}

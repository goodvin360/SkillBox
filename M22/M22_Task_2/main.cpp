#include <iostream>
#include "map"

using namespace std;

int main() {
    cout << "Task 2" << endl;
    map<int,string>line;
    int counter=0, old_counter;
    string second_name;

    while (second_name!="Exit")
    {
        cin >> second_name;
        if(second_name!="Next")
        {
            for (int i=0; i<1; i++)
                {
                    counter+=second_name[i]-'0';
                }
            if (old_counter==counter) counter++;
            line.insert(pair<int,string>(counter,second_name));
            old_counter=counter;
            counter=0;
        }
        else if (second_name=="Next")
        {
            map<int,string>::iterator it;
            it=line.begin();
            cout << it->second << endl;
            line.erase(it);
        }
    }

    return 0;
}

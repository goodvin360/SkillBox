#include <iostream>
#include "vector"
#include "random"
#include "unordered_set"
#include "memory"

int main() {
    std::cout << "Task 2" << std::endl;

    auto checkData = [](std::vector<int> &inData)
    {
        std::unordered_set<int> data;
        auto filteredData = std::make_unique<std::vector<int>>();
        std::cout << "Input data: " << std::endl;
        for (auto it:inData)
        {
            std::cout << it << std::endl;
            data.insert(it);
        }
        std::cout << std::endl;

        for (auto it:data)
            filteredData->push_back(it);
        return filteredData;
    };

    std::vector<int> dataSet;
    for (int i=0; i<10; i++)
    {
        int tmp = rand()%10;
        dataSet.push_back(tmp);
    }

    auto outData = checkData(dataSet);

    std::cout << "Filtered data: " << std::endl;
    for (auto it:*outData)
        std::cout << it << std::endl;

    return 0;
}

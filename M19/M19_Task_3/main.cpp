#include <iostream>
#include "vector"
#include "fstream"


int main() {
    std::cout << "Task 3" << std::endl;

    std::ifstream data;
    std::vector<std::string>f_name; std::string tmp_f_name;
    std::vector<std::string>s_name; std::string tmp_s_name;
    std::vector<double>pay; double tmp_pay=0, tmp_pay_pre=0;
    std::vector<std::string>date; std::string tmp_date;
    double total_pay=0;
    data.open("..\\statement.txt");
    int i=0, index=0;
    while (!data.eof())
    {
        data >> tmp_f_name; f_name.push_back(tmp_f_name);
        std::cout << tmp_f_name << std::endl;
        data >> tmp_s_name; s_name.push_back(tmp_s_name);
        tmp_pay_pre=tmp_pay;
        data >> tmp_pay; pay.push_back(tmp_pay); total_pay+=tmp_pay;
        if (tmp_pay>=tmp_pay_pre) index=i;
        data >> tmp_date; date.push_back(tmp_date);
        i++;
    }

    for (int i=0; i<pay.size();i++)
        std::cout << f_name[i] << '\t' << s_name[i] << '\t' << pay[i] << '\t' << date[i] << std::endl;

    std::cout << "Total pay is: " << total_pay << std::endl;
    std::cout << "Max pay is: " << pay[index] << std::endl;
    std::cout << "Customer with max pay is: " << f_name[index] << " " << s_name[index];

    return 0;
}

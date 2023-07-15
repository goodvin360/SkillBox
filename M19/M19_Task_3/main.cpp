#include <iostream>
#include "vector"
#include "fstream"

using namespace std;

int main() {
    cout << "Task 3" << endl;

    ifstream data;
    vector<string>f_name; string tmp_f_name;
    vector<string>s_name; string tmp_s_name;
    vector<double>pay; double tmp_pay=0, tmp_pay_pre=0;
    vector<string>date; string tmp_date;
    double total_pay=0;
    data.open("..\\statement.txt");
    int i=0, index=0;
    while (!data.eof())
    {
        data >> tmp_f_name; f_name.push_back(tmp_f_name);
        cout << tmp_f_name << endl;
        data >> tmp_s_name; s_name.push_back(tmp_s_name);
        tmp_pay_pre=tmp_pay;
        data >> tmp_pay; pay.push_back(tmp_pay); total_pay+=tmp_pay;
        if (tmp_pay>=tmp_pay_pre) index=i;
        data >> tmp_date; date.push_back(tmp_date);
        i++;
    }

    for (int i=0; i<pay.size();i++)
        cout << f_name[i] << '\t' << s_name[i] << '\t' << pay[i] << '\t' << date[i] << endl;

    cout << "Total pay is: " << total_pay << endl;
    cout << "Max pay is: " << pay[index] << endl;
    cout << "Customer with max pay is: " << f_name[index] << " " << s_name[index];

    return 0;
}

#include <iostream>
using namespace std;

string create_second_vocabulary()
{
    string second_vocabulary;
    for (int i='A'; i<='Z';i++)
        second_vocabulary+=(char)i;
    for (int i='a'; i<='z';i++)
        second_vocabulary+=(char)i;
    for (int i='0'; i<='9';i++)
        second_vocabulary+=(char)i;
    second_vocabulary+='-';
    second_vocabulary+='.';
    return second_vocabulary;
}

string create_first_vocabulary()
{
    string first_vocabulary;
    first_vocabulary=create_second_vocabulary()+"!#$%&'*+-/=?^_`{|}~";
    return first_vocabulary;
}

bool check_part(string part, int num)
{
    bool check;
    string voc;
    if (num==1)
        voc= create_first_vocabulary();
    if (num==2)
        voc= create_second_vocabulary();
    for (int i=0;i<part.length();i++)
    {
        check=0;
        for (int j=0; j<voc.length(); j++)
        {
            if (part[i]!=voc[j])
                continue;
            check=1;
        }
        if(part[i]=='.' && part[i+1]=='.') check=0;
        if (check==0) break;
    }
    if(part[0]=='0'||part[part.length()]=='0') check=0;
    if (num==1)
        if (part.length()<1 || part.length()>64) check=0;
    if (num==2)
        if (part.length()<1 || part.length()>63) check=0;

    return (check==1? 1:0);
}

bool check_email(string email)
{
    string first_part, second_part;
    int AT_counter=0;
    bool check;

    for (int i=0; i<email.length(); i++)
    {
        if (email[i]=='@') AT_counter++;
        else if(email[i]!='@'&&AT_counter==0) first_part+=email[i];
        else if(email[i]!='@'&&AT_counter==1) second_part+=email[i];
    }
    if (AT_counter==0||AT_counter>1)
    {
        return 0;
    }
    check = check_part(first_part,1);
       if(check==1)
           check = check_part(second_part,2);
    return (check==1? 1:0);
}

int main() {
    cout << "E-mail check" << std::endl;
    string email;
    cout << "Enter E-mail: " << endl;
    getline(cin, email);
    cout << (check_email(email)==1? "Yes" : "No") << endl;
    return 0;
}
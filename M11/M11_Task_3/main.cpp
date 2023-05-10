#include <iostream>
using namespace std;

bool check_part (string part)
{
    for (int i=0; i<part.length();i++)
    {
        if (part.length()==1)
        {if (part[0]<'0' || part[0]>'9') return 1;}
        else if (part.length()==2)
        {if (part[0]<'1' || part[0]>'9') return 1;
            if (part[1]<'0' || part[1]>'9') return 1;}
        else if (part.length()==3)
        {if (part[0]<'1' || part[0]>'2') return 1;
            else if (part[0]=='1')
            {if (part[1]<'0' || part[1]>'9' || part[2]<'0' || part[2]>'9') return 1;}
            else if (part[0]=='2')
            {if (part[1]<'0' || part[1]>'5' || part[2]<'0' || part[2]>'5') return 1;}
        }
    }
    return 0;
}

bool IP_check (string IP)
{   int dot_counter=0;
    string part;
    bool check = 0;
        for (int i=0; i<IP.length(); i++)
            {if (IP[i] != '.') part += IP[i];
             if (IP[i]=='.'|| IP[i+1]=='\0')
             {if (IP[i]=='.') dot_counter++;
               check = check_part(part);
               if (check==1) return 1;
               part.clear();
               if (IP[i+1]=='.') return 1;
             }}
    if (dot_counter==0||dot_counter>3) return 1;
    return check;
}

int main() {
    cout << "IP validation" << std::endl;
    string IP;
    cout <<"Enter IP address: " << endl;
    getline(cin, IP);
    cout << (IP_check(IP)==1? "No":"Yes") << endl;
    return 0;
}
#include <iostream>

using namespace std;

bool check(char *s1, char*s2)
{
    bool ch=false;
    int i=0, k=0;
    while (*(s1+i)!='\0')
        {
            if (*(s1+i)==*s2)
            {
                k=i;
                int j=0;
                while (*(s2+j)!='\0')
                {
                    if (*(s1+k)==*(s2+j))
                    {
                      ch = true;
                    } else ch = false;
                    k++;j++;
                }
                if (ch) return ch;
            }
            i++;
        }

    return ch;
}

int main() {
    cout << "Task 3" << endl;

    char* a = "Hello world";
    char* b = "wor";
    char* c = "banana";

    cout << check(a,b) << " " << check(a,c);

    return 0;
}

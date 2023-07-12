#include <iostream>
#include "sstream"
#include "cmath"

using namespace std;

int main() {
   cout << "Calculator" << endl;
   string inp;
   double a=0,b=0,res=0;
   char operation;
   cin >> inp;
   stringstream buffer_string(inp);
   buffer_string >> a >> operation >> b;

   if (operation=='+')
       res=a+b;
   else if (operation=='-')
       res=a-b;
   else if (operation=='*')
       res=a*b;
   else if (operation=='/')
       res=a/b;

   cout << a << operation << b << "=" << res << endl;
   return 0;
}

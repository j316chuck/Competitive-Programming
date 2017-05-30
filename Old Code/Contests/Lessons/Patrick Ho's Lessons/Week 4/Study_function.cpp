#include <iostream>
using namespace std;

bool iseven(int n);
//always put it above
int main()
{
    int input;
    cin>>input;

    if(iseven(input))
    {
        cout<<"even\n";
    }
     else
     {
         cout<<"odd\n";
     }
}

bool iseven(int n)
{
       if(n&1>0)
       {
           return false;
       }

       else
       {
           return true;
       }
}

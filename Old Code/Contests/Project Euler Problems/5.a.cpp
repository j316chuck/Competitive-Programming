#include <iostream>
using namespace std;

int fact(int n)
{
if(n==0)
return 1;
else
return n*fact(n-1);
}

int main()
{
    for(int i=1; i <100000; i++)
    {
        if(i%20*19*18*17*16*15*14*13*12*11*2520==0)
        {
            cout<<i<<endl;

        }
    }
}

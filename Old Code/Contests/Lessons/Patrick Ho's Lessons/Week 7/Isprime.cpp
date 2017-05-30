#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int a)
{
   for(int i = 2; i <=sqrt(a); i++ )
   {
       if(a%i==0)
        return false;
        break;
   }

    return true;
}


int main()
{
    cout<<isPrime(6)<<' '<<isPrime(7)<<endl;
}

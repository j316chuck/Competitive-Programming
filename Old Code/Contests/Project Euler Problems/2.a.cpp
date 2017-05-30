#include <iostream>
using namespace std;

long long Fibonacci(int x)
{
    long long first = 1, second = 2;
    long long replacement;

    for(int i = 0; i < x-1; i++)
    {
        replacement = second;
        second = first + replacement;
        first = replacement;

    }
    cout<<first<<endl;
    return first;

}

int main()
{
    long long sum = 0;
    int c = 0;

   for(int a = 0 ; a < 1000000; a++)
   {
       if (Fibonacci(a)>=4,000,000)
       {
           c = a;
       }
   }

   for(int b=0; b<c ;b++)
   {
       if(Fibonacci(b)%2==0)
       {
           sum = sum+Fibonacci(b);
           cout<<sum<<endl;
       }
   }

   cout<<sum<<endl;
}

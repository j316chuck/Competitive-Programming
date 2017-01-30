#include <iostream>
using namespace std;

int main()
{
    int sum=0;
    int square=0;

    for(int i=1; i<101; i++)
    {
        sum=sum+i;
    }

    for(int b=1; b<101; b++)
    {
       square=square+b*b;
    }

    cout<<sum*sum-square<<endl;
}

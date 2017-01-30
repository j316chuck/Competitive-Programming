#include <iostream>
using namespace std;

int main()

{
    int x;
    cin>>x;

    int prime[10000];
    int counter=0;
    int number=2;

    for(int i=2; i<x/2;i++)
    {
        for(int k=2; k<i; k++)
        {
            if (i%k==0)
                counter=counter+1;
        }

       if(counter=0)
       {
           prime[i-2]=i;
       }

       counter=0;
    }

    for(int k=0; k <x; k++)
    {
        if(x%prime[k]==0&&prime[k]>number)
            number=prime[k];

    }

    cout<<number<<endl;
}

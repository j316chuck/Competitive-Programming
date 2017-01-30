#include <iostream>
using namespace std;

int main()
{

    unsigned long long int k = 1;
    unsigned long long int a = 1;

    for(int i = 1; i < 21; i++)
    {
        a = i*a;
    }

    for(int i = 21; i < 41; i++)
    {
        k = i*k;
    }


cout<<a<<endl;
cout<<k<<endl;
    cout<<k/a;

}

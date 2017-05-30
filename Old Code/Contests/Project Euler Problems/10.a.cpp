#include <iostream>
using namespace std;

int Prime(int n)
{
    int counter = 0;

    for(int k = 2; k < n/2+1; k++){
        if(n%k == 0)
        {
            return 0;
        }
    }

        return 1;

}

int main()
{
    int n;
    long long sum= 2;

    for(n = 3; n < 2000000; n++)
    {
        if(Prime(n)== 1)
        {
            sum = sum + n;

        }

    }

    cout<<sum;

}

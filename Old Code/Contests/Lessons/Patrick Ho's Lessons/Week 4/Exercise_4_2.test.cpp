#include <iostream>
using namespace std;

int main()
{
    char a[5];

    int sum = 0;

    for(int i = 0; i < 5; i++)
    {
        cin>>a[i];
    }

    for(int i = 0; i < 5; i++)
    {
        sum = sum+ (a[i]-'0');
    }

}

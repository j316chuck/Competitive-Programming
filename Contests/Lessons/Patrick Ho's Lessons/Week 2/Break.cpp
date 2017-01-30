#include <iostream>
using namespace std;

int main()
{
    int a;
    cin>>a;
    int sum = 0;
    int k[100];

    for(int i = 0; i < a; i++)
    {
        cin>>k[i];
        sum = sum + k[i];

        if(k[i]== 3)
        {
            cout<<sum<<'\n';
            break;

        }
    }
}

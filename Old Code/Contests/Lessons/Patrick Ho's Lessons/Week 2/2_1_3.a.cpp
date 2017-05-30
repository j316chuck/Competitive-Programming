#include <iostream>
using namespace std;

int main()
{
    int b[100];
    int a;
    cin>> a;

    for(int i = 1; i < a + 1; i++)
    {
        cin>>b[i];
    }
    for(int i = 1 ; i < a + 1; i++)
    {
        cout<<b[i]<<" ";
        if(i % 5 == 0)
        {
            cout<<""<<endl;
        }
    }
}

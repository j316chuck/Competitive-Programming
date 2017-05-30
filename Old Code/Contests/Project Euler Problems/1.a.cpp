#include <iostream>
using namespace std;

int main()
{
    int sum = 0;

    for(int i = 0; i < 1000; i++)
    {
        if(i%3 == 0 || i%5==0)
        {
            sum = sum + i;
             cout<<sum<<endl;
        }
    }

    cout<<3%100<<endl;


}

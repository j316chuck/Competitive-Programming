#include <iostream>
using namespace std;

int main()
{
    int input;
    cin>>input;
    int arr[100];

    for(int i = 0; i < input; i++)
    {
        cin>>arr[i];
    }
    int counter = 0;
    int counter1 = 0;


    for(int i = 0; i <input; i++)
    {
        if(i==0)
        {
            cout<<"EVEN:"<<'\n';
        }

        if(arr[i]%2 == 0)
        {
            cout<<arr[i]<<" ";
            counter++;
            if(counter%5==0)
            {
                cout<<'\n';
            }
        }
    }

cout<<'\n';
    for(int i = 0; i <input; i++)
    {
        if(i==0)
        {
            cout<<"ODD:"<<'\n';
        }

        if(arr[i]%2 == 1)
        {
            cout<<arr[i]<<" ";
            counter1++;
            if(counter1%5==0)
            {
                cout<<'\n';
            }
        }
    }
}

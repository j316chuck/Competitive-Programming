#include <iostream>
using namespace std;
bool c;
int main()
{
    for(int i = 0; i < 10; i=i+4)
    {
        if(i%2==0)
            cout<<"two"<<endl;
        if(i%4==0)
            cout<<"four"<<endl;
    }

    cout<<c<<endl;
    if(10%2==0)
    {
        c=true;
        cout<<c<<endl;
    }
}

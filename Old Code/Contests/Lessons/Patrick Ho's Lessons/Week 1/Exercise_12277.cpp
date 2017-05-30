#include <iostream>
using namespace std;

int main()
{
    float a;
    cin>>a;
    int dummy;
    dummy = a/2.54;
    float dummmy;
    dummmy = a/2.54;
    int feet;
    feet = dummy/12;

    cout<<a<<" centimeters is: "<<feet<<" feet and "<< dummy-feet*12<<" inches."<<endl;
}

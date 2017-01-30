#include <iostream>
using namespace std;

int main()
{
    int a;
    cin>>a;
    int hour, minute, second;

    hour = a/3600;
    minute = a/60 - (a/3600)*60;
    second= ((a-(a/60)*60)) -((a-(a/60)*60)/60)*60;

    cout<<hour<<" "<<minute<<" "<<second<<endl;
}

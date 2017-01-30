#include <iostream>
using namespace std;

int main()
{
    bool ret = (7 != 7);
    cout<<ret<<"\n";
    if(ret == 0)
    {
        cout<<"true"<<endl;
    }
    else cout<<"false"<<endl;


    int ia=9; int ib =10;
    bool ret1 = (ia > ib);
    cout<<ret1<<"\n";

}

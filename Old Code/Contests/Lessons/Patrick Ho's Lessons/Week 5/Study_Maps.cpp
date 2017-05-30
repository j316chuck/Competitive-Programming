#include <iostream>
#include <map>
using namespace std;

int main()
{
    /*

    map<char, int> mymap;
    map<char, int> :: iterator it;

    mymap['b']=100;
    mymap['a']=200;
    mymap['a']=250;
    mymap['c']=300;

    for(it = mymap.begin(); it!=mymap.end(); it++)
    {
        cout<<it->first<<' '<<it->second<<endl;
    }
    */
    map<int, string> mymap;

    mymap[6]="aslkdjas";
    mymap[7]="aslkdjas";
    mymap[5]="aslkdjas";



    map<int, string>::iterator itr;

    for(itr = mymap.begin(); itr != mymap.end(); itr++)
    {
        cout<<(*itr).first<<' '<<(*itr).second<<endl;
    }
}

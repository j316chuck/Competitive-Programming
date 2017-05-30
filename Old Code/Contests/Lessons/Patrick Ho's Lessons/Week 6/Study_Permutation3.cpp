#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>
#include <numeric>
#include <ctime>
#include <climits>
#include <cstdlib>
using namespace std;

class box {
    public:
    string name;
    int age;

    bool operator < (const box &a) const {
        if(a.age>age)
            return true;
        else if(a.age<age)
            return false;
        return name> a.name;
    }
};


int main()
{
    set<box> myarray;
    int N;
    cin>>N;

    for(int i = 0; i < N; i++) {
        box a;
        cin >> a.name >> a.age;
        myarray.insert(a);
        /*
        string str;
        int random;
        cin>>str>>random;

        box a;
        a.age = random;
        a.name = str;
        myarray.insert(a);
        */
    }
    set<box>::iterator itr = myarray.begin();

    //conversion of set to vector
    vector<box> thing(myarray.begin(), myarray.end());
    do {

    } while (next_permutation(thing.begin(), thing.end()));
/*
    string middle = (*itr).name;
    string totalset[100];
    myarray.erase(itr);
    int c = 0;
    for(itr = myarray.begin(); itr!= myarray.end(); itr++)
    {

        totalset[c]= (*itr).name;
        c++;
    }
    vector<string> totalname;
    /*
    for(int i = 0; i < N-1; i++)
    {
        cout<<totalset[i]<<endl;
    }*/
/*
    int x = 0;
     do
    {
       for(int i = 0; i < N; i++)
       {

            totalname[x]+=totalset[i];
       }
       x++;
       cout<<totalname[x];
        cout<<'\n';
    }
    while(next_permutation(totalset, totalset+N));

for(int i = 0; i < totalname.size(); i++)
{
    totalname[i].insert(totalname.begin()+N/2, middle);
    cout<<totalname[i]<<endl;
}
*/

}

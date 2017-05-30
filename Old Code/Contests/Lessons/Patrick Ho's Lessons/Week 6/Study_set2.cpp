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

class box
{
    public:
    int age;
    string name;

    bool operator <(const box &a) const
    {
        if(a.age>age)
            return true;
        else if(a.age<age)
            return false;
        return name> a.name;
    }
};
int main()
{
    set<box> mySet;

    int N;
    cin>>N;

    for(int i = 0; i < N; i++)
    {
        box a;
        cin>>a.name>>a.age;
        mySet.insert(a);
    }

    cout<<mySet.size()<<'\n';
    //set<box>:: iterator itr = mySet.find(100);
    //cout<<(*itr).age<<' '<<(*itr).name<<'\n';




}


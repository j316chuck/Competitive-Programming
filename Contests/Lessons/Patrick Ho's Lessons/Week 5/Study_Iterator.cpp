/*
ID:j316chuck
PROG:gift1
LANG: C++
 */
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

const double Pi=acos(-1.0);


#define Set(a, s) memset(a, s, sizeof (a))
#define Rd(r) freopen(r, "r", stdin)
#define Wt(w) freopen(w, "w", stdout)

using namespace std;

int main()
{
    string s;

    cin>>s;

    int sL = s.size();

    cout<<"size = "<<sL<<'\n';

    for(int i = 0; i < sL; i++)
    {
        cout<<s[i];
    }
    cout<<'\n';

    //use itr

    string::iterator itr = s.begin();
    while(itr!=s.end())
    {
        cout<<(*itr);
        itr++;
    }
    cout<<'\n';
    //use reverse_iterator

    string::reverse_iterator ritr = s.rbegin();
    for(;ritr!=s.rend();ritr++)
    {
        cout<<(*ritr);
    }
    cout<<'\n';
}

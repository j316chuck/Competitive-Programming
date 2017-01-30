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
   int a;
   cin>>a;
   vector<int> b;
   for(int i = 0; i < a; i++)
   {
       int k;
       cin>>k;
       b.push_back(k);
   }

    vector<int>::iterator itr = b.begin();
    itr = b.begin();

    while(itr!=b.end())
    {
        cout<<*(itr);
        itr++;
    }
}

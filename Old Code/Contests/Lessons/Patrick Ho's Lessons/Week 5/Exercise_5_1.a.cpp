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

#define Set(a, s) memset(a, s, sizeof (a))
#define Rd(r) freopen(r, "r", stdin)
#define Wt(w) freopen(w, "w", stdout)


int main()
{
    map<string, double> value;

    int N;
    string name;
    int k;
    cin>>N;

    for(int i = 0; i < N; i++)
    {
        cin>>name;
        cin>>k;
        value[name]=k;
    }

    map<string, double> iterator:: it = value.begin();
    int length = value.size();
    sort((*it).second,  (*it).second+length, myComp);

    //sort(value.begin(), value.end(), myComp);
}

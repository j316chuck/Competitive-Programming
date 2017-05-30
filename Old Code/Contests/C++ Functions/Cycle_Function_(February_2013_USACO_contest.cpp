/*
ID: j316chuck
PROG: relay
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

const double Pi=acos(-1.0);
typedef long long LL;

#define Set(a, s) memset(a, s, sizeof (a))
#define Rd(r) freopen(r, "r", stdin)
#define Wt(w) freopen(w, "w", stdout)
using namespace std;


vector<int> mygraph;
vector<int> mycycle;

int cyclical (int position)
{
    if(mygraph[position]==-1){
        mycycle.clear();
        return 1;
    }
    for(int i=0; i <mycycle.size(); i++)
    {
       //cout<<mycycle[i]<<' ';
        if(mycycle[i]==mygraph[position])
        {
            mycycle.clear();
            return 0;
        }
    }
    //cout<<endl;
    mycycle.push_back(position);
    cyclical(mygraph[position]);

}
int main()
{
    Rd("relay.in");
    Wt("relay.out");
    int N;
    cin>>N;
    for(int i=0; i <N; i++)
    {
        int a;
        cin>>a;
        mygraph.push_back(a-1);
    }
    int counter=0;

    for(int i=0; i <N; i++)
    {
        counter=counter+cyclical(i);
        //cout<<counter<<endl;
    }
    cout<<counter<<endl;
}

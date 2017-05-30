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

class node
{
   public:
    int begin;
    vector<int> amount;
    vector<int> children;
};
class edgelist
{
public:
    int start;
    int end;
    int weight;
};

int main()
{
    int N;
    cin>>N;
    vector<edgelist> mygraph;
    for(int i = 0; i < N; i++)
    {
      edgelist k;
       cin>>k.start>>k.end>>k.weight;
       mygraph.push_back(k);
    }
    vector<node> realgraph;
    for(int i = 0; i < N; i++)
    {
        for(int k = 0; k <i+1; k++)
        {
            if(mygraph[k].start==mygraph[i].start)
            {
                realgraph[i].begin==mygraph[i].start;
                realgraph[i].children.push_back(mygraph[k].end);
                realgraph[i].amount.push_back(mygraph[k].weight);
            }
        }
    }

    for(int i = 0; i < N; i++)
    {
        cout<<realgraph[i].begin<<endl;
    }




}

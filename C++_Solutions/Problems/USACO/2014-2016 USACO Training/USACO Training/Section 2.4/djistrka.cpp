/*
ID: peiqistar1
PROG: StudyDijkstra
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
typedef long long LL;

#define Set(a, s) memset(a, s, sizeof (a))
#define Rd(r) freopen(r, "r", stdin)
#define Wt(w) freopen(w, "w", stdout)

using namespace std;

class pp{
public:
    int v, w;
    bool operator <(const pp&a) const
    {
        return w>a.w;
    }
};

int main(){

    Rd("dij.in");

    int n, m;

    cin>>n>>m;
    vector<pp> G[n+1];

    //cout<<n<<m<<endl;

    for(int i = 0; i < m; i++){
        pp ei;
        int s;
        cin>>s>>ei.v>>ei.w;
        G[s].push_back(ei);
    }
    int d[101];
    for(int i = 1; i <= n; i++){
        d[i] = 999;
    }
    int src;
    cin>>src;

    d[src] = 0;
    pp ei;
    ei.v = src;
    ei.w = d[src];
    priority_queue<pp> Q;

    Q.push(ei);
    while(!Q.empty()){
        int u = Q.top().v;
        Q.pop();
        for(int i = 0; i < G[u].size(); i++){
            int v = G[u][i].v;
            int w = G[u][i].w;
            if(d[u]+w < d[v]){
                d[v] = d[u]+w;
                pp ai;
                ai.v = v;
                ai.w = d[v];
                Q.push(ai);
            }
        }
    }
    for(int i = 1; i <= n; i++){
        cout<<d[i]<<endl;
    }

}

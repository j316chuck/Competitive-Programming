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
    priority_queue<pp> Q;
    int n;
    cin>>n;
    vector<pp> G[n+1];
    int e,u,v,w;
    cin>>e;


    for(int i=0; i<e; i++){
        cin>>u>>v>>w;
        pp e;
        e.v=v;
        e.w=w;
        G[u].push_back(e);
    }

    int s;
    cin>>s;
    int d[n+1];
    for(int i=1; i<=n; i++){
        d[i]=999;
    }
    d[s]=0;
    pp ei;
    ei.v=s;
    ei.w=d[s];
    Q.push(ei);

    while(!Q.empty()){
        u=Q.top().v;
        Q.pop();
        for(int i=0; i<G[u].size(); i++){
            v=G[u][i].v;
            w=G[u][i].w;
            if(d[v]>d[u]+w){
                d[v]=w+d[u];
                pp a;
                a.v=v;
                a.w=d[v];
                Q.push(a);
            }
        }
    }
    for(int i=1; i<=n; i++){
        cout<<"node "<<i<<": "<<d[i]<<endl;
    }
}

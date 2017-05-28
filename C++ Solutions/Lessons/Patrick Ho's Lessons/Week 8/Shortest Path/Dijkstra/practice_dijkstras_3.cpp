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
    bool operator < (const pp & a) const{
        return (w > a.w); //sort from low to high
    }
};

int main(){

    Rd("dij.in");

    priority_queue<pp> Q;
    int n;
    cin>>n;
    vector<pp> G[n+1];
    int e;
    cin>>e;
    for(int i = 0; i < e; i++){
        int u, v, w;
        cin>>u>>v>>w;
        pp a;
        a.v = v;
        a.w = w;
        G[u].push_back(a);
    }
    int dist[n+1];
    for(int i = 1; i <=n; i++){
        dist[i] = INT_MAX;
    }
    int s;
    cin>>s;
    dist[s] = 0;
    pp ei;
    ei.v = s;
    ei.w = dist[s];

    Q.push(ei);
    while(!Q.empty()){
        int u = Q.top().v;
        Q.pop();
        for(int i = 0; i < G[u].size(); i++){
            if(dist[u]+ G[u][i].w < dist[G[u][i].v]){
                dist[G[u][i].v] = dist[u]+ G[u][i].w;
                pp ei;
                ei.v = G[u][i].v;
                ei.w = dist[ei.v];
                Q.push(ei);
            }
        }
    }
    for(int i = 1; i <=n; i++)
        printf("node %d: %d\n", i, dist[i]);
}

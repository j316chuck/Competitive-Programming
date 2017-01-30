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
    priority_queue <pp> Q;
    int n, e, u , v , w;
    cin>>n>>e;
    vector<pp> G[n+1];
    //cout<<n<<e<<endl;
    for(int i = 0; i < e; i++){
        cin>>u>>v>>w;
        pp ei; ei.v = v; ei.w = w;
        G[u].push_back(ei);
    }
    int dist[n+1];
    for(int i = 0; i <= n; i++){
        dist[i] = 99999;
    }
    int s;
    cin>>s;
    //cout<<s<<endl;
    dist[s] = 0;
    pp ei;
    ei.v = s;
    ei.w = dist[s];
    Q.push(ei);
    while(!Q.empty()){
        u = Q.top().v;
        Q.pop();
        for(int i = 0; i < G[u].size(); i++){
            w = G[u][i].w;
            v = G[u][i].v;
            if(dist[u]+w < dist[v]){
                dist[v] = dist[u]+w;
                pp ei;
                ei.v = v;
                ei.w = dist[v];
                Q.push(ei);
            }
        }
    }
    for(int i = 1; i <=n; i++)
        printf("node %d: %d\n", i, dist[i]);
}

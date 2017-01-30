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
    bool operator < (const pp &a) const{
        return w > a.w;
    }
};

int main(){
    //freopen("poj_2387.in", "r", stdin);
    int t, n, u, v, w;
    cin>>t>>n;
    vector<pp> G[1005];

    for(int i = 0; i < t; i++){
        cin>>u>>v>>w;
        pp ei; ei.v = v; ei.w = w;
        pp ai; ai.v = u; ai.w = w;
        G[u].push_back(ei);
        G[v].push_back(ai);
    }

    int dist[1005];
    for(int i = 1; i <= n; i++){
        dist[i] = INT_MAX;
    }
    dist[1] = 0;
    pp ei;
    ei.v = 1;
    ei.w = dist[1];
    priority_queue<pp> Q;
    Q.push(ei);
    while(!Q.empty()){
        int u = Q.top().v;
        Q.pop();

        for(int i = 0; i < G[u].size(); i++){
            int v = G[u][i].v;
            int w = G[u][i].w;
            if(dist[v] > dist[u]+w){
                dist[v] = dist[u]+w;
                pp ai;
                ai.v = v;
                ai.w = dist[u]+w;
                Q.push(ai);
            }
        }
    }

    cout<<dist[n]<<endl;
}

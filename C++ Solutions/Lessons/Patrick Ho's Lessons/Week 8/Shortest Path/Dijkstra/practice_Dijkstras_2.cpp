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
        return w > a.w;
    }
};

int main(){

    freopen("dij.in","r", stdin);

    int n;
    cin>>n;
    priority_queue<pp> Q;
    vector<pp> G[n+1];

    int e, u, v, w;
    cin>>e;
    //cout<<e<<endl;
    for(int i = 0; i < e; i++){
        cin>>u>>v>>w;
        pp k;
        k.v = v, k.w = w;
        G[u].push_back(k);
        //cout<<v<<' '<<w<<endl;
    }

    int s;
    cin>>s;
    int dist[n+1];
    for(int i = 1; i <= n; i++){
        dist[i] = 999;
    }
    dist[s] = 0;
    pp ei;
    ei.v = s;
    ei.w = dist[s];
    Q.push(ei);
    while(!Q.empty()){

        u = Q.top().v;
        Q.pop();

        for(int i = 0; i < G[u].size(); i++){
            if(G[u][i].w + dist[u] < dist[G[u][i].v]){
                dist[G[u][i].v] = G[u][i].w + dist[u];
                pp a;
                a.v = G[u][i].v;
                a.w = G[u][i].w;
                Q.push(a);
            }
        }
    }
    for(int i=1; i<=n; i++){
        cout<<"node "<<i<<": "<<dist[i]<<endl;
    }
}

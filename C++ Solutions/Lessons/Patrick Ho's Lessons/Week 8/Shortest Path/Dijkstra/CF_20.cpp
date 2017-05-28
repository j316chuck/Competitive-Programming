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

int n, m;

class pp{
public:
    long long v, w;
    bool operator <(const pp&a) const
    {
        return w>a.w;
    }
};

int main(){

    freopen("CF_20.in", "r", stdin);
    cin>>n>>m;
    long long u, v, w;
    vector<pp> G[n+1];
    priority_queue<pp> Q;
    vector<int> parent;
    vector<long long> d;

    for(int i = 0; i <= n; i++){
        d.push_back(100000000000L);
        parent.push_back(-1);
    }

    for(int i = 0; i < m; i++){
        cin>>u>>v>>w;
        pp ei;
        ei.v = v; ei.w = w;
        G[u].push_back(ei);
        pp ai;
        ai.v = u; ai.w = w;
        G[v].push_back(ai);
    }
    d[1] = 0;
    pp ei;
    ei.v = 1;
    ei.w = d[1];
    Q.push(ei);

    while(!Q.empty()){
        u = Q.top().v;
        Q.pop();
        for(int i = 0; i < G[u].size(); i++){
            long long v = G[u][i].v;
            long long w = G[u][i].w;
            if(d[v] > d[u]+w){
                d[v] = d[u]+w;
                pp ai; ai.v = v; ai.w = d[v];
                Q.push(ai);
                parent[v] = u;
            }
        }
    }

    /*for(int i = 1; i <= n; i++){
        cout<<d[i]<<endl;
    }
    for(int i = 1; i <= n; i++){
        cout<<parent[i]<<endl;
    }*/

    if(parent[n] == -1){
        cout<<-1<<endl;
    }else{
        vector<int> p;
        int pos = n;
        while(pos != -1){
            p.push_back(pos);
            pos = parent[pos];
        }
        reverse(p.begin(), p.end());
        for(int i = 0; i< p.size(); i++){
            cout<<p[i]<<' ';
        }cout<<endl;
    }
}

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
#define pii pair<int, int>
using namespace std;

class pp{
public:
    int v, w;
    bool operator<(const pp&a) const
    {
        return w>a.w;
    }
};

/*class ff{
public:
    int a, b, c;
    bool operator <(const ff&d) const
    {
        if(d.a>a) return true;
        if(d.a<a) return false;
        if(d.b>d.b) return true;
        if(d.b<d.b) return false;
        if(d.c>=c) return true;
        return false;
    }
};*/

int main(){
    ios::sync_with_stdio(false);
    Rd("CF_59E.in");

    int n, m, k, x, y;
    cin>>n>>m>>k;

    priority_queue<pp> Q;
    vector<pp> G[n+1];
    int parent[n+1];
    int d[n+1];
    set< pair<int, pii> > F;

    for(int i = 0; i < m; i++){
        cin>>x>>y;
        pp ei; ei.v = y; ei.w = 1;
        G[x].push_back(ei);
        ei.v = x; ei.w = 1;
        G[y].push_back(ei);
    }

    int a, b, c;
    for(int i = 0; i < k; i++){
        cin>>a>>b>>c;
        pp ei; ei.v = b; ei.w = 1;
        pp ai; ai.v = c; ai.w = 1;
        //vector<pp>::iterator it;
        //it = find(G[a].begin(), G[a].end(), ei);
        //vector<pp>::iterator itr;
        //itr = find(G[b].begin(), G[b].end(), ai);
        //if(it !=G[a].end() && itr !=G[b].end())
        F.insert(make_pair(a, make_pair(b, c)));
    }

    for(int i = 0; i <= n; i++){
        parent[i] = -1;
        d[i] = 999999;
    }

    d[1] = 0;
    pp ei;
    ei.v = 1;
    ei.w = 1;
    Q.push(ei);
    bool nopath = true;
    pair<int, pii > curr;
    curr.first = -9999;
    curr.second.first = -9999;
    curr.second.second = 1;
    /*for(set< pair<int, pii> >::iterator it = F.begin(); it!=F.end(); it++){
        cout<<(*it).second.first<<endl;
    }*/

    while(!Q.empty()){

        int u = Q.top().v;
        Q.pop();
        curr.first = curr.second.first;
        curr.second.first = curr.second.second;
        curr.second.second = u;


        if(u == n){
            nopath = false;
            cout<<d[n]<<endl;
            vector<int> result;
            while(u != -1){
                result.push_back(u);
                u = parent[u];
            }
            reverse(result.begin(), result.end());
            for(int i = 0; i < result.size(); i++){
                cout<<result[i]<<' ';
            }cout<<endl;
            break;
        }

        for(int i = 0; i < G[u].size(); i++){
            int v = G[u][i].v;
            int w = G[u][i].w;
            if(d[u]+w < d[v]){
                d[v] = d[u]+w;
                parent[v] = u;
                pp ai;
                ai.v = v;
                ai.w = d[v];
                Q.push(ai);
            }
        }
    }

    if(nopath)
        cout<<-1<<endl;

    return 0;
}

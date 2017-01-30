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
    int u, v, w;
};
/*class pp{
public:
    int s, d, w;
};*/

vector<pp> G;
int n, m;

bool bellmanford(int src){

    int dis[151];
    for(int i = 0; i < n; i++){
        dis[i] = 99999;
    }
    //src;
    dis[src] = 0;

    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < m; j++){
            int u = G[j].u;
            int v = G[j].v;
            int w = G[j].w;
            if(dis[v] > dis[u]+w){
                dis[v] = dis[u]+w;
            }
        }
    }
    for(int j = 0; j < m; j++){
        int u = G[j].u;
        int v = G[j].v;
        int w = G[j].w;
        if(dis[v] > dis[u]+w){
            return false;
        }
    }

    for(int i = 0; i < n; i++){
        cout<<dis[i]<<endl;
    }
    return true;


}

int main(){

    Rd("bellman.in");

    cin>>n>>m;

    for(int i = 0; i < m; i++){
        pp ei;
        cin>>ei.u>>ei.v>>ei.w;
        G.push_back(ei);
    }
    /*for(int i = 0; i < m; i++){
        cout<<G[i].u<<' '<<G[i].v<<' '<<G[i].w<<endl;
    }*/
    bellmanford(0);
}

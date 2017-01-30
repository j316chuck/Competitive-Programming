/*ID: j316chuck
PROG: closing
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
const int MAXN = 1000010;

using namespace std;

int u[MAXN], v[MAXN], order[MAXN], place[MAXN]; bool res[MAXN];
int parent[MAXN];
int n, m;

void initset(int n){
    for(int i = 0; i < n+1; i++){
        parent[i] = i;
    }
}

/*int findset(int x){
    (x == parent[x]) ? x : parent[x] = findset(parent[x]);
}*/
int union_query(int d[], int n) { int res=n; while (d[res]!=res) res=d[res]; int m; while (d[n]!=n) {m=d[n];d[n]=res;n=m;} return res; };
int union_merge(int d[], int x, int y) { x=union_query(d,x); y=union_query(d,y); if (x==y)return -1; d[x]=y; return 1; }



int main(){

    freopen("closing.in", "r", stdin);
    //freopen("closing.out", "w", stdout);

    cin>>n>>m;
    vector<int> adj[n+1];
    initset(n);

    for(int i = 0; i < m; i++){
        cin>>u[i]>>v[i];
    }
    for(int j = 0; j < n; j++){
        cin>>order[j];
        place[order[j]] = j;
    }

    for(int i = 0; i < m; i++){
        if(place[u[i]] > place[v[i]]){
            adj[v[i]].push_back(u[i]);
        }else{
            adj[u[i]].push_back(v[i]);
        }
    }

    int comp = 0;
    /*for(int i = n-1; i >= 0; i--){
        int u = order[i];
        int pu = findset(u);
        comp++;

        for(int j = 0; j < adj[u].size(); j++){
            int v = adj[u][j];
            int pv = findset(v);
            if(pu != pv){
                parent[pu] = parent[pv];
                comp--;
            }
        }
        res[i] = (comp <= 1);
    }*/
    for(int i = n-1; i>=0; i--){
        int u = order[i]; comp++;
        for(int j = 0; j < adj[u].size(); j++){
            int v = adj[u][j];
            if(union_query(parent, u) != union_query(parent, v)){
                union_merge(parent, u, v);
                comp--;
            }
        }
        res[i] = (comp <= 1);
    }

    for(int i = 0; i < n; i++){
        res[i] ? printf("YES\n") : printf("NO\n");
    }
}

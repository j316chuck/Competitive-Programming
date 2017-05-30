/*ID: j316chuck
PROG: 248
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
const int MAXN = 100010;

using namespace std;

int u[MAXN], v[MAXN], order[MAXN], place[MAXN]; bool res[MAXN];
int parent[MAXN];

void initset(int n){
    for(int i = 0; i < n+1; i++){
        parent[i] = i;
    }
}

int findset(int x){
    (x == parent[x]) ? x : parent[x] = findset(parent[x]);
}

void unionset(int x, int y){
    int pu = findset(x);
    int pv = findset(y);
    if (pu!=pv){
        parent[pu] = parent[pv];
    }
}

int main(){

    freopen("closing.in", "r", stdin);
    freopen("closing.out", "w", stdout);

    int n, m;
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
    for(int i = n-1; i >= 0; i--){
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
    }

    for(int i = 0; i < n; i++){
        res[i] ? printf("YES\n") : printf("NO\n");
    }
}


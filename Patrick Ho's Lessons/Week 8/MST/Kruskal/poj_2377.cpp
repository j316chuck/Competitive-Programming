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

const double Pi=acos(-1.0);
typedef long long LL;

#define Set(a, s) memset(a, s, sizeof (a))
#define Rd(r) freopen(r, "r", stdin)
#define Wt(w) freopen(w, "w", stdout)
#define edge pair <int, int>
using namespace std;

long long n, e, total;
vector< pair<int, edge> > graph, mst;
int parent[1001];

int findset(int x, int *parent){
    if(x!=parent[x]){
        parent[x] = findset(parent[x], parent);
    }
    return parent[x];
}
void kruskal(){

    sort(graph.begin(), graph.end());
    reverse(graph.begin(), graph.end());

    for(int i = 0; i < e; i++){
        int pu = findset(graph[i].second.first, parent);
        int pv = findset(graph[i].second.second, parent);
        if(pu!=pv){
            total+=graph[i].first;
            mst.push_back(graph[i]);
            parent[pu] = parent[pv];
        }
    }
}
int main(){

    //Rd("poj_2377.in");

    cin>>n>>e;

    for(int i = 0; i < e; i++){
        int u, v, w;
        cin>>u>>v>>w;
        graph.push_back(pair<int, edge> (w, (edge (u, v))));
    }

    for(int i = 0; i < 1001; i++){
        parent[i] = i;
    }

    kruskal();

    /*bool connected = true;
    for(int i = 1; i <= n; i++){
        if(parent[i]!=parent[1]){
            connected = false;
        }
    }
    if(connected)
        cout<<total<<endl;
    else
        cout<<-1<<endl;*/
    if(mst.size()!=n-1){
        cout<<-1<<endl;
    }else{
        cout<<total<<endl;
    }
}

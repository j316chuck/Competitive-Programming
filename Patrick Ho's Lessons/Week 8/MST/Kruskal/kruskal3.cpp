/*
ID: peiqistar1
PROG:
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

const double Pi=acos(-1.0);
typedef long long LL;

#define Set(a, s) memset(a, s, sizeof (a))
#define Rd(r) freopen(r, "r", stdin)
#define Wt(w) freopen(w, "w", stdout)

using namespace std;

#define edge pair< int, int >
#define MAX 1001

vector< pair<int, edge > > graph;
vector< pair<int, edge> > mst;
int parent[1001];
int n, e, total;

void reset(){
    graph.clear();
    mst.clear();
    for(int i = 1; i <= n; i++){
        parent[i] = i;
    }
}

int findset(int x, int *parent){

    /*if(x!=parent[x])
        parent[x] = findset(parent[x], parent);
    */
    while(x!=parent[x]){
        x = parent[x];
    }
    return parent[x];
}

void kruskal(){

    sort(graph.begin(), graph.end());

    for(int i = 0; i < e; i++){
        int pu = findset(graph[i].second.first, parent);
        int pv = findset(graph[i].second.second, parent);
        if(pu!=pv){
            mst.push_back(graph[i]);
            total+=graph[i].first;
            parent[pu] = parent[pv];
        }
    }
}

int main(){

    Rd("Kruskal.in");

    cin>>n>>e;

    int u, v, w;
    reset();
    for(int i = 0; i < e; i++){
        cin>>u>>v>>w;
        graph.push_back(pair< int, edge >(w, edge(u, v)));
    }
    kruskal();
    cout<<total<<endl;
    for(int i = 0; i < mst.size(); i++){
        printf("path: %d-%d weight: %d\n", mst[i].second.first, mst[i].second.second, mst[i].first);
    }
    /*for(int i = 0; i <= n; i++){
        printf("%d ")
    }*/
}

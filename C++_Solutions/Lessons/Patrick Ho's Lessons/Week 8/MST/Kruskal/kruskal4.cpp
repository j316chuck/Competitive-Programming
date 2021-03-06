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

vector< pair<int, pair<int, int> > > graph;
vector< pair<int, pair<int, int> > > mst;

int parent[MAX];
int n, e, total;

void reset(){
    mst.clear();
    graph.clear();
    for(int i = 1; i <= 1000; i++)
        parent[i] = i;
    return;
}

int findset(int x, int* parent){
    while(x != parent[x]){
        x = parent[x];
    }
    return x;
}

void kruskal(){
    sort(graph.begin(), graph.end());
    for(int i = 0; i < e; i++){
        int pu = graph[i].second.first;
        pu = findset(pu, parent);
        int pv = graph[i].second.second;
        pv = findset(pv, parent);
        if(pu!=pv){
            parent[pu] = parent[pv];
            total+=graph[i].first;
            mst.push_back(graph[i]);
        }
    }
}
int main(){

    Rd("Kruskal.in");

    cin>>n>>e;
    reset();
    for(int i = 0; i < e; i++){
        int u, v, w;
        cin>>u>>v>>w;
        graph.push_back(make_pair(w, make_pair(u, v)));
    }

    kruskal();
    cout<<total<<endl;
}


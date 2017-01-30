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

vector< pair <int, edge> > MST, GRAPH;
int parent[MAX];
int N, E,total;

int findset(int x, int *parent){
    if(x!=parent[x])
        parent[x]=findset(parent[x],parent);

    return parent[x];
}
void kruskal(){
    int pu, pv;

    sort(GRAPH.begin(), GRAPH.end());
    for(int i=0; i<E; i++){
        pu=findset(GRAPH[i].second.first, parent);
        pv=findset(GRAPH[i].second.second, parent);
        if(pu!=pv){
            total+=GRAPH[i].first;
            MST.push_back(GRAPH[i]);
            parent[pu]=parent[pv];
        }
    }
}


void print(){
    for(int i=0; i<MST.size(); i++){
        cout<<'('<<MST[i].second.first<<','<<MST[i].second.second<<"):"<<MST[i].first<<endl;
    }
    cout<<total<<endl;
}
int main()
{
    Rd("Kruskal.in");
    cin>>N>>E;
    for(int i=1; i <=N; i++){
        parent[i]=i;
    }
    int w, u, v;
    for(int i=0; i<E; i++){
        cin>>u>>v>>w;
        GRAPH.push_back(pair<int, edge>(w,edge(u,v)));
    }
    kruskal();
    print();
}


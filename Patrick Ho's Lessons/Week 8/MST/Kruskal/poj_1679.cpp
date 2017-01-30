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
#define edge pair<int, int>

using namespace std;

int t, n, e, total;
int parent[101];
vector< pair<int, edge> > graph, mst;
bool uni;

void reset(){
    graph.clear();
    mst.clear();
    for(int i = 0; i < 101; i++){
        parent[i] = i;
    }
    total = 0;
    uni = true;
}

int findset(int x, int *parent){
    while(x!=parent[x]){
        x = parent[x];
    }
    return x;
}

void kruskal(){

    sort(graph.begin(), graph.end());

    for(int i = 0; i < e; i++){
        int pu = findset(graph[i].second.first, parent);
        int pv = findset(graph[i].second.second, parent);
        if(pu!=pv){
            mst.push_back(graph[i]);
            total+=graph[i].first;
            if(mst.size() == n-1){
                int j = i+1;
                while(j < e && graph[j].first == graph[i].first){
                    int u = findset(graph[j].second.first, parent);
                    int v = findset(graph[j].second.second, parent);
                    if(u!=v){
                        uni = false;
                        break;
                    }
                    j++;
                }
            }
            parent[pu] = parent[pv];
        }
    }
}

int main(){

    //freopen("poj_1679.in", "r", stdin);

    cin>>t;
    for(int i = 0; i < t; i++){
        cin>>n>>e;
        int u, v, w;
        reset();
        for(int k = 0; k < e; k++){
            cin>>u>>v>>w;
            graph.push_back(pair<int, edge> (w, edge(u, v)));
        }
        kruskal();
        if(uni)
            cout<<total<<endl;
        else
            cout<<"Not Unique!"<<endl;
    }
}

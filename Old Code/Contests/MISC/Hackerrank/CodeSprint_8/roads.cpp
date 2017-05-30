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
using namespace std;

int n, m, cr, cl, total, parent[10001];
vector< pair<int, int> > graph;
set<int> cluster;

void reset(){
    total = 0;
    cluster.clear();
    graph.clear();
    for(int i = 1; i <= n; i++){
        parent[i] = i;
    }
}

int findset(int x, int* parent){
    while(x != parent[x]){
        x = parent[x];
    }
    return x;
}

void kruskal(){
    for(int i = 0; i < m; i++){
        int pu = findset(graph[i].first, parent);
        int pv = findset(graph[i].second, parent);
        if(pu != pv){
            total += cr;
            parent[pu] = parent[pv];
        }
    }
    for(int i = 1; i <= n; i++){
        cluster.insert(findset(i, parent));
    }
    total+=(cluster.size() * cl);
}

int main(){

    //freopen("roads.in", "r", stdin);

    int q;
    cin>>q;
    for(int i = 0; i < q; i++){
        cin>>n>>m>>cl>>cr;
        int x, y;
        for(int i = 0; i < m; i++){
            cin>>x>>y;
            graph.push_back(make_pair(x, y));
        }
        if(cr >= cl){
            cout<<cl*m<<endl;
        }else{
            reset();
            kruskal();
            cout<<total<<endl;
        }
    }

    return 0;
}

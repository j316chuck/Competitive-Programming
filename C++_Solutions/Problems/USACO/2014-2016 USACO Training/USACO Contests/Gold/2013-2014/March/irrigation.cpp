/*
ID: j316chuck
PROG: irrigation
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
#define MAX 2010

vector< pair< long long, edge > > GRAPH, MST;
vector< pair<int, int> > G;
int parent[MAX];
long long total;
int N, C;

int findset(int x){
    if(parent[x]!=x){
        parent[x] = findset(parent[x]);
    }
    return parent[x];
}

int main(){

    freopen("irrigation.in", "r", stdin);
    freopen("irrigation.out", "w", stdout);

    cin>>N>>C;

    for(int i = 0; i < N; i++){
        int x, y;
        cin>>x>>y;
        G.push_back(make_pair(x, y));
    }

    for(int i = 0; i < G.size(); i++){
        for(int j = 0; j < G.size(); j++){
            if(i == j)
                continue;
            long long cost = (G[i].first-G[j].first)*(G[i].first-G[j].first)
                            +(G[i].second-G[j].second)*(G[i].second-G[j].second);
            if(cost < C){
                continue;
            }
            GRAPH.push_back(make_pair(cost, make_pair(i, j)));
        }
    }

    for(int i = 0; i <= N; i++){
        parent[i] = i;
    }

    sort(GRAPH.begin(), GRAPH.end());
    for(int i = 0; i < GRAPH.size(); i++){
        int pu = findset(GRAPH[i].second.first);
        int pv = findset(GRAPH[i].second.second);
        if(MST.size() == N-1){
            cout<<total<<endl;
            return 0;
        }

        if(pu != pv){
            parent[pu] = parent[pv];
            MST.push_back(GRAPH[i]);
            total += GRAPH[i].first;
        }
    }
    cout<<-1<<endl;
    return 0;
}

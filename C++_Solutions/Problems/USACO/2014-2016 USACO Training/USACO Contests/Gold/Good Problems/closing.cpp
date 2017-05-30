/*
ID: j316chuck
PROG: closing April 2016
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

using namespace std;

int parent[200001], v[200001], u[200001], order[200001], close[200001];
bool res[200001];

int findset(int x){
    if(x!=parent[x]){
        parent[x] = findset(parent[x]);
    }
    return parent[x];
}

int main(){

    Rd("closing.in");
    Wt("closing.out");

    for(int i = 0; i <= 200000; i++){
        parent[i] = i;
    }

    int N, M;
    cin>>N>>M;
    for(int i = 0; i < M; i++){
        cin>>u[i]>>v[i];
    }
    vector< vector<int> > G(N+1);

    for(int i = 0; i < N; i++){
        cin>>close[i];
        order[close[i]] = N-i;
    }
    reverse(close, close+N);
    for(int i = 0; i < M; i++){
        if(order[u[i]] > order[v[i]] ){
            G[u[i]].push_back(v[i]);
        }else{
            G[v[i]].push_back(u[i]);
        }
    }
    int sub = 0; //subgraphs
    for(int i = 0; i < N; i++){
        sub++;
        int pu = findset(close[i]);
        if(order[pu]  < order[close[i]]){
            sub--;
        }
        for(int j = 0; j < G[close[i]].size(); j++){
            int pv = findset(G[close[i]][j]);
            if(pu!=pv){
                parent[pv] = parent[pu];
                sub--;
            }
        }
        res[i] = (sub <= 1);
        cout<<sub<<endl;
    }

    for(int i = N-1; i>=0; i--){
        if(res[i])
            cout<<"YES\n";
        else
            cout<<"NO\n";
        //cout<<(res[i])? "YES\n": "NO"<<endl;
    }
    return 0;
}

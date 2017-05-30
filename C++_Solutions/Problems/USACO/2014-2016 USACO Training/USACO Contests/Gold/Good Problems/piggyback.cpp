/*
ID: j316chuck
PROG: piggyback January 2015
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

int B, E, P, N, M;

vector<int> Dijstrka(int start, const vector< vector<int> > G){
    vector<int> D(N+1, -1);
    D[start] = 0;
    queue<int> Q;
    Q.push(start);
    while(!Q.empty()){
        int top = Q.front();
        Q.pop();
        for(int i = 0; i < G[top].size(); i++){
            int u = G[top][i];
            if(D[u] == -1){
                D[u] = D[top]+1;
                Q.push(u);
            }
        }
    }
    return D;
}

int main(){

    Rd("piggyback.in");
    Wt("piggyback.out");

    cin>>B>>E>>P>>N>>M;
    vector< vector<int> > G(N+1, vector<int> ());

    for(int i = 0; i < M; i++){
        int x, y;
        cin>>x>>y;
        G[x].push_back(y);
        G[y].push_back(x);
    }

    vector<int> DP1 = Dijstrka(1, G);
    vector<int> DP2 = Dijstrka(2, G);
    vector<int> DPN = Dijstrka(N, G);


    long long ans = pow(10, 10);
    for(int i = 1; i <= N; i++){
        long long res = -1;
        if(DP1[i] != -1 && DP2[i] != -1 && DPN[i] != -1){
            res = (1ll * DP1[i] * B) + (1ll * DP2[i] * E) +(1ll * DPN[i] * P);
        }
        ans = min(ans, res);
    }
    printf("%lld\n", ans);
    return 0;
}

/*
ID: j316chuck
PROG: rblock
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

int N, M;
int parent[251];

int dijstrka(vector< vector<int> > G, int x, int y){

    vector<int> D(N+1, pow(10, 8));
    vector<bool> used(N+1, false);
    if(x != -1){
        G[x][y] = 2 * G[x][y];
        G[y][x] = 2 * G[y][x];
    }

    D[1] = 0;
    for(int i = 0; i < N; i++){
        int j = -1;
        for(int k = 1; k <= N; k++){
            if(used[k]) continue;
            if(j == -1 || D[k] < D[j]){
                j = k;
            }
        }

        if(j == -1) break;
        used[j] = true;

        for(int k = 1; k <= N; k++){
            if(G[j][k] != 0 && !used[k] && D[j] + G[j][k] < D[k]){
                D[k] = D[j] + G[j][k];
                if(x == -1){
                    parent[k] = j;
                }
            }
        }
    }
    return D[N];
}

int main(){

    Rd("rblock.in");
    Wt("rblock.out");

    cin>>N>>M;

    vector< vector<int> > G(N+1, vector<int> (N+1, 0));
    for(int i = 0; i < M; i++){
        int u, v, w;
        cin>>u>>v>>w;
        G[u][v] = w;
        G[v][u] = w;
    }
    int cost = dijstrka(G, -1, -1);
    //cout<<cost<<endl;

    int pos = N;
    vector<int> P;
    while(pos){
        P.push_back(pos);
        pos = parent[pos];
    }

    int cost2 = 0;
    for(int i = 0; i < P.size()-1; i++){
        cost2 = max(cost2, dijstrka(G, P[i], P[i+1]));
    }

    cout<<cost2-cost<<endl;
}

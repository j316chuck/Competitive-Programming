#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

#define MAXN 1010

int Q[MAXN];
int DP[MAXN];
int D[MAXN];
vector<int> E[MAXN];
int result;

bool cmp(int a, int b){
    return Q[a] < Q[b];
}

int main(){

    freopen("buffet.in", "r", stdin);
    //freopen("buffet.out", "w", stdout);

    int N, ECST;
    cin>>N>>ECST;
    for(int i = 0; i < N; i++){
        int D;
        cin>>Q[i]>>D;
        for(int j = 0; j < D; j++){
            int v;
            cin>>v;
            E[i].push_back(v-1);
        }
    }
    vector<int> PI;
    for(int i = 0; i < N; i++){
        PI.push_back(i);
    }
    sort(PI.begin(), PI.end(), [&](int x, int y) {
        return Q[x] < Q[y];
    });

    int result = 0;
    for(int i = N-1; i >= 0; i--){
        int u = PI[i];
        //cout<<u<<' '<<Q[u]<<endl;
        queue<int> q;
        memset(D, -1, sizeof(D));
        D[u] = 0;
        q.push(u);
        while(!q.empty()){
            int v = q.front();
            q.pop();
            for(int j = 0; j < E[v].size(); j++){
                int nv = E[v][j];
                if(D[nv] == -1){
                    D[nv] = D[v]+1;
                    q.push(nv);
                }
            }
        }

        int res = Q[u];
        for(int j = 0; j < N; j++){
            res  = max(res, Q[u] + DP[j] - D[j] * ECST);
        }
        DP[u] = res;
        result = max(result, res);
    }
    cout<<result<<endl;
}

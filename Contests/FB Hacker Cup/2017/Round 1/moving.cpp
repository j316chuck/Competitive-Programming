/*
ID: j316chuck
PROG: moving
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

int G[110][110];
int S[5010];
int E[5010];
LL DP[5010][5010];

int main(){

    freopen("moving2.in", "r", stdin);
    freopen("moving.out", "w", stdout);

    int T, N, M, K;
    cin>>T;
    for(int it = 0; it < T; it++){

        cin>>N>>M>>K;
        memset(G, 0x3f, sizeof(G));
        for(int i = 0; i < M; i++){
            int a, b, g;
            cin>>a>>b>>g;
            G[a][b] = min(G[a][b], g);
            G[b][a] = min(G[b][a], g);
        }

        for(int k = 1; k <= N; k++){
            for(int i = 1; i <= N; i++){
                for(int j = 1; j <= N; j++){
                    G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
                }
            }
        }
        for(int i = 1; i <= N; i++){
            G[i][i] = 0;
        }

        memset(S, 0, sizeof(S));
        memset(E, 0, sizeof(E));
        bool cont = false;
        for(int i = 1; i <= K; i++){
            cin>>S[i]>>E[i];
            if(G[S[i]][E[i]] > 100000){
                cont = true;
            }
        }
        if(cont || G[1][S[1]] > 100000){
            printf("Case #%d: -1\n", it+1);
            continue;
        }

        memset(DP, 0, sizeof(DP));
        DP[1][0] = G[1][S[1]];
        DP[2][0] = DP[1][0] + G[S[1]][S[2]];
        DP[1][1] = DP[1][0] + G[S[1]][E[1]];
        for(int i = 1; i < K; i++){
            LL a = DP[i][i] + G[E[i]][S[i+1]];
            LL b = DP[i+1][i-1] + G[S[i+1]][E[i]];
            //cout<<i<<' '<<DP[i][i]<<' '<<a<<' '<<b<<endl;

            if(a < b){
                DP[i+1][i] = a;
                DP[i+1][i+1] = a + G[S[i+1]][E[i+1]];
                if(i != K-1)
                    DP[i+2][i] = a + G[S[i+1]][S[i+2]];
            }else if(b > a){
                DP[i+1][i] = b;
                DP[i+1][i+1] = b + G[E[i]][E[i+1]];
                if(i != K-1)
                    DP[i+2][i] = b + G[E[i]][S[i+2]];
            }else{
                DP[i+1][i] = a;
                DP[i+1][i+1] = min(a + G[S[i+1]][E[i+1]],
                                   b + G[E[i]][E[i+1]]);
                if(i != K-1){
                    DP[i+2][i] = min(a + G[S[i+1]][S[i+2]],
                                     b + G[E[i]][S[i+2]]);
                }
            }
        }

        printf("Case #%d: %d\n", it+1, DP[K][K]);

    }

    return 0;

}



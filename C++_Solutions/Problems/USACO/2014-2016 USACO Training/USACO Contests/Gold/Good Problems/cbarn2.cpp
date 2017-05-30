/*
ID: j316chuck
PROG: cbarn February 2016
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
#define pii pair<int, int>
using namespace std;

int N, K;
long long dp[8][1010];
long long dist[1010];
long long A[1010];

int main(){

    Rd("cbarn2.in");
    Wt("cbarn2.out");
    cin>>N>>K;
    for(int i = 0; i < N; i++){
        cin>>A[i];
    }

    long long res = INT_MAX;
    for(int it = 0; it < N; it++){
        memset(dp, 0x3f, sizeof(dp));
        dp[0][N] = 0;

        for(int k = 1; k <= K; k++){
            for(int i = 0; i < N; i++){
                long long val = 0;
                for(int j = i+1; j <= N; j++){
                    val+=A[j-1] * (j-i-1);
                    dp[k][i] = min(val + dp[k-1][j], dp[k][i]);
                }
            }
        }
        res = min(dp[K][0], res);
        rotate(A, A+1, A+N);
    }
    cout<<res<<endl;
    return 0;
}

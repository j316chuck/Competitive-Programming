/*
ID: j316chuck
PROG: CF_106C
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

int DP[11][1010];
int N, M, C0, D0;

int main(){

    //freopen("CF_106C.in", "r", stdin);
    //freopen("106C.out", "w", stdout);

    cin>>N>>M>>C0>>D0;
    vector<int> A(M+1);
    vector<int> B(M+1);
    vector<int> C(M+1);
    vector<int> D(M+1);
    vector<int> used(N+1);
    for(int i = 1; i <= M; i++){
        cin>>A[i]>>B[i]>>C[i]>>D[i];
    }

    memset(DP, -1, sizeof(DP));
    for(int i = 0; i <= N; i++){
        DP[0][i] = (i/C0)*D0;
    }
    for(int i = 0; i <= M; i++){
        DP[i][0] = 0;
    }

    for(int i = 1; i <= M; i++){
        fill(used.begin(), used.end(), 0);
        for(int j = 1; j <= N; j++){
            DP[i][j] = max(DP[i-1][j], DP[i][j-1]);
            //used[j] = 0;
            for(int k = 1; k * B[i] <= A[i] && k * C[i] <= j; k++){
                DP[i][j] = max(DP[i][j], DP[i-1][j-k*C[i]] + k * D[i]);
            }
            /*if(j-C[i] >= 0 && DP[i][j-C[i]] + D[i] > DP[i][j]
               && used[j-C[i]] + B[i] <= A[i] ){
                used[j] = used[j-C[i]] + B[i];
                DP[i][j] = DP[i][j-C[i]] + D[i];
            }*/
            //cout<<DP[i][j]<<' ';
        }//cout<<endl;
    }
    cout<<DP[M][N]<<endl;
    return 0;
}

/*ID: j316chuck
PROG: CF118D
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
#define MOD 100000000
using namespace std;

int N1, N2, K1, K2;
//int DP[101][101][11][11];
int DP[101][101][2];

int main(){

    //Rd("CF_118D.in");
    cin>>N1>>N2>>K1>>K2;

    DP[0][0][0] = 1; DP[0][0][1] = 1;
    for(int i = 0; i <= N1; i++){
        for(int j = 0; j <= N2; j++){
            for(int k = 1; k <= K1 && k <= i; k++){
                DP[i][j][0] = (DP[i][j][0] + DP[i-k][j][1]) % MOD;
            }
            for(int k = 1; k <= K2 && k <= j; k++){
                DP[i][j][1] = (DP[i][j][1] + DP[i][j-k][0]) % MOD;
            }
        }
    }
    cout<<(DP[N1][N2][0] + DP[N1][N2][1]) % MOD <<endl;
    /*DP[1][0][1][0] = 1;
    DP[0][1][0][1] = 1;
    for(int i = 1; i <= N1; i++){
        for(int k = 1; k <= N2; k++){
            for(int j = 1; j <= K2 && j <= k; j++){
                DP[i][k][1][0] += DP[i-1][k][0][j];
                DP[i][k][1][0] = DP[i][k][1][0]%MOD;
            }
            for(int a = 2; a <= K1 && a <= i; a++){
                DP[i][k][a][0] = DP[i-1][k][a-1][0];
            }
            for(int j = 1; j <= K1 && j <= i; j++){
                DP[i][k][0][1]+=DP[i][k-1][j][0];
                DP[i][k][0][1] = DP[i][k][0][1]%MOD;
            }
            for(int b = 2; b <= K2 && b <= k; b++){
                DP[i][k][0][b] = DP[i][k-1][0][b-1];
            }
        }
    }
    int total = 0;
    for(int i = 1; i <= K1; i++){
        total = (total + DP[N1][N2][i][0])%MOD;
        //cout<<total<<endl;
    }for(int i = 1; i <= K2; i++){
        total = (total + DP[N1][N2][0][i])%MOD;
        //cout<<total<<endl;
    }
    cout<<total<<endl;*/


}

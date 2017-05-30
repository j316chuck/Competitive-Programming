/*ID: j316chuck
PROG: hopscotch
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

int G[105][105];
long long dp[105][105];

int main(){

    Rd("hopscotch.in");
    Wt("hopscotch.out");

    int R, C, K;
    cin>>R>>C>>K;

    for(int i = 1; i <= R; i++){
        for(int j = 1; j <= C; j++){
            cin>>G[i][j];
        }
    }

    memset(dp, 0, sizeof(dp));
    dp[1][1] = 1;
    for(int i = 1; i < R; i++){
        for(int j = 1; j < C; j++){
            if(G[i][j] == 0){
                continue;
            }
            for(int r = i+1; r <= R; r++){
                for(int c = j+1; c <= C; c++){
                    if(G[i][j] != G[r][c]){
                        dp[r][c] += dp[i][j];
                        dp[r][c] = dp[r][c] % 1000000007;
                    }
                }
            }
        }
    }

    cout<<dp[R][C]<<endl;

    return 0;

}



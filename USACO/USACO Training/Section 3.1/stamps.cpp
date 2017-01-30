/*
ID: j316chuck
PROG: stamps
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
#define HM 1000000007

using namespace std;

int dp[2000001];
int A[101];

int main(){

    Rd("stamps.in");
    Wt("stamps.out");

    int K, N;
    cin>>K>>N;
    int m = -1;
    for(int i = 1; i <= N; i++){
        cin>>A[i];
        m = max(m, A[i]);
    }

    sort(A+1, A+N+1);
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    for(int i = 1; i <= N; i++){
        for(int j = A[i]; j <= K * m; j++){
            if(dp[j-A[i]] != -1 && (dp[j] == -1 || dp[j-A[i]] + 1 < dp[j]) && dp[j-A[i]] != K){
                dp[j] = dp[j-A[i]] + 1;
            }
        }
    }

    for(int i = 0; i <= 2000000; i++){
        if(dp[i] == -1){
            cout<<i-1<<endl;
            break;
        }
    }
    return 0;

}

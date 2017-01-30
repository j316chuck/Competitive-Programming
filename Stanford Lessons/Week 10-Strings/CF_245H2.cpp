/*ID: j316chuck
PROG: CF_245
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

int N;
string S;
int dp[5001][5001];
bool pal[5001][5001];

int main(){

    ios_sync
    cin>>S;

    for(int i = 0; i <= S.size(); i++){
        dp[i][i] = 1;
        pal[i][i] = true;
    }
    for(int i = 0; i < S.size()-1; i++){
        pal[i][i+1] = (S[i] == S[i+1]);
    }

    for(int len = 2; len < S.size(); len++){
        for(int i = 0; i + len < S.size(); i++){
            int j = i+len;
            pal[i][j] = (S[i] == S[j] && pal[i+1][j-1]);
        }
    }

    for(int len = 1; len < S.size(); len++){
        for(int i = 0; i + len < S.size(); i++){
            dp[i][j] = dp[i+1][i+len] + dp[i][i+len-1] - dp[i+1][i+len-1];
            dp[i][j] += (pal[i][i+len] ? 1:0);
        }
    }

    cin>>N;
    for(int i = 0; i < N; i++){
        int a, b;
        cin>>a>>b;
        a--; b--;
        cout<<dp[a][b]<<endl;
    }
    return 0;
}

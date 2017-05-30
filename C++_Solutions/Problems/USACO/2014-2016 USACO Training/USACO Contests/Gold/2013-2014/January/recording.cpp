/*ID: j316chuck
PROG: recording
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
#define NOPATH -100000000

using namespace std;

int DP[151][151];

int main(){

    Rd("recording.in");
    Wt("recording.out");

    int N;
    cin>>N;
    vector< pair<int, int> > A(N+1);
    A[0].first = 0; A[0].second = 0;
    for(int i = 1; i <= N; i++){
        cin>>A[i].first>>A[i].second;
    }
    sort(A.begin(), A.end());

    DP[0][0] = 0;
    DP[1][0] = 1;
    DP[0][1] = 1;
    DP[1][1] = NOPATH;
    
    for(int i = 2; i <= N; i++){
        for(int j = 2; j <= N; j++){
            DP[i][j] = NOPATH;
        }
    }

    for(int i = 2; i <= N; i++){
        for(int j = 0; j < i; j++){
            for(int k = 0; k < i; k++){
                if(DP[j][k]!=NOPATH && A[i].first >= A[j].second){
                    DP[i][k] = max(DP[i][k], DP[j][k]+1);
                }
                if(DP[j][k]!=NOPATH && A[i].first >= A[k].second){
                    DP[j][i] = max(DP[j][i], DP[j][k]+1);
                }
            }
        }
    }

    int res = 0;
    for(int i = 0; i <= N; i++){
        for(int j = 0; j <= N; j++){
            res = max(res, DP[i][j]);
        }
    }
    cout<<res<<endl;
    return 0;
}

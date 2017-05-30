/*ID: j316chuck
PROG: poj_2430
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

int DP1[1010][1010];
int DP2[1010][1010];
int DP[1010][1010];

int main(){

    freopen("10.in", "r", stdin);
    int N, K, B;
    cin>>N>>K>>B;

    vector< pair<int, int> > A(N+1);
    for(int i = 1; i <= N; i++){
       cin>>A[i].second>>A[i].first;
    }
    sort(A.begin(), A.end());
    /*for(int i = 1; i <= N; i++){
        cout<<A[i].first<<endl;
    }*/

    //initalization
    memset(DP, 0x3f, sizeof(DP));
    memset(DP1, 0x3f, sizeof(DP1));
    memset(DP2, 0x3f, sizeof(DP2));

    //base case
    DP1[1][1] = 1;
    DP2[1][1] = 1;
    DP[1][1] = 1;

    /*subproblems and recurrence relation*/
    //DP1[i][k] = min(DP[i-1][k-1] + 1, DP1[i-1][k] + A[k].first - A[k-1].first);
    //DP2[i][k] = min(DP[i-1][k-1] + 2, DP2[i-1][k] + A[k].first-A[k-1].first;
    //DP[i][k] = min(DP[i-1][k-1] + 1, DP1[i-1][k-1] + A, DP2[i][k-1]
    for(int i = 2; i <= N; i++){
        for(int k = 1; k <= i && k <= K; k++){
            if(A[i].second == A[i-1].second){
                firstDP[i-1]
            }
            DP1[i][k] = min(DP[i-1][k-1] + 1, )
        }
    }
}

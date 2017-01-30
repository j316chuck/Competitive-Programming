/*ID: j316chuck
PROG: poj_2127
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

// a and b are the sequences to be processed
int a[1001], b[1001];
// dp[i][j] represents the length of LCIS ending with b[j]
int dp[1001][1001];
// what does path do?
int path[1001][1001];
// ans stores the numbers in the LCIS
int lcis[1001];

int main() {

    //freopen("7.in", "r", stdin);
    // I, J represent the final i and j values.

    int I = 0, J = 0;

    // What does mj mean?
    int mj = 0;

    int length = 0;

    // gets input
    int m, n;
    cin >> m;
    for (int i = 1; i <= m; i++) cin >> a[i];
    cin >> n;
    for (int j = 1; j <= n; j++) cin >> b[j];

    memset(dp, 0, sizeof(dp));
    memset(path, -1, sizeof(path));

    for (int i = 1; i <= m; i++) {
        int max = 0;
        for (int j = 1; j <= n; j++) {
            // state transfer
            dp[i][j] = dp[i-1][j];

            // find the max
            if (b[j] < a[i] && max < dp[i][j]) {
                max = dp[i][j];
                mj = j;
            } else {
                if (a[i] == b[j]) {
                    // state transfer
                    dp[i][j] = 1 + max;
                    path[i][j] = mj;
                }
            }
            // the length is the maximal dp[i][j]
            if (length < dp[i][j]) {
                length = dp[i][j];
                I = i;
                J = j;
            }
        }
    }
    cout << length << endl;

    // What does this part do?
//    for (int i = length; i > 0; i--) {
//        if (path[I][J] > -1) {
//            lcis[i] = b[J];
//            J = path[I][J];
//        }
//        I--;
//    }

    // Why does this work?
    int temp=length;
    while (temp) {
        if(path[I][J]>-1)
        {
            lcis[temp--]=b[J];
            J=path[I][J];
        }
        I--;
    }

    // print the LCIS
    for (int i = 1; i <= length; i++) {
        cout << lcis[i] << ((i == length) ? "\n" : " ");
    }
    return 0;
}

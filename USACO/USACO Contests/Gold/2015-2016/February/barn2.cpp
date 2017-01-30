/*ID: j316chuck
PROG: cbarn
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

#define MAXN 1010
#define MAXK 10
#define INF 0x3FFFFFFFFFFFFFFFLL
int N, K;
long long A[MAXN];
long long DP[MAXK][MAXN];

int main() {

    Rd("cbarn2.in");
  cin >> N >> K;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  long long result = INF;
  for (int i = 0; i < N; i++) {
    memset(DP, 0x3F, sizeof(DP));
    DP[0][N] = 0;
    for (int k = 1; k <= K; k++) {
      for (int j = 0; j < N; j++) {
        long long val = 0;
        for (int a = j + 1; a <= N; a++) {
          val += A[a - 1] * (a - j - 1);
          DP[k][j] = min(DP[k][j], val + DP[k - 1][a]);
        }
        //cout<<DP[k][j]<<' ';
      }//cout<<endl;
    }
    //cout<<endl<<endl<<endl;
    result = min(result, DP[K][0]);
    rotate(A, A + 1, A + N);
  }
  cout << result << endl;
}

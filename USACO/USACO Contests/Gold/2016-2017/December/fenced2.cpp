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
#define edge pair< int, int >

using namespace std;
int A, B, N, M;

int nd(int r, int c) {
  return r * M + c;
}

int P[2010*2010];

int find(int x) {
  return x == P[x] ? x : P[x] = find(P[x]);
}

bool merge(int x, int y) {
  int X = find(x);
  int Y = find(y);
  if (X == Y) return false;
  P[X] = P[Y] = P[x] = P[y] = rand() % 2 ? X : Y;
  return true;
}

int main() {
    freopen("fencedin.in", "r", stdin);
  cin >> A >> B >> N >> M;

  vector<int> VA(N + 1), HA(M + 1);
  for (int i = 0; i < N; i++) {
    cin >> VA[i];
  }
  for (int j = 0; j < M; j++) {
    cin >> HA[j];
  }

  sort(VA.begin(), VA.end());
  for (int i = 0; i < N; i++) {
    VA[i] = VA[i + 1] - VA[i];
  }
  VA[N] = B - VA[N];

  sort(HA.begin(), HA.end());
  for (int i = 0; i < M; i++) {
    HA[i] = HA[i + 1] - HA[i];
  }
  HA[M] = A - HA[M];

  sort(VA.begin(), VA.end());
  sort(HA.begin(), HA.end());
  N++; M++;

  for (int i = 0; i < N * M; i++) {
    P[i] = i;
  }

  long long result = 0;
  for (int vi = 0, hi = 0; vi < N || hi < M; ) {
    if (hi == M || (vi < N && VA[vi] < HA[hi])) {
      for (int i = 0; i + 1 < M; i++) {
        if (merge(nd(vi, i), nd(vi, i + 1))) {
          result += VA[vi];
        }
      }
      vi++;
    } else {
      for (int i = 0; i + 1 < N; i++) {
        if (merge(nd(i, hi), nd(i + 1, hi))) {
          result += HA[hi];
        }
      }
      hi++;
    }
  }
  cout << result << endl;

  return 0;
}

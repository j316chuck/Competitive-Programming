/*ID: j316chuck
PROG: lightsout
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

#define MAXN 210

int opt[MAXN];

int main() {

 freopen("lightsout.in", "r", stdin);
  int N; cin >> N;
  vector<pair<long long, long long> > A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i].first >> A[i].second;
  }

  /* Create the underlying string from the polygon.  Represent the exit as
   * 0.  Represent clockwise turns as -1, counter clockwise as -2.  Represent
   * lengths by their length.
   */
  vector<int> S(1, 0);
  for (int i = 0; i < N; i++) {
    int j = (i + 1) % N;
    int k = (i + 2) % N;
    S.push_back(abs(A[i].first - A[j].first) +
                abs(A[i].second - A[j].second));

    /* Use a cross product to determine which way the polygon turned. */
    if ((A[i].first - A[j].first) * (A[k].second - A[j].second) -
        (A[k].first - A[j].first) * (A[i].second - A[j].second) > 0) {
      S.push_back(-1);
    } else {
      S.push_back(-2);
    }
  }
  S.back() = 0;

/*for(int i = 0; i < S.size(); i++){
    cout<<S[i]<<' ';
}cout<<endl;*/
  /* Compute the lights-on cost for each corner. */
  for (int i = 0; i < N; i++) {
    opt[i + 1] = opt[i] + S[2 * i + 1];
  }
  opt[N] = 0;
  for (int i = N - 1; i >= 0; i--) {
    opt[i] = min(opt[i], opt[i + 1] + S[2 * i + 1]);
  }
  /*for(int i = 0; i < N; i++){
    cout<<opt[i]<<' ';
  }cout<<endl;*/

  multiset<vector<int> > st;
  for (int i = 0; i < S.size(); i += 2) {
    for (int ln = 1; i + ln <= S.size(); ln += 2) {
      st.insert(vector<int>(S.begin() + i, S.begin() + i + ln));
    }
  }

  int result = 0;
  for (int i = 2; i + 2 < S.size(); i += 2) {
    int ln;
    int cost = 0;
    for (ln = 1; ; ln += 2) {
      if (st.count(vector<int>(S.begin() + i, S.begin() + i + ln)) == 1) {
        break;
      }
      cost += S[i + ln];
    }
    result = max(result, cost + opt[(i + ln) / 2] - opt[i / 2]);
  }

  cout << result << endl;

  return 0;
}

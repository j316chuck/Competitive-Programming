/*
ID: j316chuck
PROG: cbarn February 2016
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


long long sumn2(long long v) {
  return v * (v + 1) * (2 * v + 1) / 6;
}

int main() {
    freopen("cbarn.in", "r", stdin);
  int N; cin >> N;
  vector<long long> A(N);

  int c = 0;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    c = max(0ll, c + A[i] - 1);
    //cout<<c<<' ';
  }//cout<<endl;

  for (int i = 0; ; i++) {
    if (c == 0) {
      rotate(A.begin(), A.begin() + i, A.begin() + N);
      break;
    }
    c = max(0ll, c + A[i] - 1);
    //cout<<c<<' ';
  }//cout<<endl;

    /*for(auto i = A.begin(); i < A.end(); i++){
        cout<<*i<<' ';
    }cout<<endl;*/

  long long result = 0;
  for (int i = 0; i < N; i++) {
    result += sumn2(A[i] + c - 1) - sumn2(c - 1);
    c = max(0ll, c + A[i] - 1);
    cout<<c<<' '<<result<<endl;
  }
  cout << result << endl;
}

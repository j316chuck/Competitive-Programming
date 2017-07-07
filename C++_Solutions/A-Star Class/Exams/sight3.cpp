#include <algorithm>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <iostream>
using namespace std;

#define PI 3.1415926535897932384626

int main() {
  freopen("sight.in", "r", stdin);
  //freopen("sight.out", "w", stdout);

  int N, R;
  scanf("%d%d", &N, &R);

  vector<pair<double, double> > A;
  for(int i = 0; i < N; i++) {
    int x, y; scanf("%d%d", &x, &y);
    double alpha = acos(R / sqrt(1.0 * x * x + 1.0 * y * y));
    double a0 = atan2(y, x) - alpha;
    if(a0 < 0) a0 += 2 * PI;
    A.push_back(make_pair(a0, a0 + 2 * alpha));
  }
  sort(A.begin(), A.end());
    cout << A[0].first << endl;
}

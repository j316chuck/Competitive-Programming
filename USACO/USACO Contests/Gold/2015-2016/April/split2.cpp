/*ID: j316chuck
PROG: 248
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

vector < pair<long long, long long> > A;
vector < pair<LL, LL> > B;

int main(){

    freopen("split.in", "r", stdin);
    freopen("split.out", "w", stdout);

    int n;
    cin>>n;

    long long bx = -1, by = -1, sx = INT_MAX, sy = INT_MAX;
    for(int i = 0; i < n; i++){
        long long x, y;
        cin>>x>>y;
        A.push_back(make_pair(x, y));
        B.push_back(make_pair(y, x));
        bx = max(bx, x); by = max(by, y);
        sx = min(x, sx); sy = min(y, sy);
    }

    long long res = (bx-sx)*(by-sy);
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    vector<long long> mem[2];
    for(int k = 0; k < 2; k++){
        bx = A[0].first, by = A[0].second, sx = A[0].first, sy = A[0].second;
        for(int i = 0; i < A.size(); i++){
            bx = max(bx, A[i].first), by = max(by, A[i].second);
            sx = min(A[i].first, sx), sy = min(A[i].second, sy);
            mem[k].push_back((bx-sx) * (by-sy));
        }
        reverse(A.begin(), A.end());
    }
    reverse(mem[1].begin(), mem[1].end());

    long long minimum = res;
    for(int i = 1; i < mem[0].size(); i++){
        minimum = min(minimum, mem[0][i-1] + mem[1][i]);
    }

    vector<long long> memo[2];
    for(int k = 0; k < 2; k++){
        bx = B[0].first, by = B[0].second, sx = B[0].first, sy = B[0].second;
        for(int i = 0; i < B.size(); i++){
            bx = max(bx, B[i].first), by = max(by, B[i].second);
            sx = min(B[i].first, sx), sy = min(B[i].second, sy);
            memo[k].push_back((bx-sx) * (by-sy));
        }
        reverse(B.begin(), B.end());
    }
    reverse(memo[1].begin(), memo[1].end());
    /*for(int i = 0; i < n; i++){
        cout<<memo[0][i]<<' '<<memo[1][i]<<endl;
    }*/
    for(int i = 1; i < memo[0].size(); i++){
        minimum = min(minimum, memo[0][i-1] + memo[1][i]);
    }
    res -= minimum;
    printf("%lld\n", res);

}

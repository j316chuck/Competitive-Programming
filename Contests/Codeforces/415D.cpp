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

int n, k;
string input;

bool query(int x, int y) {
    if (x < 1 || y > n) {
        return false;
    }
    printf("1 %d %d\n", x, y);
    fflush(stdout);
    cin >> input;
    return input == "TAK";
}

int bsearch(int lo, int hi) {
    if (lo > hi) return false;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (query(mid, mid + 1)) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    return lo;
}

int main(){

    //Rd("input.in");
    scanf("%d %d", &n, &k);

    int a1 = bsearch(1, n);
    int a2 = bsearch(1, a1 - 1);
    if (!query(a2, a2+1)) {
        a2 = bsearch(a1 + 1, n);
    }
    printf("2 %d %d\n", a1, a2);
    return 0;
}




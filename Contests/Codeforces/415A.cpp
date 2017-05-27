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

int main(){

    //Rd("input.in");
    int n, counter = 0;
    double k, sum = 0, temp;
    scanf("%d %lf", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%lf", &temp);
        sum += temp;
    }

    while (k - 0.5 > sum / (n + counter)) {
        counter++;
        sum += k;
    }

    printf("%d\n", counter);
    return 0;
}


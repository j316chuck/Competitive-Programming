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

long long MOD = 1e9 + 7;

int main(){

    //Rd("input.in");
    int n; long long tmp, total = 0, multiply = 1;
    scanf("%d", &n);
    vector<int> vec;
    for (int i = 0; i < n; i++) {
        scanf("%I64d", &tmp);
        vec.push_back(tmp);
    }
    sort(vec.begin(), vec.end());
    for (int i = 0; i < n; i++) {
        total = total + (((multiply * vec[i]) + MOD)% MOD) % MOD;
        multiply = multiply * 2 % MOD;
    }
    reverse(vec.begin(), vec.end());
    multiply = 1;
    for (int i = 0; i < n; i++) {
        total = ((total - (((multiply * vec[i]) + MOD)% MOD)) + MOD) % MOD;
        multiply = (multiply * 2) % MOD;
    }
    printf("%I64d", total);
    return 0;
}




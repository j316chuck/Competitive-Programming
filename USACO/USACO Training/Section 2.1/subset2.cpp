/*
ID: j316chuck
PROG: subset
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

const double Pi=acos(-1.0);
typedef long long LL;

#define Set(a, s) memset(a, s, sizeof (a))
#define Rd(r) freopen(r, "r", stdin)
#define Wt(w) freopen(w, "w", stdout)
using namespace std;

int main(){
    //Rd("subset.in");

    long long dp [1600];



    int n; scanf ("%d", &n);

    if ( ((n * (n + 1)) / 2) % 2 ) {
        printf ("0\n"); return 0;
    }

    Set (dp, 0);

    dp [0] = 1;     // we can make zero in 1 ways

    for ( int i = 1; i <= n; i++ ) {
        for ( int j = 1599; j >= 0; j-- ) {
            if ( dp [j] !=0 && j + i < 1600 )
                dp [j + i] += dp [j];
        }
    }

    //printf ("%d\n", ((n * (n + 1)) / 2));


    cout << dp [(n * (n + 1) / 2) / 2] / 2 << endl;

    return 0;
}


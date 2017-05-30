/*ID: j316chuck
PROG: cowjog
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

int main(){

    freopen("cowjog.in", "r", stdin);
    freopen("cowjog.out", "w", stdout);

    long long n, t;
    cin>>n>>t;

    vector<long long> G;
    for(int i = 0; i < n; i++){
        long long p, s;
        cin>>p>>s;
        G.push_back(p + t * s);
    }

    reverse(G.begin(), G.end());
    int group = 1;
    long long minimum = G[0];

    for(int i = 1; i < n; i++){
        if(minimum > G[i]){
            minimum = G[i];
            group++;
        }
    }

    printf("%d\n", group);
    return 0;
}

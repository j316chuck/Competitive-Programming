/*ID: j316chuck
PROG: superbull
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
#include <functional>

const double Pi=acos(-1.0);
typedef long long LL;

#define Set(a, s) memset(a, s, sizeof (a))
#define Rd(r) freopen(r, "r", stdin)
#define Wt(w) freopen(w, "w", stdout)
#define pii pair<int, int>

using namespace std;


int main(){

    freopen("superbull.in", "r", stdin);
    freopen("superbull.out", "w", stdout);

    int n;
    cin>>n;
    vector<int> A(n);
    for(int i = 0; i < n; i++){
        cin>>A[i];
    }
    long long result = 0;
    vector<bool> used(n, false);
    vector<int> D(n, 0);

    for(int i = 0; i < n; i++){
        int j  = -1;
        for(int k = 0; k < n; k++){
            if(used[k]) continue;
            if(j == -1 || D[k] > D[j]){
                j = k;
            }
        }

        result += D[j];
        used[j] = true;

        for(int k = 0; k < n; k++){
            if(!used[k]){
                D[k] = max(D[k], A[j] ^ A[k]);
            }
        }
    }

    cout<<result<<endl;
    return 0;

}

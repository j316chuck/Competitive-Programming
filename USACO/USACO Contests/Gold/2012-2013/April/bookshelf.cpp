/*ID: j316chuck
PROG: bookshelf
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
#define BG 1000000001

using namespace std;

int mem[2010];
int N, L;
vector<pii> A;

int dp(int n){
    int i = n, height = 0, width = 0, total = BG;
    if(i == 0) return 0;
    if(mem[i] != -1) return mem[i];

    while(i >= 1){
        if(width + A[i].second > L){
            break;
        }
        width += A[i].second;
        height = max(height, A[i].first);
        total = min(total, dp(i-1) + height);
        i--;
    }
    return mem[n] = total;
}

int main(){

    Rd("bookshelf.in");
    Wt("bookshelf.out");

    cin>>N>>L;
    A.resize(N+1);
    for(int i = 1; i <= N; i++){
        cin>>A[i].first>>A[i].second;
    }

    memset(mem, -1, sizeof(mem));
    mem[0] = 0;
    int width = 0, i = 1;
    while(width + A[i].second <= L && i <= N){
        mem[i] = max(mem[i-1], A[i].first);
        width += A[i].second;
        i++;
    }

    cout<<dp(N)<<endl;
    return 0;
}




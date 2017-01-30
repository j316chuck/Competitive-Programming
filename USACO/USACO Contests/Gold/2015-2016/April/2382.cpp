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

using namespace std;

int main(){

    freopen("248.in", "r", stdin);
    //freopen("248.out", "w", stdout);

    int mem[250][250];
    memset(mem, -1, sizeof(mem));
    int n;
    cin>>n;

    for(int i = 0; i < n; i++){
        cin>>mem[1][i];
    }

    for(int i = 2; i <= n; i++){
        for(int j = 0; j+i <= n; j++){
            for(int k = 1; k < i; k++){
                if(mem[k][j] == mem[i-k][j+k] && mem[k][j]!=-1 && mem[i-k][j+k]!=-1){
                    mem[i][j] = max(mem[i][j], mem[k][j]+1);
                }
            }
        }
    }

    int res = -1;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j+i <= n; j++){
            res = max(res, mem[i][j]);
        }
    }
    cout<<res<<endl;

}

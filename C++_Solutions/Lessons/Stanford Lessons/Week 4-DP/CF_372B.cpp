/*ID: j316chuck
PROG:
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

int row[51][51];
int dp[51][51][51][51];
int mapa[51][51];

int main(){

    Rd("372B.in");
    int n, m, q;
    cin>>n>>m>>q;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            scanf("%1d", &mapa[i][j]);
            row[i][j] = row[i][j-1];
            if(mapa[i][j]){
                row[i][j] = 0;
            }else{
                row[i][j]++;
            }
        }
    }
    //cout<<row[2][2]<<endl;
    for(int a = 1; a <= n; a++)
    for(int b = 1; b <= m; b++)
    for(int c = a; c <= n; c++)
    for(int d = b; d <= m; d++){
        dp[a][b][c][d] = dp[a][b][c-1][d]+dp[a][b][c][d-1]
                        -dp[a][b][c-1][d-1];
        int r = d-b+1;
        for(int i = c; i >= a && r; i--){
            r = (r < row[i][d]? r : row[i][d]);
            dp[a][b][c][d]+=r;
        }

    }
    while(q--){
        int a, b, c, d;
        scanf("%d%d%d%d", &a, &b, &c, &d);
        printf("%d\n", dp[a][b][c][d]);
    }
    return 0;
}




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

int n, t, nx, ny, nk;
long long G[105][105];
long long mem[105][105][3];
bool visit[105][105][3];
int dx[4], dy[4];

long long dp(int i, int j, int k){
    if(mem[i][j][k] != -1){
        cout<<"mem: "<<i<<' '<<j<<' '<<k<<' '<<mem[i][j][k]<<endl;
        return mem[i][j][k];
    }
    long long total = INT_MAX;
    visit[i][j][k] = true;
    cout<<"iteration: "<<i<<' '<<j<<' '<<k<<' '<<endl;

    for(int ii = 0; ii < 4; ii++){
        nx = dx[ii] + i;
        ny = dy[ii] + j;
        nk = ((k-1) + 3) % 3;
        if(nx < 0 || ny < 0 || nx >= n || ny >= n|| visit[nx][ny][nk] == true){
            continue;
        }
        cout<<"for loop: "<<nx<<' '<<ny<<' '<<nk<<endl;
        total = min(total, dp(nx, ny, nk));
    }
    if(k == 0) total += G[i][j];
    total += t;
    visit[i][j][k] = false;
    if(total > pow(10, 9)) total = -1;
    cout<<"total: "<<i<<' '<<j<<' '<<k<<' '<<total<<endl;

    return mem[i][j][k] = total;
}

int main(){

    Rd("1.in");
    Wt("1.out");
    cin>>n>>t;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin>>G[i][j];
        }
    }

    dx[0] = -1, dx[1] = 0; dx[2] = 1; dx[3] = 0;
    dy[0] = 0; dy[1] = 1; dy[2] = 0; dy[3] = -1;
    long long result = INT_MAX;
    for(int i = 0; i < 3; i++){
        memset(visit, false, sizeof(visit));
        memset(mem, -1, sizeof(mem));
        mem[0][0][0] = 0; mem[0][0][1] = 0; mem[0][0][2] = 0;
        long long d = dp(n-1, n-1, i);
        //cout<<d<<endl;
        result = min(d, result);
    }
    cout<<result<<endl;
}



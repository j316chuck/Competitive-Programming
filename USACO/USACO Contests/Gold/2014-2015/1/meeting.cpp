/*ID: j316chuck
PROG: meeting
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

class pp{
public:
    int t, x;
    bool b;
    bool operator < (const pp & a) const{
        return t > a.t;
    }
};

int main(){

    freopen("meeting.in", "r", stdin);
    freopen("meeting.out", "w", stdout);

    int n, m, a, b, c, d;
    cin>>n>>m;

    int E[101][101], B[101][101];
    memset(E, -1, sizeof(E));
    memset(B, -1, sizeof(B));

    for(int i = 0; i < m; i++){
        cin>>a>>b>>c>>d;
        B[a][b] = c;
        E[a][b] = d;
    }
    pp ei; ei.t = 0; ei.x = 1; ei.b = false;
    pp bi; bi.t = 0; bi.x = 1; bi.b = true;

    priority_queue<pp> Q;
    Q.push(ei); Q.push(bi);

    set<int> btime; set<int> etime;

    while(!Q.empty()){
        pp top = Q.top();
        Q.pop();

        if(top.x == n){
            if(top.b){
                if(etime.find(top.t)!=etime.end()){
                    printf("%d\n", top.t);
                    return 0;
                }else{
                    btime.insert(top.t);
                }
            }else{
                if(btime.find(top.t)!=btime.end()){
                    printf("%d\n", top.t);
                    return 0;
                }else{
                    etime.insert(top.t);
                }
            }
        }

        pp bii;

        for(int i = top.x+1; i <= n; i++){// for int i = 0; i <=n;
            if(B[top.x][i]!=-1){
                if(top.b){
                    bii.x = i; bii.t = top.t + B[top.x][i]; bii.b = true;
                }else{
                    bii.x = i; bii.t = top.t + E[top.x][i]; bii.b = false;
                }
                Q.push(bii);
            }
        }

    }

    printf("IMPOSSIBLE\n");
    return 0;
}

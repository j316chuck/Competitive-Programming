/*ID: j316chuck
PROG: piggyback
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


class pp{
public:
    int w, b, e;
    bool operator < (const pp &a) const{
        return w > a.w;
    }
};
int B, E, P, N, M;

int main(){

    Rd("piggyback.in");
    Wt("piggyback.out");

    cin>>B>>E>>P>>N>>M;

    vector< vector<int> > G(N+1, vector<int>());
    for(int i = 0; i < M; i++){
        int a, b;
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    priority_queue<pp> Q;
    pp ei; ei.b = 1; ei.e = 2; ei.w = 0;
    Q.push(ei);

    //int res = INT_MAX;

    while(!Q.empty()){
        pp top = Q.top();
        Q.pop();
        int b = top.b; int e = top.e;
        if(b == N && e == N){
            printf("%d\n", top.w);
            return 0;
        }
        pp bi;
        if(b == e && P < E + B){
            for(int i = 0; i < G[b].size(); i++){
                bi.b = G[b][i]; bi.e = G[b][i]; bi.w = top.w + P;
                Q.push(bi);
            }
        }else{
            for(int i = 0; i < G[b].size(); i++){
                bi.b = G[b][i]; bi.e = e; bi.w = top.w + B;
                Q.push(bi);
            }
            for(int i = 0; i < G[e].size(); i++){
                bi.b = b; bi.e = G[e][i]; bi.w = top.w + E;
                Q.push(bi);
            }
        }
    }

    //printf("%d\n", res);

    return 0;

}

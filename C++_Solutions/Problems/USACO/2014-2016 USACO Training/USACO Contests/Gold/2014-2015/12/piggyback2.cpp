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

int B, E, P, N, M;

vector<int> D(int st, const vector< vector<int> > &G){
    vector<int> D(G.size(), -1);
    deque<int> Q;
    D[st] = 0;
    Q.push_back(st);

    while(!Q.empty()){
        int top = Q.front();
        Q.pop_front();
        for(int i = 0; i < G[top].size(); i++){
            int c = G[top][i];
            if(D[c] == -1){
                D[c] = D[top] + 1;
                Q.push_back(c);
            }
        }
    }
    return D;
}

int main(){

    Rd("piggyback.in");
    Wt("piggyback.out");
    cin>>B>>E>>P>>N>>M;

    vector< vector<int> > G(N+1, vector<int> ());
    for(int i = 0; i < M; i++){
        int x, y;
        cin>>x>>y;
        x--; y--;
        G[x].push_back(y);
        G[y].push_back(x);
    }

    vector<int> D0 = D(0, G);
    vector<int> D1 = D(1, G);
    vector<int> Dn = D(N-1, G);

    /*for(int i = 0; i < D0.size(); i++ ){
        cout<<D0[i]<<' '<<D1[i]<<' '<<Dn[i]<<endl;
    }*/
    long long ans = pow(10, 12);

    for(int i = 0; i < N; i++){
        if(D0[i]!=-1 && D1[i]!=-1 && Dn[i]!=-1){
            ans = min(ans, ((long long) D0[i] * B + D1[i] * E + Dn[i] * P));
        }
    }
    cout<<ans<<endl;
}

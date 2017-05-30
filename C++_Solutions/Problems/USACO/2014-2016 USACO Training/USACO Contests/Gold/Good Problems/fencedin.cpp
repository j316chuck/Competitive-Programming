/*ID: j316chuck
PROG: fencedin
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
    int u, v, w;
    bool operator <(const pp &a) const{
        return w < a.w;
    }
};

int A, B, N, M;
vector<int> V;
vector<int> H;
vector<int> parent;
long long total;
vector<pp> G;


int nd(int r, int c){
    return r *(N+1) + c;
}

int findset(int x){
    if(x!=parent[x]){
        parent[x] = findset(parent[x]);
    }
    return parent[x];
}

int main(){

    Rd("fencedin.in");
    Wt("fencedin.out");

    cin>>A>>B>>N>>M;
    H.push_back(0); V.push_back(0);

    for(int i = 0; i < N; i++){
        int a; cin>>a;
        V.push_back(a);
    }
    for(int i = 0; i < M; i++){
        int a; cin>>a;
        H.push_back(a);
    }
    V.push_back(A);
    H.push_back(B);
    sort(V.begin(), V.end());
    sort(H.begin(), H.end());

    for(int r = 0; r <= M; r++){
        for(int c = 0;  c <= N; c++){
            pp ei;
            ei.u = nd(r, c);
            if(c!=N){
                ei.v = nd(r, c+1);
                ei.w = H[r+1]-H[r];
                G.push_back(ei);
            }if(r!=M){
                ei.v = nd(r+1, c);
                ei.w = V[c+1]-V[c];
                G.push_back(ei);
            }
        }
    }
    sort(G.begin(), G.end());

    for(int i = 0; i <= (N+1) * (M+1); i++){
        parent.push_back(i);
    }

    total = 0;
    int size = 0;
    for(int i = 0; i < G.size(); i++){
        int pu = findset(G[i].u);
        int pv = findset(G[i].v);
        if(pu!=pv){
            parent[pu] = parent[pv];
            total+=G[i].w;
            //size++;
        }
        /*if(size+1 == (N+1)*(M+1)){
            cout<<total<<endl;
            return 0;
        }*/
    }
    cout<<total<<endl;
    return 0;
}

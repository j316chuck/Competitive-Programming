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
#define INF 10000
using namespace std;


int main(){

    Rd("buffet.in");
    //Wt("buffet.out");

    int n, e, t;
    cin>>n>>e;
    vector<int> D(n+1);
    vector< vector<LL> > G(n+1, vector<LL>(n+1, INF));

    for(int i = 1; i <= n; i++){
        cin>>D[i];
        cin>>t;
        G[i][i] = 0;
        for(int j = 0; j < t; j++){
            int a; cin>>a;
            G[i][a] = 1;
        }
    }

    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
            }
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            /*if(i == j){
                G[i][j] = D[j];
            }else */
            if(D[i] >= D[j]){
                G[i][j] = -INF;
            }else if(G[i][j] == INF){
                G[i][j] = -INF;
            }else{
                G[i][j] = D[j] - (G[i][j] * e);
            }
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j<= n; j++){
            cout<<G[i][j]<<' ';
        }cout<<endl;
    }

    long long res = -1;
    int start = -1;
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(G[i][j] == -INF){
                    continue;
                }
                G[i][j] = max(G[i][j], G[i][k] + G[k][j]);
            }
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j<= n; j++){
            if(res < G[i][j]){
                res = G[i][j];
                start = i;
            }
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j<= n; j++){
            cout<<G[i][j]<<' ';
        }cout<<endl;
    }
    cout<<res + D[start]<<endl;
    return 0;

}



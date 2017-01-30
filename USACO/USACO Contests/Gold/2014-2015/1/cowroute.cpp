/*ID: j316chuck
PROG: cowroute
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

int G[1001][1001];
int C[1001][1001];

int main(){

    freopen("cowroute.in", "r", stdin);
    freopen("cowroute.out", "w", stdout);

    int a, b, n;
    cin>>a>>b>>n;
    int v = -1;

    for(int i = 0; i <= 1000; i++){
        for(int j = 0; j <= 1000; j++){
            (i == j) ? G[i][j] = 0 : G[i][j] = INT_MAX;
            (i == j) ? C[i][j] = 0 : C[i][j] = INT_MAX;
        }
    }

    for(int i = 0; i < n; i++){
        int c, t;
        cin>>c>>t;
        vector<int> temp(t+1);
        for(int k = 0; k < t; k++){
            cin>>temp[k]; v = max(v, temp[k]);
        }
        for(int k = 0; k < t; k++){
            for(int j = k+1; j < t; j++){
                if(G[temp[k]][temp[j]] > c){
                    G[temp[k]][temp[j]] = c;
                    C[temp[k]][temp[j]] = j-k;
                }
            }
        }
    }

    /*for(int i = 1; i <= v; i++){
        for(int j = 1; j <= v; j++){
            cout<<C[i][j]<<' ';
        }cout<<endl;
    }*/

    long long d[1010]; bool visit[1010]; int city[1010];
    for(int i = 0; i <= 1000; i++){
        d[i] = INT_MAX; visit[i] = false; city[i] = INT_MAX;
    }
    d[a] = 0;
    city[a] = 0;

    for(int i = 0; i < v; i++){
        int pos = -1, value = INT_MAX;

        for(int k = 1; k <= v; k++){
            if(visit[k] == false && value > d[k]){
                value = d[k];
                pos = k;
            }
        }
        if(pos == -1){
            break;
        }
        visit[pos] = true;
        for(int k = 1; k <= v; k++){
            if(!visit[k] && G[pos][k] && d[pos] + G[pos][k] <= d[k]){
                d[k] = d[pos] + G[pos][k];
                if(d[pos] + G[pos][k] == d[k]){
                    city[k] = min(city[k], city[pos] + C[pos][k]);
                }else{
                    city[k] = city[pos] + C[pos][k];
                }
            }
        }
    }
    //cout<<v<<endl;
    /*for(int i = 0; i < v; i++){
        cout<<d[i]<<' '<<city[i]<<endl;
    }*/
    if(d[b] == INT_MAX){
        printf("-1 -1\n");
    }else{
        printf("%lld %d\n", d[b], city[b]);
    }
}

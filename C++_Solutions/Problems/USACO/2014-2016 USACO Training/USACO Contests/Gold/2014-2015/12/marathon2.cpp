/*ID: j316chuck
PROG: marathon
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

int dist[510][510];
int mem[510][510];
int n, k;

int solve(int start, int moves){
    //cout<<start<<' '<<moves<<endl;
    if(mem[start][moves]!=-1){
        return mem[start][moves];
    }if(moves == 1){
        return dist[start][n];
    }
    mem[start][moves] = INT_MAX;
    for(int i = start+1; i < n; i++){
        if(n-i < moves-1){
            continue;
        }else{
            mem[start][moves] = min(mem[start][moves],
                    dist[start][i]+solve(i, moves-1));
        }
    }
    return mem[start][moves];
}

int main(){

    Rd("marathon.in");
    Wt("marathon.out");

    cin>>n>>k;

    memset(dist, -1, sizeof(dist));
    vector<pii> G;
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            mem[i][j] = 999999;
        }
    }

    G.push_back(make_pair(0, 0));
    for(int i = 0; i < n; i++){
        int r, c;
        cin>>r>>c;
        G.push_back(make_pair(r, c));
    }

    for(int i = 1; i < G.size(); i++){
        for(int j = i; j < G.size(); j++){
            dist[i][j] = abs(G[i].first-G[j].first) + abs(G[i].second-G[j].second);
        }
    }

    mem[1][1] = 0;
    for(int i = 2; i <= n-k; i++){
        for(int j = i; j <= n; j++){
            for(int a = i-1; a < j; a++){
                mem[i][j] = min(mem[i][j],
                        mem[i-1][a] + dist[a][j]);
                //cout<<a<<' '<<mem[i-1][a]<<' '<<dist[a][j]<<' '<<mem[i][j]<<endl;
            }
        }
    }
    cout<<mem[n-k][n]<<endl;
   //cout<<solve(1, n-k-1)<<endl;
}


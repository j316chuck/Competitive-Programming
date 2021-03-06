/*ID: j316chuck
PROG: poj_2395 (prim)
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
#define NOPATH 1000000001

using namespace std;

int main(){

    //Rd("5.in");
    //Wt("5.out");

    int n, m, u, v, w;
    cin>>n>>m;
    vector< vector<int> > G(n, vector<int> (n, NOPATH));
    for(int i = 0; i < m; i++){
    	cin>>u>>v>>w;
    	u--; v--;
    	G[u][v] = min(G[u][v], w);
    	G[v][u] = min(G[v][u], w);
    }

    vector<int> D(n, NOPATH);
    vector<bool> visit(n, false);
    D[0] = 0;
    int result = 0;

    for(int i = 0; i < n; i++){
    	int index = -1;
    	for(int j = 0; j < n; j++){
    		if(visit[j]) continue;
    		if(index == -1 || D[index] > D[j]){
    			index = j;
    		}
    	}
    	if(index == -1) break;

    	result = max(result, D[index]);
    	visit[index] = true;

    	for(int j = 0; j < n; j++){
    		if(G[index][j] != NOPATH && G[index][j] < D[j]){
    			D[j] = G[index][j];
    		}
    	}
    }

    printf("%d\n", result);

}

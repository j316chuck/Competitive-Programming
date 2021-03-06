/*ID: j316chuck
PROG: poj_1258 (Kruskal)
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

int parent[10005];
vector< pair<int, pair<int, int> > > G, MST;
int total;

void reset(int n){
	for(int i = 0; i < n; i++)
		parent[i] = i;
	G.clear();
	MST.clear();
	total = 0;
}

int find(int x){
	while(x != parent[x]){
		x = parent[x];
	}
	return x;
}

void Kruskal(){
	sort(G.begin(), G.end());
	for(int i = 0; i < G.size(); i++){
		int pu = find(G[i].second.first);
		int pv = find(G[i].second.second);
		if(pu != pv){
			parent[pu] = parent[pv];
			total += G[i].first;
			MST.push_back(G[i]);
		}
	}
}

int main(){

    //Rd("2.in");
    //Wt("2.out");

    int n, u, v, w;
    while(scanf("%d", &n)!=EOF){
    	reset(n);
    	for(int i = 0; i < n; i++){
    		for(int j = 0; j < n; j++){
    			scanf("%d", &w);
    			if(w == 0) continue;
    			G.push_back(make_pair(w, make_pair(i, j)));
    		}
    	}
    	Kruskal();
    	printf("%d\n", total);
    }
    return 0;
}

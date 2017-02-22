/*ID: j316chuck
PROG: poj_3177 (GRAPH)
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

    Rd("1.in");
    //Wt("1.out");

    int n, m, x, y;
	scanf("%d %d", &n, &m);
    vector<int> degree(n + 1, 0);

    for(int i = 0; i < m; i++){
    	scanf("%d %d", &x, &y);
    	degree[x]++;
    	degree[y]++;
    }

    int total = 0;
    for(int i = 1; i <= n; i++){
    	if(degree[i] == 1){
    		total++;
    	}
    }
    printf("%d\n", (total+1)/2);
    return 0;
}

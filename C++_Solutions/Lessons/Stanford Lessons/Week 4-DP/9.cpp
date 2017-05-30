/*ID: j316chuck
PROG: poj_1655
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

vector<int> tree[20005];
bool used[20005];
int mem[20005];
int cost[20005];

int dfs(int root){
    cost[root] = 0;
    used[root] = true;
    for(int i = 0; i < tree[root].size(); i++){
        if(!used[tree[root][i]]){
            int current = dfs(tree[root][i]);
            cost[root] += current;
            mem[root] = max(mem[root], current);
        }
    }
    used[root] = false;
    return cost[root] + 1;
}

int main(){

    //freopen("9.in", "r", stdin);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        memset(mem, 0, sizeof(mem));
        memset(cost, 0, sizeof(cost));
        memset(tree, 0, sizeof(tree));
        for(int i = 0; i < n-1; i++){
            int x, y;
            cin>>x>>y;
            tree[x].push_back(y);
            tree[y].push_back(x);
        }

        int total = dfs(1)-1;

        int node = 0; int res = INT_MAX;
        for(int i = 1; i <= n; i++){
            int curr = max(total - cost[i], mem[i]);
            if(curr < res){
                res = curr;
                node = i;
            }
        }
        cout<<node<<' '<<res<<endl;
    }

    return 0;

}


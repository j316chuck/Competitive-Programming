/*ID: j316chuck
PROG: superbull
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
#include <functional>

const double Pi=acos(-1.0);
typedef long long LL;

#define Set(a, s) memset(a, s, sizeof (a))
#define Rd(r) freopen(r, "r", stdin)
#define Wt(w) freopen(w, "w", stdout)
#define pii pair<int, int>

using namespace std;

int arr[2010];
int G[2010][2010];
vector< pair<int, pii > > GRAPH;
vector< pair<int, pii > >  MST;
int parent[2010];
int n;
int findset(int x){
    if(x != parent[x])
        parent[x] = findset(parent[x]);
    return parent[x];
}


int main(){

    Rd("superbull.in");
    Wt("superbull.out");

    cin>>n;
    for(int i = 0; i < 2001; i++)
        parent[i] = i;

    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            G[i][j] = arr[i] ^ arr[j];
            GRAPH.push_back(make_pair(G[i][j], make_pair(i, j)));
        }
    }

    sort(GRAPH.begin(), GRAPH.end()); // increasing weight
    reverse(GRAPH.begin(), GRAPH.end());

    long long total = 0;
    for(int i = 0; i < GRAPH.size() ; i++){
        int pu = findset(GRAPH[i].second.first);
        int pv = findset(GRAPH[i].second.second);
        if(pu != pv){
            parent[pu] = parent[pv];
            MST.push_back(GRAPH[i]);
            //MST.insert(GRAPH[i].second.second); // add to tree
            total += GRAPH[i].first; // add edge cost
        }
        if(MST.size() == n-1){
            cout<<total<<endl;
            return 0;
        }
    }
    //cout<<total<<endl;
    //return 0;

}



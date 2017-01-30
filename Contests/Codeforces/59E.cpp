/*
ID: peiqistar1
PROG: StudyDijkstra
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
    int v, w;
    bool operator <(const pp&a) const
    {
        return w>a.w;
    }
};

set< pair<int, pair<int, int> > > S;
int parent[3001];

int main(){

    Rd("59E.in");
    int n, m, k;
    cin>>n>>m>>k;
    priority_queue<pp> Q;
    vector<pp> G[n+1];
    int u, v;
    for(int i = 0; i < m; i++){
        cin>>u>>v;
        pp ei;
        ei.v = v;
        ei.w = 1;
        G[u].push_back(ei);
    }
    for(int i = 0; i < k; i++){
        int a, b, c;
        S.insert(make_pair(a, make_pair(b, c)));
    }
    for(int i = 0; i < S.size(); i++){
        cout<<S[i].first<<endl;
    }
}


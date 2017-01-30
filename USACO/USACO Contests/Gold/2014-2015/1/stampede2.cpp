/*ID: j316chuck
PROG: stampede
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

vector<int> S; vector<int> E;

class pp{
public:
    int x, y, r;
	bool operator < (const pp &a) const{
		return (y > a.y);   // sort from low to high
	}
};

int main(){

    freopen("stampede.in", "r", stdin);
    freopen("stampede.out", "w", stdout);

    int n;
    cin>>n;
    vector< pair<int, pair<int, int> > > G;
    set<int> st;

    for(int i = 0; i < n; i++){
        int x, y, r;
        cin>>x>>y>>r;
        x = x * -r;
        G.push_back(make_pair(y, make_pair(x - r, x)));
        st.insert(x); st.insert(x-r);
    }
    sort(G.begin(), G.end());

    int total = 0;
    for(int i = 0; i < G.size(); i++){
        set<int>:: iterator it = st.lower_bound(G[i].second.first);
        set<int>:: iterator jt = st.lower_bound(G[i].second.second);
        if(it!=jt){
            total++;
            st.erase(it, jt);
        }
    }

    printf("%d\n", total);
}

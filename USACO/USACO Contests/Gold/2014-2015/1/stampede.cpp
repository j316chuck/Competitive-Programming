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
	bool operator < (const pp &a) const
	{
		return (y > a.y);   // sort from low to high
	}
};

int main(){

    freopen("stampede.in", "r", stdin);
    //freopen("stampede.out", "w", stdout);

    int n;
    cin>>n;
    vector<pp> G;

    for(int i = 0; i < n; i++){
        pp ei;
        cin>>ei.x>>ei.y>>ei.r;
        G.push_back(ei);
    }
    sort(G.begin(), G.end());

    vector<pii> V;
    for(int i = 0; i < G.size(); i++){
        V.push_back(make_pair((-1-G[i].x) * G[i].r, -G[i].x * G[i].r));
    }
    S.push_back(V[0].first); E.push_back(V[0].second);
    int counter = 1;

    for(int i = 1; i < V.size(); i++){
        int u = V[i].first, v = V[i].second;
        if(u > E[len-1]){
            S.push_back(u); E.push_back(v);
            counter++; continue;
        }
        /*int l = 0; int r = E.size() - 1; int mid = (lo + hi)/2;
        while(l <= r){
            if(mid == 0 || mid == E.size()-1){
                break;
            }else if(E[mid] < u && E[mid] >= u){
                break;
            }else if(E[mid] < u ){
                low = mid+1;
            }else if(E[mid] > u){
                high = mid-1
            }
            mid = (low + high)/2;
        }*/
        //sort(E.begin(), E.end())
    }

}

/*ID: j316chuck
PROG: lasers
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

class pp{
public:
    int x, y, c;
    bool v;
    bool operator < (const pp & a) const{
        return c > a.c; //sort from low to high
    }
};

bool visit[100001];
vector<pii> mirrors;
priority_queue<pp> pq;

int main(){

    freopen("lasers.in", "r", stdin);
    freopen("lasers.out", "w", stdout);

    int n, xl, yl, xb, yb;
    cin>>n>>xl>>yl>>xb>>yb;
    int x, y;
    for(int i = 0; i < n; i++){
        cin>>x>>y;
        mirrors.push_back(make_pair(x, y));
    }

    pp a; a.x = xl; a.y = yl; a.v = true; a.c = 0;
    pq.push(a);
    pp b; b.x = xl; b.y = yl; b.v = false; b.c = 0;
    pq.push(b);

    while(!pq.empty()){
        pp curr = pq.top();
        pq.pop();
        if(curr.x == xb || curr.y == yb){
            cout<<curr.c<<endl;
            return 0;
        }
        for(int i = 0; i < mirrors.size(); i++){
            if(visit[i] == false && curr.v == true && mirrors[i].first == curr.x){
                visit[i] = true;
                pp ei; ei.x = mirrors[i].first; ei.y = mirrors[i].second; ei.v = false; ei.c = curr.c+1;
                pq.push(ei);
            }else if(visit[i] == false && curr.v == false && mirrors[i].second == curr.y){
                visit[i] = true;
                pp ei; ei.x = mirrors[i].first; ei.y = mirrors[i].second; ei.v = true; ei.c = curr.c+1;
                pq.push(ei);
            }
        }
    }

    cout<<-1<<endl;
    return 0; //done with code yayyy!!!!
}
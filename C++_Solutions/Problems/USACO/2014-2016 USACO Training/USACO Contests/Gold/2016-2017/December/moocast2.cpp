/*ID: j316chuck
PROG: checklist
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

vector<int> parent(1000);

void initset(int size){
    parent.resize(size);
    for(int i = 0; i < size+1; i++){
        parent[i] = i;
    }
}
int findset(int x){
    if(x!=parent[x]){
        parent[x] = findset(parent[x]);
    }
    return parent[x];
}
void unionset(int i, int j){
   parent[findset(i)] = findset(j);
}

int dist(pair<int, int> a, pair<int, int> b){
    return (a.first-b.first) * (a.first-b.first) + (a.second-b.second)*(a.second-b.second);
}
class pp{
public:
    int u, v, w;
     bool operator < (const pp & a) const{
        return w > a.w; //sort from low to high
    }
};

int main(){

    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);
    int n;
    cin>>n;
    vector< pair<int, int> > graph;
    for(int i = 0; i < n; i++){
        pair<int, int> a; cin>>a.first>>a.second;
        graph.push_back(a);
    }
    initset(n);
    priority_queue<pp> Q;
    //cout<<n<<endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            pp ei; ei.w = dist(graph[i], graph[j]); ei.u = i; ei.v = j;
            Q.push(ei);
        }
    }
    int total = -1;
    int num = 0;
    while(!Q.empty()){
        if(num == n-1){
            cout<<total<<endl;
            break;
        }
        pp top = Q.top();
        Q.pop();
        total = max(total, top.w);
        int pu = findset(top.u);
        int pv = findset(top.v);
        if(pu != pv){
            unionset(pu, pv);
            num++;
        }
    }
    return 0;
}


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

using namespace std;

int mem[1005][1005];
vector< pair<int, int> > H;
vector< pair<int, int> > G;

int dist(int x1, int x2, int y1, int y2){
    return (x1-x2) * (x1-x2) + (y1-y2) * (y1-y2);
}

int dfs(int h, int g, int pasth){
    cout<<h<<' '<<g<<endl;
    if(mem[h][g]!=-1){
        return mem[h][g];
    }else if(h == H.size()-1 && g == G.size()){
        return dist(G[g].first, G[g].first, G[g].second, G[g+1].second)+dfs(h, g+1, 1);
    }else if(h == H.size()-1 && g == G.size()){
        return 0;
    }else if(g == G.size()){
        return dist(H[h].first, H[h+1].first, H[h].second, H[h+1].second) + dfs(h+1, g,0);
    }else{
        pair<int, int> curr;
        if(pasth == 0){
            curr.first = H[h].first;
            curr.second = H[h].second;
        }else{
            curr.first = G[g].first;
            curr.second = G[g].second;
        }
        int d1 = dist(curr.first, H[h+1].first ,curr.second, H[h+1].second);
        int d2 = dist(curr.first, G[g+1].first, curr.second, G[g+1].second);
        cout<<d1<<' '<<d2<<endl;
        mem[h][g] = min(d1 + dfs(h+1, g, 0), d2 + dfs(h, g+1, 1));
        return mem[h][g];
    }
}

int main(){
    Rd("checklist.in");
    //Wt("checklist.out");
    int h, g;
    cin>>h>>g;
    pair<int, int> a;
    for(int i = 0; i < h; i++){
        cin>>a.first>>a.second;
        H.push_back(a);
    }
    for(int i = 0; i < g; i++){
        cin>>a.first>>a.second;
        G.push_back(a);
    }
    memset(mem, -1, sizeof(mem));
    cout<<dfs(0, -1, 0)<<endl;
}

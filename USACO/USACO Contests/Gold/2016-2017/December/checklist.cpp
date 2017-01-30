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

int graph[1005][1005];

int dist(int x1, int x2, int y1, int y2){
    return (x1-x2) * (x1-x2) + (y1-y2) * (y1-y2);
}

int main(){

    Rd("checklist.in");
    Wt("checklist.out");

    int h, g;
    cin>>h>>g;
    vector< pair<int, int> > H;
    vector< pair<int, int> > G;
    pair<int, int> a;
    H.push_back(make_pair(0, 0));
    for(int i = 0; i < h; i++){
        cin>>a.first>>a.second;
        H.push_back(a);
    }G.push_back(make_pair(0, 0));
    for(int i = 0; i < g; i++){
        cin>>a.first>>a.second;
        G.push_back(a);
    }
    for(int i = 0; i <= g; i++){
        graph[0][i] = 0;
    }
    graph[1][0] = 0;
    for(int i = 2; i <= h; i++){
        graph[i][0] = graph[i-1][0]+dist(H[i].first, H[i-1].first, H[i].second, H[i-1].second);
    }
    graph[1][1] = dist(G[1].first, H[1].first, G[1].second, H[1].second);
    for(int i = 2; i <= g; i++){
        graph[1][i] = graph[1][i-1] + dist(G[i].first, G[i-1].first, G[i].second, G[i-1].second);
    }
    for(int i = 0; i <= g; i++){
        graph[h][i] = INT_MAX;
    }
    for(int i = 2; i < h; i++){
        for(int j = 1; j <= g; j++){
            int top = graph[i-1][j] + dist(H[i].first, G[j].first, H[i].second, G[j].second);
            int left = graph[i][j-1] + dist(H[i].first, H[i-1].first, H[i].second, H[i-1].second);
            if(j == 1 && i == 2){
                graph[i][j] = top;
            }else if(j == 1 && i!=2){
                graph[i][j] = left;
            }else{
                graph[i][j] = min(top, left);
            }
            //cout<<graph[i][j]<<' ';
        }//cout<<endl;
    }
    /*for(int i = 0; i <= h; i++){
        for(int j = 0; j <=g; j++){
            cout<<graph[i][j]<<' ';
        }cout<<endl;
    }*/
    graph[h][g] = graph[h-1][g] + dist(H[h].first, H[h-1].first, H[h].second, H[h-1].second);
    cout<<graph[h][g]<<endl;
}

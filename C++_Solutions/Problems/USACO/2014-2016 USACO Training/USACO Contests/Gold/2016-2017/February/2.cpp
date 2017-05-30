/*ID: j316chuck
PROG:
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
#define NOPATH 10000000000
using namespace std;

long long graph[105][105];
int n, t;

class pp{
public:
    int v;
    long long w;
    bool operator < (const pp &a) const{
        return w > a.w;
    }
};

int nd(int r, int c){
    return n * r + c;
}

int main(){

    Rd("visitfj.in");
    Wt("visitfj.out");

    cin>>n>>t;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin>>graph[i][j];
        }
    }
    int dx[12] = {-3, -2, -1, 0, 1, 2, 3, 2, 1, 0, -1, -2};
    int dy[12] = {0, 1, 2, 3, 2, 1, 0, -1, -2, -3, -2, -1};
    vector<int> G[10005];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int u = nd(i, j);
            for(int k = 0; k < 12; k++){
                int nx = i + dx[k];
                int ny = j + dy[k];
                if(nx < 0 || ny < 0 || ny >= n|| nx >= n) continue;
                int v = nd(nx, ny);
                G[u].push_back(v);
            }
        }
    }

    vector<long long> D(10005, NOPATH);
    priority_queue<pp> Q;
    D[0] = 0;
    pp ei; ei.v = 0; ei.w = 0;
    Q.push(ei);
    while(!Q.empty()){
        int u = Q.top().v;
        int r = u/n;
        int c = u%n;
        Q.pop();
        if(r == (n-1) && c == n-3){
            D[n * n - 1] =  min(D[n * n - 1], D[u] + 2 * t);
            continue;
        }else if(r == (n-1) && c == n-2){
            D[n * n - 1] =  min(D[n * n - 1], D[u] + t);
            continue;
        }else if(r == (n-3) && c == n-1){
            D[n * n - 1] =  min(D[n * n - 1], D[u] + 2 * t);
            continue;
        }else if(r == (n-3) && c == n-2){
            D[n * n - 1] =  min(D[n * n - 1], D[u] + t);
            continue;
        }else if(r == (n-2) && c == n-2){
            D[n * n - 1] =  min(D[n * n - 1], D[u] + 2 * t);
            continue;
        }
        for(int i = 0; i < G[u].size(); i++){
            int v = G[u][i];
            int w = D[u] + 3 * t + graph[v/n][v%n];
            if(w < D[v]){
                D[v] = w;
                ei.v = v; ei.w = w;
                Q.push(ei);
            }
        }
    }
    cout<<D[n*n - 1]<<endl;
    return 0;
}



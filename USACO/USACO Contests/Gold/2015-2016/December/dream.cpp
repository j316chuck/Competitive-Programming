/*
ID: j316chuck
PROG: dream
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

const double Pi=acos(-1.0);
typedef long long LL;

#define Set(a, s) memset(a, s, sizeof (a))
#define Rd(r) freopen(r, "r", stdin)
#define Wt(w) freopen(w, "w", stdout)

using namespace std;

int graph[1001][1001];
bool visited[1001][1001][4]; //0 north 1 west 2 south 3 east
int maximum = INT_MAX;
int n, m;

void dfs(int x, int y, int prev_dir, bool smell, int moves){
    //cout<<x<<' '<<y<<' '<<' '<<prev_dir<<' '<<moves<<endl;
    if(x == n-1 && y == m-1){
        maximum = min(maximum, moves);
        return;
    }if(x >= n || y >=m || y < 0 || x < 0){
        return;
    }if(graph[x][y] == 0){
        return;
    }if(graph[x][y] == 3 && smell == false){
        return;
    }if(maximum < moves){
        return;
    }if(visited[x][y][prev_dir]){
        return;
    }else{
        visited[x][y][prev_dir] = true;
        if(graph[x][y] == 2)
            smell = true;
        if(graph[x][y] == 1 || graph[x][y] == 3 || graph[x][y] == 2){
            dfs(x+1, y, 0, smell, moves+1);
            dfs(x, y+1, 1, smell, moves+1);
            dfs(x-1, y, 2, smell, moves+1);
            dfs(x, y-1, 3, smell, moves+1);
        }if(graph[x][y] == 4){
            if(prev_dir == 0){
                dfs(x+1, y, 0, false, moves+1);
            }if(prev_dir == 1){
                dfs(x, y+1, 1, false, moves+1);
            }if(prev_dir == 2){
                dfs(x-1, y, 2, false, moves+1);
            }if(prev_dir == 3){
                dfs(x, y-1, 3, false, moves+1);
            }
        }
        visited[x][y][prev_dir] = false;
    }
}

int main(){

    freopen("dream.in", "r", stdin);
    freopen("dream.out", "w", stdout);

    cin>>n>>m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin>>graph[i][j];
        }
    }

    dfs(0, 0, 0, false, 0);

    cout<<maximum<<endl;

    return 0;
}


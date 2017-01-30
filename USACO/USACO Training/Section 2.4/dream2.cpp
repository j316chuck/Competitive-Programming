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

/*void dfs(int x, int y, int prev_dir, bool smell, int moves){
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
}*/
class pp{
public:
    int x, y, moves, dir;
    bool smell;

	bool operator < (const pp &a) const
	{
		return (moves > a.moves);   // sort from low to high
	}
};


int main(){

    freopen("dream.in", "r", stdin);
    //freopen("dream.out", "w", stdout);

    cin>>n>>m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin>>graph[i][j];
        }
    }
    priority_queue<pp> Q;
    pp s;
    s.x = 0; s.y = 0; s.moves = 0; s.dir = -1; s.smell = false;
    Q.push(s);

    while(!Q.empty()){
        pp a = Q.top();
        Q.pop();
        if(a.x >= n || a.y >=m || a.x < 0 || a.y < 0){
            continue;
        }else if(maximum < a.moves){
            continue;
        }else if(visited[a.x][a.y][a.dir]){
            continue;
        }else if(graph[a.x][a.y] == 0){
            continue;
        }else if(graph[a.x][a.y] == 3 && a.smell == false){
            continue;
        }else if(a.x == n-1 && a.y == m-1){
            maximum = min(maximum, a.moves);
            break;
        }else{
            visited[a.x][a.y][a.dir] = true;
            a.moves+=1;
            pp nt = a; pp et = a; pp st = a; pp wt = a;
            nt.y+=1; nt.dir = 0;
            st.y-=1; st.dir = 2;
            et.x+=1; et.dir = 1;
            wt.x-=1; wt.dir = 3;
            if(graph[a.x][a.y] == 2){
                a.smell = true;
            }if(graph[a.x][a.y] == 2 ||graph[a.x][a.y] == 3|| graph[a.x][a.y]==1){
                Q.push(nt); Q.push(et); Q.push(st); Q.push(wt);
            }if(graph[a.x][a.y] == 4){
                a.smell = false;
                if(a.dir == 0){
                    Q.push(nt);
                }else if(a.dir == 1){
                    Q.push(et);
                }else if(a.dir == 2){
                    Q.push(st);
                }else if(a.dir == 3){
                    Q.push(wt);
                }
            }
        }
    }
    if(maximum == INT_MAX){
        cout<<-1<<endl;
    }else{
        cout<<maximum<<endl;
    }
    return 0;
}



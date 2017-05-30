/*
ID: j316chuck
PROG: cownav
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

char G[21][21];
int parent[21][21][4];
int D[21][21][4];
int N;

pair<int, int> shift(int i, int j, int dir){
    pair<int, int> a = make_pair(i,j);
    if(i == N && j == N){
        return make_pair(i, j);
    }
    if(dir == 0){
        a.first--;
    }else if(dir == 1){
        a.second++;
    }else if(dir == 2){
        a.first++;
    }else if(dir == 3){
        a.second--;
    }
    bool can = true;
    if(a.first < 1 || a.first > N || a.second < 1 || a.second > N){
        can = false;
    }else if(G[a.first][a.second] == 'H'){
        can = false;
    }
    if(can){
        return a;
    }else{
        return make_pair(i, j);
    }
}

int mem[21][21][4][21][21][4];
int visited[21][21][4][21][21][4];

/*int dp(int x1, int y1, int d1, int x2, int y2, int d2){
    //cout<<x1<<' '<<y1<<' '<<d1<<' '<<x2<<' '<<y2<<' '<<d2<<endl;
    if(x1 == N && y1 == N){
        return D[x2][y2][d2];
    }if(x2 == N && y2 == N){
        return D[x1][y1][d1];
    }if(mem[x1][y1][d1][x2][y2][d2]!=-1){
        return mem[x1][y1][d1][x2][y2][d2];
    }
    int res = 1+dp(x1, y1, (d1+1)%4, x2, y2, (d2+1)%4);
    res = min(res, 1+dp(x1, y1, (d1+3)%4, x2, y2, (d2+3)%4));
    pair<int, int> one = shift(x1, y1, d1);
    pair<int, int> two = shift(x2, y2, d2);
    res = min(res, 1+dp(one.first, one.second, d1,
                      two.first, two.second, d2));
    mem[x1][y1][d1][x2][y2][d2] = res;
    return res;
}*/

class pp{
public:
    int x1, x2, y1, y2, d1, d2, w;
    bool operator < (const pp &a) const{
		return (w > a.w);   // sort from low to high
	}
};
int main(){

    Rd("cownav.in");
    //Wt("cownav.out");
    cin>>N;

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cin>>G[i][j];
        }
    }
    memset(D, -1, sizeof(D));
    priority_queue< pair<int, pair<int, int> > > Q;
    Q.push(make_pair(N, make_pair(N, 0)));
    Q.push(make_pair(N, make_pair(N, 3)));
    D[N][N][0] = 0; D[N][N][3] = 0;
    D[N][N][1] = 0; D[N][N][2] = 0;
    while(!Q.empty()){
        pair<int, pair<int, int> > top = Q.top();
        int x = top.first; int y = top.second.first;
        int dir = top.second.second;
        Q.pop();
        pair<int, int> m = shift(x, y, dir);
        if(D[m.first][m.second][dir] == -1){
            D[m.first][m.second][dir] = D[x][y][dir]+1;
            Q.push(make_pair(m.first, make_pair(m.second, dir)));
            parent[m.first][m.second][dir] = 1;
        }if(D[x][y][(dir+1)%4] == -1){
            D[x][y][(dir+1)%4] = D[x][y][dir]+1;
            Q.push(make_pair(x, make_pair(y, (dir+1)%4)));
            parent[x][y][(dir+1)%4] = 2;
        }if(D[x][y][(dir+3)%4] == -1){
            D[x][y][(dir+3)%4] = D[x][y][dir]+1;
            Q.push(make_pair(x, make_pair(y, (dir+3)%4)));
            parent[x][y][(dir+3)%4] = 3;
        }
    }
    memset(mem, -1, sizeof(mem));
    //cout<<dp(1, 1, 1, 1, 1, 2)<<endl;
    pp ei;
    ei.x1 = 1; ei.x2 = 1; ei.y1 = 1; ei.y2 = 1; ei.d1 = 1; ei.d2 = 2;
    ei.w = 0;
    priority_queue<pp> pq;
    pq.push(ei);
    memset(visited, -1, sizeof(visited));
    while(!pq.empty()){
        pp top = pq.top();
        pq.pop();
        int x1 = top.x1, x2 = top.x2, y1 = top.y1, y2 = top.y2,
        d1 = top.d1, d2 = top.d2;
        int w =top.w;
        //cout<<x1<<y1<<x2<<y2<<w<<endl;
        if(x1 == N && y1 == N && x2 == N && y2 == N){
            cout<<w<<endl;
            return 0;
        }
        pair<int, int> one = shift(x1, y1, d1);
        pair<int, int> two = shift(x2, y2, d2);
        if(visited[one.first][one.second][d1][two.first][two.second][d2] == -1){
            visited[one.first][one.second][d1][two.first][two.second][d2] = w + 1;
            ei.x1 = one.first, ei.y1 = one.second, ei.d1 = d1;
            ei.x2 = two.first, ei.y2 = two.second, ei.d2 = d2;
            ei.w = w+1;
            pq.push(ei);
        }
        d1 = (d1+1)%4;
        d2 = (d2+1)%4;
        if(visited[x1][y1][d1][x2][y2][d2] == -1){
            visited[x1][y1][d1][x2][y1][d2] = w+1;
            ei.x1 = x1, ei.y1 = y1, ei.d1 = d1;
            ei.x2 = x2, ei.y2 = y2, ei.d2 = d2;
            ei.w = w+1;
            pq.push(ei);
        }
        d1 = (d1+2)%4;
        d2 = (d2+2)%4;
        if(visited[x1][y1][d1][x2][y2][d2] == -1){
            visited[x1][y1][d1][x2][y1][d2] = w+1;
            ei.x1 = x1, ei.y1 = y1, ei.d1 = d1;
            ei.x2 = x2, ei.y2 = y2, ei.d2 = d2;
            ei.w = w+1;
            pq.push(ei);
        }
    }
}

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

int N;
char G[41][41];
int visit[21][21][4][21][21][4];

class pp{
public:
    int x1, x2, y1, y2, d1, d2, w;
    bool operator < (const pp &a) const{
		return (w > a.w);   // sort from low to high
	}
};

pair<int, int> shift(int i, int j, int dir){
    pair<int, int> a = make_pair(i, j);
    if(i == N && j == N){
        return a;
    }
    if(dir == 0){
        a.first--;
    }else if(dir == 2){
        a.first++;
    }else if(dir == 1){
        a.second++;
    }else if(dir == 3){
        a.second--;
    }
    if(a.first < 1 || a.second < 1 || a.first > N || a.second > N
       || G[a.first][a.second] == 'H'){
        return make_pair(i, j);
    }
    return a;
}

int main(){

    Rd("cownav.in");
    Wt("cownav.out");
    cin>>N;

    for(int i = N; i >= 1; i--){
        for(int j = 1; j <= N; j++){
            cin>>G[i][j];
        }
    }

    memset(visit, -1, sizeof(visit));
    queue<pp> Q;
    pp ei; ei.x1 = 1; ei.x2 = 1; ei.y1 = 1; ei.y2 = 1; ei.d1 = 1; ei.d2 = 2; ei.w = 0;
    Q.push(ei);

    while(!Q.empty()){
        pp top = Q.front();
        Q.pop();
        int x1 = top.x1, x2 = top.x2, y1 = top.y1, y2 = top.y2;
        int d1 = top.d1, d2 = top.d2, w = top.w;
        if(x1 == N && y1 == N && x2 == N && y2 == N){
            cout<<w<<endl;
            return 0;
        }
        pair<int, int> pii = shift(x1, y1, d1);
        pair<int, int> eii = shift(x2, y2, d2);
        if(visit[pii.first][pii.second][d1][eii.first][eii.second][d2] == -1){
            visit[pii.first][pii.second][d1][eii.first][eii.second][d2] = w+1;
            pp ai = top; ai.x1 = pii.first; ai.y1 = pii.second;
            ai.w = w+1; ai.x2 = eii.first; ai.y2 = eii.second;
            Q.push(ai);
        }
        d1 = (top.d1+1)%4;
        d2 = (top.d2+1)%4;
        if(visit[x1][y1][d1][x2][y2][d2] == -1){
            visit[x1][y1][d1][x2][y2][d2] = w+1;
            pp ai = top; ai.d1 = d1; ai.d2 = d2; ai.w = w+1;
            Q.push(ai);
        }
        d1 = (top.d1+3)%4;
        d2 = (top.d2+3)%4;
        if(visit[x1][y1][d1][x2][y2][d2] == -1){
            visit[x1][y1][d1][x2][y2][d2] = w+1;
            pp ai = top; ai.d1 = d1; ai.d2 = d2; ai.w = w+1;
            Q.push(ai);
        }
    }

    return 0;

}


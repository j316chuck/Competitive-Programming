/*
ID: j316chuck
PROG: ttwo
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

char graph[11][11];
int mem[401][401];

int nd(int r, int c, int dir){
    return 100*dir + 10*r + c;
}

class pp{
public:
    int r, c, dir;
};

bool pathable(int r, int c){
    if(r < 0 || r >= 10 || c < 0 || c >= 10){
        return false;
    }if(graph[r][c] == '*'){
        return false;
    }
    return true;
}

int main(){

    freopen("ttwo.in", "r", stdin);
    freopen("ttwo.out", "w", stdout);

    memset(mem, -1, sizeof(mem));

    pp f, c;
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            cin>>graph[i][j];
            if(graph[i][j] == 'F'){
                graph[i][j] = '.';
                f.r = i; f.c = j; f.dir = 0;
            }else if(graph[i][j] == 'C'){
                graph[i][j] = '.';
                c.r = i; c.c = j; c.dir = 0;
            }
        }
    }

    int time = 0;
    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};

    while(mem[nd(f.r, f.c, f.dir)][nd(c.r, c.c, c.dir)] != 0 ){
        int pf = nd(f.r, f.c, f.dir), pc = nd(c.r, c.c, c.dir);
        mem[pf][pc] = 0;
        //cout<<f.r<<' '<<f.c<<' '<<c.r<<' '<<c.c<<endl;
        if(f.r == c.r && f.c == c.c){
            printf("%d\n", time);
            return 0;
        }
        time++;
        if(pathable(dr[f.dir] + f.r, dc[f.dir] + f.c)){
            f.r += dr[f.dir]; f.c += dc[f.dir];
        }else{
            f.dir += 1; f.dir = f.dir % 4;
        }
        if(pathable(dr[c.dir] + c.r, dc[c.dir] + c.c)){
            c.r += dr[c.dir]; c.c += dc[c.dir];
        }else{
            c.dir += 1; c.dir = c.dir % 4;
        }
    }

    printf("0\n");
    return 0;

}

/*ID: j316chuck
PROG: radio
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

int n, m;
int mem[1001][1001];

int distance(pair<int, int> a, const pair<int, int> 7c){
    return (a.first-c.first)*(a.first-c.first) + (a.second-c.second)*(a.second-c.second);
}
int move_x(pair<int, int> b, char c){
    if(c == 'N' || c == 'S'){
        return b.first;
    }else if(c == 'E'){
        return b.first+1;
    }else{
        return b.first-1;
    }
}
int move_y(pair<int, int> b, char c){
    if(c == 'E' || c == 'W'){
        return b.second;
    }else if(c == 'N'){
        return b.second+1;
    }else{
        return b.second-1;
    }
}

int dfs(string p1, string p2, pair<int, int> j, pair<int, int> b){
    int x = p1.size(), y = p2.size();
    if(mem[x][y]!=-1){
        return mem[x][y];
    }else if(x == 0 && y == 0){
        mem[x][y] = 2 * distance(j, b);
        return mem[x][y];
    }else if(x == 0){
        mem[x][y] = 2 * distance(j, b);
        b.first = move_x(b, p2[0]);
        b.second = move_y(b, p2[0]);
        mem[x][y] += dfs(p1, p2.substr(1), j, b);
        return mem[x][y];
    }else if(y == 0){
        mem[x][y] = 2 * distance(j, b);
        j.first = move_x(j, p1[0]);
        j.second = move_y(j, p1[0]);
        mem[x][y] += dfs(p1.substr(1), p2, j, b);
        return mem[x][y];
    }else{
        mem[x][y] += 2 * distance(j, b);
        pair<int, int> temp;
        temp.first = j.first; temp.second = j.second;

        j.first = move_x(j, p1[0]);
        j.second = move_y(j, p1[0]);
        int x1 = dfs(p1.substr(1), p2, j, b);
        b.first = move_x(b, p2[0]);
        b.second = move_y(b, p2[0]);
        int y1 = dfs(p1, p2.substr(1), temp, b);
        int both = dfs(p1.substr(1), p2.substr(1), j, b);
        mem[x][y]+=min(both, min(x1, y1));
        return mem[x][y];
    }
}

int main(){

    freopen("radio.in", "r", stdin);
    //freopen("radio.out", "w", stdout);
    memset(mem, -1, sizeof(mem));
    cin>>n>>m;
    pair<int, int> j;
    pair<int, int> b;
    cin>>j.first>>j.second>>b.first>>b.second;
    string p1;
    cin>>p1;
    string p2;
    cin>>p2;

    cout<<dfs(p1, p2, j, b)-2*distance(j,b)<<endl;

}

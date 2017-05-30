/*
ID: j316chuck
PROG: maze1
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

char graph[203][101];
int mem[203][101];
int w, h;

bool pathable(int r, int c){
    if(r == 1 || r == 2 * h + 1 || c == 1 || c == 2 * w + 1){
        return false;
    }else if(graph[r][c] == '-'){
        return false;
    }
    return true;
}

int main(){

    freopen("maze1.in", "r", stdin);
    freopen("maze1.out", "w", stdout);

    cin>>w>>h;
    for(int i = 0; i < 201; i++){
        for(int j = 0; j < 101; j++){
            mem[i][j] = INT_MAX;
        }
    }
    string s; getline(cin, s);
    for(int i = 1; i <= 2*h+1; i++){
        getline(cin, s);
        if(s.length() < 2*w+1){
            for(int j = s.length()+1; j <= 2*w+1; j++){
                graph[i][j] = '*';
            }
        }
        for(int j = 1; j <= s.length(); j++){
            graph[i][j] = (s[j-1] == ' ') ? '*': '-';
        }
    }

    int x[3]; int y[3]; int counter = 0;
    for(int i = 1; i <= 2*h+1; i++){
        for(int j = 1; j <= 2*w+1; j++){
            if((i == 1) && graph[i][j] == '*'){
                y[counter] = i+1; x[counter] = j; counter++;
            }if((i == 2*h+1) && graph[i][j] == '*'){
                y[counter] = i-1; x[counter] = j; counter++;
            }if((j == 1) && graph[i][j] == '*'){
                y[counter] = i; x[counter] = j+1; counter++;
            }if((j == 2*w+1) && graph[i][j] == '*'){
                y[counter] = i; x[counter] = j-1; counter++;
            }
        }
    }

    queue< pair<int, pair<int, int> > > q;
    q.push(make_pair(1, make_pair(y[0], x[0])));
    q.push(make_pair(1, make_pair(y[1], x[1])));

    int res = -1;
    while(!q.empty()){
        pair<int, pair<int, int> > top = q.front();
        q.pop();

        int r = top.second.first; int c = top.second.second; int weight = top.first;
        if(mem[r][c] > weight){
            mem[r][c] = weight;
            res = max(res, mem[r][c]);

            if(pathable(r+1, c)){
                q.push(make_pair(weight+1, make_pair(r+2, c)));
            }if(pathable(r-1, c)){
                q.push(make_pair(weight+1, make_pair(r-2, c)));
            }if(pathable(r, c+1)){
                q.push(make_pair(weight+1, make_pair(r, c+2)));
            }if(pathable(r, c-1)){
                q.push(make_pair(weight+1, make_pair(r, c-2)));
            }
        }
    }
    printf("%d\n", res);
}

/*
ID: j316chuck
PROG: feast
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

bool visited[5000001][2];
int t, a, b;

void dfs(int curr, bool half){
    if(visited[curr][half]){
        return;
    }else if(curr > t){
        return;
    }else if(curr == t){
        visited[curr][half] = true;
        return;
    }else{
        visited[curr][half] = true;
        dfs(curr+a, half);
        dfs(curr+b, half);
        if(half == false){
            dfs(curr/2, true);
        }
    }
}

int main(){

    freopen("feast.in", "r", stdin);
    freopen("feast.out", "w", stdout);

    cin>>t>>a>>b;
    dfs(0, false);
    for(int i = t; i>=0; i--){
        if(visited[i][0]||visited[i][1]){
            cout<<i<<endl;
            break;
        }
    }
    return 0;
}


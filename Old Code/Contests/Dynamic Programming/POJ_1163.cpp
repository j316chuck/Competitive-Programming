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

int main(){

    //freopen("POJ_1163.in", "r", stdin);
    int n;
    cin>>n;

    int graph[101][101];

    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++){
            cin>>graph[i][j];
        }
    }

    for(int i = n-2; i >= 0; i--){
        for(int j = 0; j <= i; j++){
            graph[i][j] = graph[i][j]+max(graph[i+1][j], graph[i+1][j+1]);
        }
    }
    cout<<graph[0][0]<<endl;
}


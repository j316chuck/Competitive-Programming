/*
ID: peiqistar1
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

const double Pi=acos(-1.0);
typedef long long LL;

#define Set(a, s) memset(a, s, sizeof (a))
#define Rd(r) freopen(r, "r", stdin)
#define Wt(w) freopen(w, "w", stdout)

using namespace std;

int graph[101][101];
int d[101];
int parent[101];
int n;
bool intree[101];
int total;

int main(){

    Rd("prim.in");
    cin>>n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin>>graph[i][j];
        }
    }
    for(int i = 1; i <= n; i++){
        intree[i] = false; d[i] = INT_MAX; parent[i] = -1;
    }
    d[1] = 0;
    parent[1] = 1;
    for(int i = 1; i <= n; i++){
        int value = INT_MAX, index = -1;
        //cout<<value<<endl;
        for(int j = 1; j <= n; j++){
            if(!intree[j] && d[j] < value){
                value = d[j];
                index = j;
            }
        }
        //cout<<index<<endl;
        intree[index] = true;
        total+=d[index];
        //cout<<index<<endl;

        for(int j = 1; j <= n; j++){
            if(graph[index][j]!=0 && graph[index][j] < d[j] && intree[j] == false){
                parent[j] = index;
                d[j] = graph[index][j];
            }
        }
    }
    cout<<total<<endl;
}

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

int n, m;
int graph[101][101];
int d[101];
bool intree[101];
//bool part[101];
int total;

int main(){

    freopen("poj_2421.in", "r", stdin);

    cin>>n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &graph[i][j]);
            if(graph[i][j] == 0){
                graph[i][j] = -1;
            }
        }
    }

    cin>>m;
    for(int i = 0; i < n; i++){
        intree[i] = false; d[i] = INT_MAX;
    }

    for(int i = 0; i < m; i++){
        int a, b;

        cin>>a>>b;
        intree[--a] = true;
        intree[--b] = true;
        d[a] = 0; d[b] = 0;
        //graph[--a][--b] = 0;
        //graph[b][a] = 0;
    }
    /*for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout<<graph[i][j]<<' ';
        }cout<<endl;
    }*/

    d[0] = 0;

    for(int i = 0; i < n; i++){

        int index = -1, value = INT_MAX;
        for(int j = 0; j < n; j++){
            if(value > d[j] && !intree[j]){
                value = d[j];
                index = j;
            }
        }
        if(index == -1)
            break;

        intree[index] = true;
        total+=d[index];

        for(int j = 0; j < n; j++){
            if(!intree[j] && graph[index][j]!=-1 && graph[index][j] < d[j]){
                d[j] = graph[index][j];
            }
        }
    }

    cout<<total<<endl;

}

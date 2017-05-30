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

int n; // total nodes
int graph[101][101]; //graph
int d[101]; //distance
bool intree[101]; //check if value is in tree.
int parent[101]; //parents

int main(){

    Rd("prim.in");
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &graph[i][j]);
        }
    }

    for(int i = 0; i < n; i++){
        intree[i] = false; d[i] = INT_MAX; parent[i] = -1;
    }

    d[0] = 0;
    int total = 0;

    for(int i = 1; i <= n; i++){
        int min_index  = -1, min_value = INT_MAX;
        for(int j = 0; j < n; j++){
            if(intree[j] == false && d[j] < min_value){
                min_value = d[j];
                min_index = j;
            }
        }
        if(min_index == -1)
            break;

        intree[min_index] = true;
        total += min_value;
        //cou

        for(int j = 0; j < n; j++){
            if(graph[min_index][j]!=0 && intree[j] == false){
                if(graph[min_index][j] < d[j]){
                    d[j] = graph[min_index][j];
                    parent[j] = min_index;
                }
            }
        }
    }
    cout<<total<<endl;
}

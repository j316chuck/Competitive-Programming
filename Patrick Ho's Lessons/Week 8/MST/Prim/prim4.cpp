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

void updateDistances(int target){

    for(int i = 0; i < n; i++){
        if(graph[i][target]!=0 && graph[i][target] < d[i]){
            d[i] = graph[i][target];
            parent[i] = target;
        }
    }
    /*for(int i = 0; i < n; i++){
        cout<<d[i]<<' ';
    }cout<<endl;*/

}
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

    intree[0] = true;
    //d[0] = 0;
    updateDistances(0);

    int total = 0;

    for(int i = 0; i < n-1; i++){
        int min_index  = -1;
        for(int j = 0; j < n; j++){
            if(intree[j] == false){
                if(min_index == -1 || d[min_index] > d[j]){
                    min_index = j;
                }
            }
        }
        printf("Adding edge %d-%d\n", parent[min_index]+1, min_index+1);
        intree[min_index] = true;
        total+=d[min_index];

        updateDistances(min_index);
    }

    printf("%d\n", total);
    /*for(int i = 0; i < n; i++){
        printf("Parent %d: %d\n",i, parent[i]);
    }*/
}

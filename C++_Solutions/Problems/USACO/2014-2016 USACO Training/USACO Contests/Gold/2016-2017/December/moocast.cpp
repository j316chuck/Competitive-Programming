/*ID: j316chuck
PROG: moocast
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

int n; // total nodes
int graph[1001][1001]; //graph
int d[1001]; //distance
bool intree[1001]; //check if value is in tree.
int parent[1001]; //parents

int main(){

    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);
    int n;
    cin>>n;
    vector< pair<int, int> > G;
    int x, y;
    for(int i = 0; i < n; i++){
        cin>>x>>y;
        G.push_back(make_pair(x, y));
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            graph[i][j] = (G[i].first-G[j].first)*(G[i].first-G[j].first)+ (G[i].second-G[j].second)*(G[i].second-G[j].second);
        }
    }

    for(int i = 0; i < n; i++){
        d[i] = INT_MAX;
        intree[i] = false;
    }


    int total = -1;
    for(int i = 0; i < n; i++){
        if(graph[0][i]!=0)
            d[0] = min(d[0], graph[0][i]);
    }

    for(int i = 1; i <= n; i++){
        int min_index = -1, min_value = INT_MAX;
        for(int j = 0; j < n; j++){
            if(!intree[j] && d[j] < min_value){
                min_value = d[j];
                min_index = j;
            }
        }
        intree[min_index] = true;
        total = max(total, min_value);
        //cout<<min_value<<endl;
        for(int j = 0; j < n; j++){
            if(graph[min_index][j]!=0 && intree[j] == false){
                if(graph[min_index][j] < d[j]){
                    d[j] = graph[min_index][j];
                }
            }
        }
    }
    cout<<total<<endl;
}

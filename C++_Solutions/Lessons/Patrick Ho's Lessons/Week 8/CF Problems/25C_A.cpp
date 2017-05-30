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
int graph[301][301];
int d[301];
bool visited[301];

int main(){

    freopen("25C.in", "r", stdin);

    cin>>n;
    long long sum = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &graph[i][j]);
            sum+=graph[i][j];
        }
    }
    cin>>m;
    int u, v, w;

    for(int i = 0; i < m; i++){
        cin>>u>>v>>w;
        u--; v--; w;
        if(graph[u][v] > w){
            sum = sum - (2 * (graph[u][v]-w));
            graph[u][v] = w;
            graph[v][u] = graph[u][v];

        }else{
            cout<<sum/2<<endl;
            continue;
        }
        //cout<<graph[u][v]<<endl;
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                int temp = graph[j][k];
                //cout<<j<<' '<<k<<' '<<' '<<graph[j][u]<<' '<<graph[v][k]<<' '<<graph[j][u]+graph[u][v]+graph[v][k]<<' '<<graph[j][k]<<endl;
                graph[j][k] = min(graph[j][k], graph[j][u]+graph[u][v]+graph[v][k]);
                graph[j][k] = min(graph[j][k], graph[j][v]+graph[v][u]+graph[u][k]);
                //cout<<graph[j][k]<<' ';
                sum = sum - (temp - graph[j][k]);
                //cout<<sum<<endl;
            }//cout<<endl;
        }
        cout<<sum/2<<' ';
    }
    cout<<endl;
    return 0;
}


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

    //freopen("25C.in", "r", stdin);

    cin>>n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &graph[i][j]);
        }
    }
    cin>>m;
    int u, v, w;
    for(int i = 0; i < m; i++){
        cin>>u>>v>>w;
        u--; v--; w;
        int sum = 0;
        if(w < graph[u][v]){
            //cout<<w<<u<<v<<endl;
            graph[u][v] = w;
            graph[v][u] = w;
            for(int i = 0; i < 301; i++){
                visited[i] = false;
                d[i] = INT_MAX;
            }

            d[u] = 0;

            for(int j = 0; j < n; j++){
                int index  = -1, value = INT_MAX;
                for(int k = 0; k < n; k++){
                    if(visited[k] == false && d[k] < value){
                        value = d[k];
                        index = k;
                    }
                }
                if(index == -1)
                    break;
                //cout<<index<<endl;
                visited[index] = true;
                for(int k = 0; k < n; k++){
                    if(visited[k] == false && graph[index][k]!=0 && d[k] > graph[index][k]+d[index]){
                        d[k] = graph[index][k];
                    }
                }
            }

            for(int j = 0; j < n; j++){
                graph[u][j] = d[j];
                graph[j][u] = d[j];
                //cout<<d[j]<<endl;
            }
            /*for(int j = 0; j < n; j++){
                for(int k = 0; k < n; k++){
                    graph[j][k] = min(graph[j][k], graph[u][j]+graph[u][k]);
                }
            }*/
        }
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                graph[j][k] = min(graph[j][k], graph[u][j]+graph[u][k]);
                sum+=graph[j][k];
            }
        }
        cout<<sum/2<<' ';
    }
    cout<<endl;
    return 0;
}

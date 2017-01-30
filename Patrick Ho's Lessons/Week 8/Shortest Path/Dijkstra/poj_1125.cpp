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

int n;

class pp{
public:
    int u, v, w;
};

int dijkstra(int mygraph[][101], int start){

    vector<int> dist;
    vector<int> visited;

    for(int i = 0; i <= n; i++){
        dist.push_back(INT_MAX);
        visited.push_back(0);
    }

    dist[start] = 0;

    for(int i = 0; i < n-1; i++){
        int min_value = INT_MAX, pos = -1;
        for(int k = 1; k <= n; k++){
            if(visited[k] == false && dist[k] < min_value){
                min_value = dist[k];
                pos = k;
            }
        }
        if(pos == -1)
            break;

        visited[pos] = true;

        for(int k = 1; k <= n; k++){
            if(visited[k] == false && mygraph[pos][k]!=0
            && mygraph[pos][k]+dist[pos] < dist[k]){

                dist[k] = dist[pos]+mygraph[pos][k];
                //cout<<"distance: "<<mygraph[pos][k]<<"position: "<<k<<"new distance: "<<dist[k]<<endl;

            }
        }
    }

    int max_dist = 0;
    /*for(int i = 1; i <=n; i++){
        cout<<dist[i]<<' ';
    }cout<<endl;*/

    for(int i = 1; i <= n; i++){
        if(visited[i] == false ){
            return dist[i];
        }else{
            max_dist = max(max_dist, dist[i]);
        }
    }
    return max_dist;
}

int main(){

    Rd("poj_1125.in");

    while(cin>>n && n!=0){
        int graph[101][101];

        memset(graph, 0, sizeof(graph[0][0]) * 101 * 101);
        int m, v, w;
        /*for(int i = 1; i < 101; i++){
            for(int j = 1; j < 101; j++){
                graph[i][j] = 0;
            }
        }*/
        for(int i = 1; i <= n; i++){
            cin>>m;
            //cout<<m<<endl;
            for(int k = 0; k < m; k++){
                cin>>v>>w;
                graph[i][v] = w;
            }
        }
        int min_distance = INT_MAX, start  = 0;
        for(int i = 1; i <= n; i++){
            int dist = dijkstra(graph, i);
            //cout<<dist<<' '<<i<<endl;
            if(dist < min_distance){
                min_distance = dist;
                start = i;
            }
        }
        if(start == 0){
            cout<<"disjoint"<<endl;
        }else{
            printf("%d %d\n", start, min_distance);
        }
    }
}

/*vector< vector<pp> > mygraph;
        for(int i = 1; i <= n; i++){
            int m;
            pp ei;
            vector<pp> temp;
            cin>>m;
            for(int k = 0; k < m; k++){
                cin>>ei.v>>ei.w;
                ei.u = i;
                temp.push_back(ei);
            }
            mygraph.push_back(temp);
        }
        for(int i = 0; i < mygraph.size(); i++){
            cout<<mygraph[i][0].u<<" THIS IS NUMBER: "<<endl;
            for(int j = 0; j < mygraph[i].size(); j++){
                cout<<mygraph[i][j].v<<' ';
            }cout<<endl;
        }*/
 /*for(int i = 1; i <=n; i++){
            for(int j = 1; j <= n; j++){
                cout<<graph[i][j]<<' ';
            }cout<<endl;
        }*/

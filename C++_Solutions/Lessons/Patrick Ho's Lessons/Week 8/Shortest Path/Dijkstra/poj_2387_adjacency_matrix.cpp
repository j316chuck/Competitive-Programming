#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdlib>

using namespace std;

class pp{
public:
    int v, w;
};

int G[1005][1005];

int main(){

    //freopen("poj_2387.in", "r", stdin);
    int n, t, u, v, w;
    cin>>t>>n;
    //cout<<t<<n<<endl;
    //memset(G, -1, sizeof(G));
    for(int i = 0; i < t; i++){
        cin>>u>>v>>w;
        if(G[u][v]!=0){
            G[u][v] = min(G[u][v], w);
            G[v][u] = G[u][v];
        }else{
            G[u][v] = G[v][u] = w;
        }
    }
    //cout<<G[0][15];
    /*for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++ ){
            cout<<G[i][j]<<' ';
        }cout<<endl;
    }*/

    vector<int> dist;
    vector<bool> visit;

    for(int i = 0; i <= n; i++){
        dist.push_back(INT_MAX);
        visit.push_back(false);
    }

    dist[1] = 0;

    for(int i = 0; i < n-1; i++){

        int pos = -1, min_dist = INT_MAX;

        for(int k = 1; k <= n; k++){
            if(min_dist > dist[k] && visit[k] == false){
                min_dist = dist[k];
                pos = k;
            }
        }
        //cout<<pos<<endl;
        visit[pos] = true;
        for(int k = 0; k <= n; k++){
            if(visit[k] == false && G[pos][k]!=0 && G[pos][k] + dist[pos] < dist[k]){
                dist[k] = dist[pos]+G[pos][k];
            }
        }

    }
    cout<<dist[n]<<endl;
}


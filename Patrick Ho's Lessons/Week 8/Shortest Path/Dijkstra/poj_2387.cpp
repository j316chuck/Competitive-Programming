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

int n, t, u;


int main(){

    freopen("poj_2387.in", "r", stdin);

    cin>>t>>n;
    //cout<<t<<n<<endl;
    vector<pp> G[n+1];
    for(int i = 0; i < t; i++){
        pp ei;
        cin>>u>>ei.v>>ei.w;
        G[u].push_back(ei);
    }
    /*for(int i = 0; i <= n; i++){
        for(int j = 0; j < G[i].size(); j++ ){
            cout<<i<<' '<<G[i][j].v<<' '<<G[i][j].w<<"   ";
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
            if(visit[k] == false && k!=pos){
                for(int j = 0; j < G[pos].size(); j++){
                    if(G[pos][j].v == k && G[pos][j].w + dist[pos] < dist[k]){
                        dist[k] = G[pos][j].w + dist[pos];
                    }
                }
            }
        }
        /*for(int i = 1; i <= n; i++){
            cout<<dist[i]<<' ';
        }cout<<endl;*/
    }
    cout<<dist[n]<<endl;
}

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdlib>

using namespace std;

class pp{
public:
    int x, y;
};

int main(){

    //freopen("poj_2253.in", "r", stdin);
    int n;
    int counter = 0;

    while(cin>>n && n!=0){

        vector<pp> G;
        //vector< vector<double> > adj;

        for(int i = 0; i < n; i++){
            pp si;
            cin>>si.x>>si.y;
            G.push_back(si);
        }

        /*for(int i = 0; i < G.size(); i++){
            vector<double> temp;
            for(int j = 0; j < G.size(); j++){
                double x = G[i].x - G[j].x;
                double y = G[i].y - G[j].y;
                double d = sqrt(x*x+y*y);
                temp.push_back(d);
            }
            adj.push_back(temp);
        }*/

       vector<double> dist;
       vector<int> visited;

       for(int i = 0; i < n; i++){
            dist.push_back(INT_MAX);
            visited.push_back(false);
       }

       dist[0] = 0;

       for(int count = 0; count < n-1; count++){
            int pos = -1, min_value = INT_MAX;

            for(int i = 0; i < n; i++){
                if(min_value > dist[i] && visited[i] == false){
                    pos = i;
                    min_value = dist[i];
                }
            }
            visited[pos] = true;

            if(pos == 1)
                break;

            for(int i = 0; i < n; i++){
                double adj = (G[i].x-G[pos].x)*(G[i].x-G[pos].x);
                adj += (G[i].y-G[pos].y)*(G[i].y-G[pos].y);
                adj = sqrt(adj);
                if(visited[i] == false && adj!=0 && max(dist[pos], adj) < dist[i] ){
                    dist[i] = max(dist[pos], adj);
                }
            }
       }

       printf("Scenario #%d\n", ++counter);
       printf("Frog Distance = %.3f\n \n", dist[1]);

    }
    //cout<<endl;
    return 0;
}

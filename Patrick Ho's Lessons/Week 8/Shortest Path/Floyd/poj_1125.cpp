#include <iostream>
#include <cstdio>
using namespace std;

int n;

void floydwarshall(int dist[][101], int &pos, int &result){

    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
            }
        }
    }

    for(int i = 1; i <= n; i++){
        int minimum_cost = 0;
        for(int j = 1; j <= n; j++){
            minimum_cost = max(dist[i][j], minimum_cost);
        }
        if(minimum_cost < result){
            result = minimum_cost, pos = i;
        }
    }

    if(result == INT_MAX/10 && pos == 0){
        cout<<"disjoint"<<endl;
    }else{
        cout<<pos<<' '<<result<<endl;
    }

    return;
}

int main(){

    freopen("poj_1125.in", "r", stdin);

    while(cin>>n && n!=0){

        int dist[101][101];

        for(int i = 0; i < 101; i++){
            for(int j = 0; j < 101; j++){
                dist[i][j] = INT_MAX/10;
            }
        }
        for(int i = 0; i < 101; i++)
            dist[i][i] = 0;

        for(int i = 1; i <= n; i++){
            int k; cin>>k;
            for(int j = 0; j < k; j++){
                int v, w;
                cin>>v>>w;
                dist[i][v] = w;
            }
        }

        int pos = 0, res = INT_MAX/10;
        floydwarshall(dist, pos, res);

    }

    return 0;
}

//check if bool
 /*for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout<<dist[i][j]<<' ';
        }cout<<endl;
    }*/
    //bool cycle = true;
    /*for(int i = 1; i <= n; i++){
        int counter = 0;
        for(int j = 1; j <= n; j++){
            if(i == j){
                continue;
            }else if(dist[i][j] == INT_MAX/10){
                counter++;
            }
        }
        if(counter != n-1){
            break;
        }if(i == n){
            cycle = false;
        }
    }

    if(!cycle)
        return;
    */

    /*for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i == j){
                continue;
            }else{

            }
        }
    }*/
//floyd warshall

 /*for(int k = 1; k <= n; k++){
            for(int i = 1; i <= n; i++){
                for(int j = 1; j <= n; j++){
                    dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
                }
            }
        }
         for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
               cout<<dist[i][j]<<' ';
            }cout<<endl;
        }*/

/*if(i == j){
                continue;
            }else if(dist[i][j] == INT_MAX/10){
                minimum_cost = INT_MAX;
                break;
            }else{
                minimum_cost == max(dist[i][j], minimum_cost);
            }*/

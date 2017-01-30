#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
using namespace std;

int n, m, k, x, y;
vector<short> G[3005];
short dist[3005][3005];
map<long long, bool> mp;
short parent[3005][3005];
short order[3005];


int main(){

    ios::sync_with_stdio(false);
    Rd("CF_59E.in");
    cin>>n>>m>>k;


    for(int i = 0; i < m; i++){
        cin>>x>>y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    /*for(int i = 1; i <= n; i++){
        for(int j = 0; j < G[i].size(); j++){
            cout<<G[i][j]<<' ';
        }cout<<endl;
    }*/
    int a, b, c;
    for(int i = 0; i < k; i++){
        cin>>a>>b>>c;
        mp[(long long)a*100000000 + b * 10000 + c] = true;
        //F.insert(make_pair(a, make_pair(b, c)));
    }

    Q.push(make_pair(1,1));
    /*for(set< pair<int, pii> >::iterator it = F.begin(); it!=F.end(); it++){
        cout<<(*it).second.first<<endl;
    }*/
    //pair<int, pii> curr;
    while(!Q.empty()){
        int u = Q.front().first;
        int v = Q.front().second;
        //cout<<u<<v<<endl;
        //curr.first = u;
        //curr.second.first = v;
        Q.pop();

        for(int i = 0; i < G[v].size(); i++){
            int w = G[v][i];
            //curr.second.second = w;
            //long long value = w + v * 10000 + u * 100000000;
            //cout<<mp[value]<<' '<<parent[v][w]<<endl;
            if(!mp[w + v * 10000 + u * 100000000] && parent[v][w] == 0){
                dist[v][w] = dist[u][v] + 1;
                parent[v][w] = u;
                Q.push(make_pair(v, w));
            }
        }
    }
    int pos = -1, value = INT_MAX;

    for(int i = 1; i <= n; i++){
        if(dist[i][n]!=0 && dist[i][n] < value){
            value = dist[i][n];
            pos = i;
        }
    }
    if(pos == -1)
        cout<<-1<<endl;
    else{
        cout<<value<<endl;
        int b = n;
        for(int i = 0; i <= value; i++){
            order[value-i] = b;
            int temp = pos;
            pos = parent[pos][b];
            b = temp;
        }
        for(int i = 0; i <= value; i++){
            cout<<order[i]<<' ';
        }
        /*int u = pos, v = n;
        vector<int> result;
        result.push_back(n);
        int temp;
        while(v!=1){
            result.push_back(u);
            temp = parent[u][v];
            v = u;
            u = temp;
        }
        reverse(result.begin(), result.end());
        for(int i = 0; i < result.size(); i++){
            cout<<result[i]<<' ';
        }cout<<endl;*/
    }

    return 0;
}

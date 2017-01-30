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

class ff{
public:
    int a, b, c;
    bool operator <(const ff&d) const
    {
        if(d.a>a) return true;
        if(d.a<a) return false;
        if(d.b>d.b) return true;
        if(d.b<d.b) return false;
        if(d.c>=c) return true;
        return false;
    }
};

int n, m ,k;
bool graph[3001][3001];
vector<ff> forbid;

int main(){

    freopen("59E.in", "r", stdin);
    cin>>n>>m>>k;
    for(int i = 0; i < m; i++){
        int x, y;
        cin>>x>>y;
        graph[x][y] = true;
        graph[y][x] = true;
    }
    for(int j = 0; j < k; j++){
        ff d;
        cin>>d.a>>d.b>>d.c;
        forbid.push_back(d);
    }
    int distance[3001];
    int parent[3001];
    bool visited[3001];

    for(int i = 0; i <= n; i++){
        distance[i] = INT_MAX;
        visited[i] = false;
    }

    distance[1] = 0;

    for(int i = 0; i < m; i++){
        int min_value = INT_MAX, pos = -1;
        for(int k = 1; k <= n; k++){
            if(visited[k] == false && distance[k] < min_value){
                min_value = distance[k];
                pos = k;
            }
        }
        if(pos == -1){
            break;
        }

        visited[pos] = true;
        for(int k = 1; k <= n; k++){
            if(graph[pos][k] && visited[k] == false &&
               distance[k] > distance[pos] + 1){
                    distance[k] = distance[pos] + 1;
                    parent[k] = pos;
               }
        }
    }
    if(distance[n]==INT_MAX){
        cout<<-1<<endl;
    }else{
        cout<<distance[n]<<endl;
        int k = n;
        vector<int> parents;
        parents.push_back(n);
        while(parent[k]!=0){
            k = parent[k];
            parents.push_back(k);
        }
        reverse(parents.begin(), parents.end());
        for(int i = 0; i < parents.size(); i++){
            cout<<parents[i]<<' ';
        }cout<<endl;
    }
}

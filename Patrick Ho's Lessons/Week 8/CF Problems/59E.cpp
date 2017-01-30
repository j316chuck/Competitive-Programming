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

vector<ff> forbid;
bool graph[3001][3001];
int d[3001];
bool visited[3001];
int parent[3001];
int n, m, k, u, v;

bool contains(int a, int b, int c, int l, int r){
    int m = 0;
    while(l <= r && m < k){
        m = (l+r)/2;
        if(forbid[m].a < a){
            l = m+1;
        }else if(forbid[m].a > a){
            r = m-1;
        }else if(forbid[m].b < b){
            l = m+1;
        }else if (forbid[m].b > b){
            r = m-1;
        }else if(forbid[m].c < c){
            l = m+1;
        }else if(forbid[m].c > c){
            r = m-1;
        }else{
            return true;
        }
    }
    return false;
}
int main(){

    freopen("CF_59.in", "r", stdin);

    cin>>n>>m>>k;

    memset(graph, 0, sizeof(graph[0][0])*3000*3000);

    for(int i = 0; i <= 3000; i++){
        d[i] = 99999;
        visited[i] = false;
        parent[i] = -1;
    }
    for(int i = 0; i < m; i++){
        cin>>u>>v;
        graph[u][v] = true;
        graph[v][u] = true;
    }

    ff x;
    for(int i = 0; i < k; i++){
        cin>>x.a>>x.b>>x.c;
        forbid.push_back(x);
    }
    sort(forbid.begin(), forbid.end());

    d[1] = 0;
    int counter = 0;

    ff curr;
    curr.a = -1;
    curr.b = -1;
    curr.c = -1;
    //cout<<contains(1, 3, 3, 0, k)<<endl;
    for(int i = 0; i < n; i++){

        int value = 99999, index = -1;
        for(int j = 1; j <= n; j++){
            if(!contains(curr.b, curr.a, j, 0, k) && !visited[j] && d[j] < value){
                value = d[j];
                index = j;
            }
        }

        if(index == -1)
            break;

        curr.c = curr.b;
        curr.b = curr.a;
        curr.a = index;

        visited[index] = true;

        for(int j = 1; j <= n; j++){
            if(!visited[j] && graph[index][j] && d[index]+1 <= d[j]){
                if(d[index]+1 < d[j] && j == n){
                    counter = 1;
                }else if(d[index]+1 == d[j] && j == n){
                    counter++;
                }
                d[j] = d[index]+1;
                parent[j] = index;
            }
        }
    }

    if(counter!=0)
        cout<<counter<<endl;

    int a = n;
    if(parent[n] != -1){
        vector<int> parents;
        while(a!=-1){
            parents.push_back(a);
            a = parent[a];
        }
        reverse(parents.begin(), parents.end());
        for(int i = 0; i < parents.size(); i++)
            cout<<parents[i]<<' ';
        cout<<endl;
    }else{
        cout<<-1<<endl;
    }
}

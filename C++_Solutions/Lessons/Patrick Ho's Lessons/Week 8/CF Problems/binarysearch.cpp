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

bool binarysearch(int a, int b, int c, int lower, int upper){
    int middle = lower+upper;
    middle = middle/2;

    if(forbid[middle].a < a ){
        return binarysearch(a, b, c, middle, upper);
    }else if(forbid[middle].a > a){
        return binarysearch(a, b, c, lower, middle);
    }else if(forbid[middle].b < b){
        return binarysearch(a, b, c, middle, upper);
    }else if(forbid[middle].b > b){
        return binarysearch(a, b, c, lower, middle);
    }else if(forbid[middle].c > c){
        return binarysearch(a, b, c, middle, upper);
    }else if(forbid[middle].c < c){
        return binarysearch(a, b, c, lower, middle);
    }else if(forbid[middle].c == c){
        return true;
    }
    if(lower == middle||middle == upper){
        return false;
    }
}

bool contains(int a, int b, int c, int l, int r){
    int m = (l+r)/2;
    if(m > k){

    }
    if(l == r){

    }
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

    for(int i = 0; i < k; i++){

    }
}

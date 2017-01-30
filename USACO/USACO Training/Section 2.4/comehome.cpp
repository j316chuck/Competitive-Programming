/*
ID: j316chuck
PROG: comehome
LANG: C++
 */

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
#define MAX 1001
using namespace std;

int n;

int djstrka(vector< vector<int> > graph, int src){

    int d[101];
    bool v[101];

    for(int i = 1; i <= 54; i++){
        d[i] = 999999; v[i] = false;
    }

    d[src] = 0;
    for(int i = 0; i < 51; i++){
        int pos = -1, val = 999999;
        for(int j = 1; j <= 52; j++){
            if(val > d[j] && v[j] == false){
                val = d[j];
                pos = j;
            }
        }
        v[pos] = true;
        for(int j = 1; j <= 52; j++){
            if(v[j] == false && graph[pos][j]+d[pos] < d[j]){
                d[j] = graph[pos][j]+d[pos];
            }
        }
    }
    return d[26];
}
int main(){

    freopen("comehome.in", "r", stdin);
    freopen("comehome.out", "w", stdout);

    cin>>n;
    //cout<<n<<endl;
    vector< vector<int> > graph;
    for(int i = 0; i < 55; i++){
        vector<int> temp;
        for(int j = 0; j < 55; j++){
            temp.push_back(99999);
        }graph.push_back(temp);
    }

    for(int i = 0; i < n; i++){
        char s, d; int v;
        cin>>s>>d>>v;
        int x, y;
        if(isupper(s)){
            x = s-'A'+1;
        }else{
            x = s-'a'+27;
        }if(isupper(d)){
            y = d-'A'+1;
        }else{
            y = d-'a'+27;
        }
        //cout<<x<<' '<<y<<endl;
        graph[x][y] = min(graph[x][y], v); //many paths
        graph[y][x] = graph[x][y];
        //cout<<graph[x][y]<<endl; //bidirectional
    }

    for(int i = 0; i < 55; i++){
        graph[i][i] = 0;
    }

    int dist[26];
    for(int i = 0; i < 26; i++){
        dist[i] = 99999;
    }
    int minimum = INT_MAX;
    /*for(int i = 1; i <= 40; i++){
        for(int j = 1; j <= 40; j++){
            cout<<graph[i][j]<<' ';
        }cout<<endl;
    }*/
    int pos;
    for(int i = 1; i < 26; i++){
        dist[i] = djstrka(graph, i);
        //cout<<dist[i]<<endl;
        if(minimum > dist[i]){
            minimum = dist[i];
            pos = i;
        }
    }
    char int_to_upper[]={'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
                     'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
                     'U', 'V', 'W', 'X', 'Y', 'Z'};

    printf("%c %d\n", int_to_upper[pos-1], minimum);
    //1-26 27-52
}

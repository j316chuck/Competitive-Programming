/*
ID: j316chuck
PROG: cowtour
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
vector< pair<int, int> > d;
int NO_PATH = 99999;

double dis(int a, int b) {
    double x = d[a].first-d[b].first;
    double y = d[a].second-d[b].second;
    return sqrt(x*x + y*y);
}

int main(){

    freopen("cowtour.in", "r", stdin);
    freopen("cowtour.out", "w", stdout);

    cin>>n;

    for(int i = 0; i < n; i++) {
        int x, y;
        cin>>x>>y;
        d.push_back(make_pair(x, y));
    }

    vector< vector<double> > graph;

    for(int i = 0; i < n; i++){
        char c; vector<double> temp;
        for(int j = 0; j < n; j++){
            cin>>c;
            if(c == '0' && i==j){
                temp.push_back(0);
            }else if(c == '0'){
                temp.push_back(NO_PATH);
            }else{
                temp.push_back(dis(i, j));
            }
        }graph.push_back(temp);
    }

    double rmax[151];
    double minimum = 0;
    memset(rmax, 0, sizeof(rmax));

    //floyd
    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                graph[i][j] = min(graph[i][j], graph[i][k]+graph[k][j]);
            }
        }
    }

    //calculate distance of all the loops in the current graph;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(graph[i][j]!=NO_PATH){
                rmax[i] = max(rmax[i], graph[i][j]);
            }
        }minimum = max(minimum, rmax[i]);
    }

    double minim = INT_MAX;

    //connect two graphs;
    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            if(graph[i][j] == NO_PATH){
                minim = min(rmax[i]+dis(i, j)+rmax[j], minim);
            }
        }
    }

    if(minimum > minim){
        printf("%.6f\n", minimum);
    }else{
        printf("%.6f\n", minim);
    }
}

/* for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout<<graph[i][j]<<' ';
        }cout<<endl;
    }
    for(int i = 0; i < n; i++)
        cout<<rmax[i]<<endl;
    cout<<minimum<<endl;
*/

/*
ID: j316chuck
PROG: split
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

using namespace std;

vector< pair<int, int> > graph;
vector< pair<int, int> > lef;
vector< pair<int, int> > righ;

int main(){

    Rd("split.in");
    //Wt("split.out");

    int n;
    cin>>n;

    int x, y;
    int maxx = -1, maxy = -1, minx = INT_MAX, miny = INT_MAX;
    for(int i = 0; i < n; i++){
        cin>>x>>y;
        maxx = max(maxx, x);
        maxy = max(maxy, y);
        minx = min(minx, x);
        miny = min(miny, y);
        graph.push_back(make_pair(x, y));
    }
    int first = (maxx-minx) * (maxy-miny);
    //cout<<first<<endl;
    sort(graph.begin(), graph.end());
    maxx = graph[0].first; minx = graph[0].first; maxy = graph[0].second; miny = graph[0].second;
    lef.push_back(make_pair(0, maxx));
    for(int i = 1; i < n-1; i++){
        //cout<<i<<' '<<graph[i].first<<endl;
        maxx = max(maxx, graph[i].first);
        minx = min(minx, graph[i].first);
        maxy = max(maxy, graph[i].second);
        miny = min(miny, graph[i].second);
        int area = (maxy-miny)*(maxx-minx);
        int lastx = graph[i].first;
        lef.push_back(make_pair(area, lastx));
    }
    maxx = graph[n-1].first; minx = graph[n-1].first; maxy = graph[n-1].second; miny = graph[n-1].second;
    righ.push_back(make_pair(0, maxx));
    for(int i = n-2; i >= 1; i--){
        maxx = max(maxx, graph[i].first);
        minx = min(minx, graph[i].first);
        maxy = max(maxy, graph[i].second);
        miny = min(miny, graph[i].second);
        int area = (maxy-miny)*(maxx-minx);
        int lastx = graph[i].first;
        righ.push_back(make_pair(area, lastx));
    }
    int minsize = INT_MAX;
    for(int i = 0; i < righ.size(); i++){
        int l = lef.size()-1-i;
        //cout<<righ[i].first<<' '<<lef[l].first<<' '<<righ[i].second<<' '<<lef[l].second<<endl;
        if(righ[i].second!=lef[l].second){
            minsize = min(righ[i].first+lef[l].first, minsize);
        }
    }
    //cout<<first<<' '<<minsize<<endl;
    cout<<first-minsize<<endl;

}

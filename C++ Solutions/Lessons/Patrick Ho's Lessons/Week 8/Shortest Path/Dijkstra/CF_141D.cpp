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
#define pii pair<int, int>
using namespace std;

class pp{
public:
    int x, d, p, t, n;
    bool operator <(const pp&a) const
    {
        return x-p > a.x-a.p;
    }
};
class re{
public:
    int finish, parent, time, ramp;
};

int n, l;
vector<pp> graph;
vector<re> result; //time, parent;

int main(){

    freopen("CF_141D.in", "r", stdin);

    cin>>n>>l;
    pp b;

    for(int i = 0; i < n; i++){
        cin>>b.x>>b.d>>b.t>>b.p;
        b.n = i+1;
        if(b.x-b.p < 0 || b.d/b.t == 0){
            continue;
        }
        graph.push_back(b);
    }
    sort(graph.begin(), graph.end());

    re a;
    a.finish = graph[0].d+graph[0].x;
    a.parent = -1;
    a.time = graph[0].x+graph[0].t;
    a.ramp = 1;
    result.push_back(a);

    for(int i = 1; i < graph.size(); i++){
        int minimum = pow(10, 9)+1; int pos = -1;
        for(int j = i-1; j >= 0; j++){
            int distance = result[j].finish - (graph[i].x - graph[i].p);
            if(distance < 0){
                distance = -distance;
                if(minimum > result[j].time + distance +  graph[i].p + graph[i].t){
                    minimum = result[j].time + distance +  graph[i].p + graph[i].t;
                    pos = j;
                }
                break;
            }else{
                if(minimum > result[j].time - (graph[i].x - graph[i].p)+ graph[i].p + graph[i].t){
                    minimum = result[j].time - (graph[i].x - graph[i].p)+ graph[i].p + graph[i].t;
                    pos = j;
                }else if(minimum > abs(graph[i].x + graph[i].d - result[j].finish) + result[j].time){
                    minimum = abs(graph[i].x + graph[i].d - result[j].finish) + result[j].time;
                    pos = j;
                }
            }
        }
        if(pos == -1){
            minimum = graph[i].x + graph[i].t;
        }
        a.parent = pos;
        a.time = minimum;
        a.finish = graph[i].d + graph[i].x;
        a.ramp = graph[i].n;
        result.push_back(a);
    }
    int res = l;
    int start = -1;
    for(int i = 0; i < result.size(); i++){
        //cout<<result[i].time<<' '<<result[i].parent<<' '<<result[i].finish<<endl;
        if(result[i].time + (l - result[i].finish) < res){
            res = result[i].time + (l - result[i].finish);
            start = i;
        }
    }
    cout<<res<<endl;
    vector<int> positions;
    int counter = 0;
    while(start!=-1){
        positions.push_back(result[start].ramp);
        start = result[start].parent;
        counter++;
    }
    cout<<counter<<endl;
    for(int i = positions.size()-1; i>=0; i--){
        cout<<positions[i]<<' ';
    }cout<<endl;
    /*for(int i = 0; i < graph.size(); i++){
        cout<<graph[i].x<<graph[i].d<<graph[i].t<<graph[i].p<<endl;
    }*/

}




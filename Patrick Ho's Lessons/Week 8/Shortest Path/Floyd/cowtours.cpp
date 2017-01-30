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

double floyd(int v, int x, int y, vector< vector<double> > graph){
    graph[x][y] = v;
    graph[y][x] = v;
    //cout<<x<<' '<<y<<' '<<v<<endl;
    /*for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
           printf("%.1f ", graph[i][j]);
        }cout<<endl;
    }*/
    //cout<<endl;

    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                //if(graph[i][k]!=0 && graph[k][j]!=0)
                graph[i][j] = min(graph[i][j], graph[i][k]+graph[k][j]);
            }
        }
    }
    double max_distance = -1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            //printf("%.1f ", graph[i][j]);
            max_distance = max(max_distance, graph[i][j]);
        }//cout<<endl;
    }
    //cout<<max_distance<<endl;
    return max_distance;
}

int main(){

    freopen("cowtour.in", "r", stdin);
    freopen("cowtour.out", "w", stdout);

    cin>>n;
    pair<int, int> dist[151];

    for(int i = 0; i < n; i++){
        int x, y; cin>>x>>y;
        dist[i].first = x;
        dist[i].second = y;
    }

    vector< vector<double> > mygraph;
    //vector< vector<double> > same;

    for(int i = 0; i < n; i++){
        vector<double> temp;
        for(int j = 0; j < n; j++){
            char a;
            cin>>a;
            temp.push_back(double (a-'0'));
        }mygraph.push_back(temp); //same.push_back(temp);
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
           if(mygraph[i][j] == 1){
                mygraph[i][j] = (dist[i].first-dist[j].first)*(dist[i].first-dist[j].first);
                mygraph[i][j] += (dist[i].second-dist[j].second)*(dist[i].second-dist[j].second);
                mygraph[i][j] = sqrt(mygraph[i][j]);
                //same[i][j] = mygraph[i][j];
           }
        }
    }
    vector< vector<int> > mygroup;
    for(int i = 0; i < n; i++){
        int c = 0;
        bool found = false;
        for(int k = 0; k < mygroup.size(); k++){
            for(int j = 0; j < mygroup[k].size(); j++){
                if(mygroup[k][j] == i){
                    c = k;
                    found = true;
                }
            }
        }
        if(found){
            for(int k = 0; k < n; k++){
                if(mygraph[i][k]!=0){
                    if(find(mygroup[c].begin(), mygroup[c].end(), k) == mygroup[c].end()){
                        mygroup[c].push_back(k);
                    }
                }
            }
        }else{
            vector<int> group;
            group.push_back(i);
            for(int k = 0; k < n; k++){
                if(mygraph[i][k]!=0){
                    group.push_back(k);
                }
            }
            mygroup.push_back(group);
        }

    }

    sort(mygroup.begin(), mygroup.end());
    double minimum = INT_MAX;

    for(int i = 0; i < mygraph.size(); i++){
        for(int j = 0; j < mygraph[i].size(); j++){
            if(mygraph[i][j]==0 && i!=j){
                mygraph[i][j] = INT_MAX;
            }
        }
    }
    for(int i = 0; i < mygroup.size()-1; i++){
        for(int j = i+1; j < mygroup.size(); j++){
            vector< pair<int, int> > m;
            double v = INT_MAX;
            for(int k = 0; k < mygroup[i].size(); k++){
                for(int l = 0; l < mygroup[j].size(); l++){
                    int a = mygroup[i][k];
                    int b = mygroup[j][l];
                    double dis = (dist[a].first-dist[b].first)*(dist[a].first-dist[b].first);
                    dis +=((dist[a].second-dist[b].second)*(dist[a].second-dist[b].second));
                    dis = sqrt(dis);
                    if(v > dis){
                        m.clear();
                        v = dis;
                        pair<int, int> x;
                        x.first = a;
                        x.second = b;
                        m.push_back(x);
                    }else if(v == dis){
                        pair<int, int> x;
                        x.first = a;
                        x.second = b;
                        m.push_back(x);
                    }
                }
            }
            //cout<<minx<<' '<<miny<<' '<<v<<endl;
            for(int k = 0; k < m.size(); k++){
                double a = floyd(v, m[k].first, m[k].second, mygraph);
                if(minimum > a){
                    //printf("%.6f\n", a);
                    minimum = a;
                }
            }
        }
    }
     printf("%.6f\n", minimum);
     return 0;
     /*for(int k= 0; k < mygroup.size(); k++){
        for(int j = 0; j < mygroup[k].size(); j++){
            cout<<mygroup[k][j]<<' ';
        }cout<<endl;//cout<<endl; cout<<endl;
    }*/
   /*for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout<<mygraph[i][j]<<' ';
        }cout<<endl;
    }*/
}


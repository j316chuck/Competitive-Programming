/*
ID: j316chuck
PROG: closing
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

int n, m;
short arr[200001];
set<int> not_connected;
set<int> closed;

int main(){

    freopen("closing.in", "r", stdin);
    freopen("closing.out", "w", stdout);

    cin>>n>>m;
    int x, y;
    vector<int> edges[n+1]; //pair, binary search or set search

    for(int i = 0; i < m; i++){
        cin>>x>>y;
        arr[x]++;
        arr[y]++;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }

    for(int i = 1; i <= n; i++){
        if(arr[x] == 0){
            not_connected.insert(i);
        }
    }
    if(not_connected.size()==0){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
    int c;
    for(int i = 1; i < n; i++){
        cin>>c;
        if(not_connected.find(c)!=not_connected.end()){
            not_connected.erase(not_connected.find(c));
        }
        closed.insert(c);

        for(int j = 0; j < edges[c].size(); j++){
            if(closed.find(edges[c][j])!=closed.end()){
                continue;
            }
            arr[edges[c][j]]--;
            if(arr[edges[c][j]] <= 0){
                not_connected.insert(edges[c][j]);
            }
        }
        /*for(set<int>::iterator it = not_connected.begin(); it!= not_connected.end(); it++){
            cout<<*it<<' ';
        }*/

        if(not_connected.size()==0 || (not_connected.size() == 1 && closed.size()== n-1)){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    cin>>c;
    return 0;
}

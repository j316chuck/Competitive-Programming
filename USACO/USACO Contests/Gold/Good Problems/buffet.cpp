/*
ID: j316chuck
PROG: buffet April 2015
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
#include <cstdlib>

const double Pi=acos(-1.0);
typedef long long LL;

#define Set(a, s) memset(a, s, sizeof (a))
#define Rd(r) freopen(r, "r", stdin)
#define Wt(w) freopen(w, "w", stdout)
#define pii pair<int, int>
using namespace std;

vector<int> G[1005];
int D[1005];
int DP[1005];

int main(){

    Rd("buffet.in");
    Wt("buffet.out");

    int N, E;
    cin>>N>>E;
    vector<int> Q(N+1);
    for(int i = 0; i < N; i++){
        int d;
        cin>>Q[i]>>d;
        for(int j = 0; j < d; j++){
            int a;
            cin>>a;
            G[i].push_back(a-1);
        }
    }

    vector<int> order;
    for(int i = 0; i < N; i++)
        order.push_back(i);
    sort(order.begin(), order.end(), [&](int x, int y){
            return Q[x] < Q[y];
        });

    int result = -1;
    for(int i = N-1; i >= 0; i--){
        int st = order[i];
        memset(D, -1, sizeof(D));
        D[st] = 0;
        queue<int> pq;
        pq.push(st);
        while(!pq.empty()){
            int top = pq.front();
            pq.pop();
            for(int j: G[top]){
                if(D[j] == -1){
                    D[j] = D[top]+1;
                    pq.push(j);
                }
            }
        }
        /*for(int j = 0; j < N; j++){
            cout<<D[j]<<' ';
        }cout<<endl;*/
        int res = Q[st];
        for(int j = 0; j < N; j++){
            if(D[j]!=-1 && DP[j]!=0){
                res = max(res, Q[st] + DP[j] - (E*D[j]));
                //cout<<DP[j]<<' '<<D[j]<<' '<<j<<endl;
            }
        }
        DP[st] = res;
        //cout<<DP[i]<<' '<<endl;
        result = max(result, DP[st]);
    }

    cout<<result<<endl;
    return 0;
}

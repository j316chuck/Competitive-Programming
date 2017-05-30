#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

#define MAXN 1010

int Q[MAXN];
int DP[MAXN];
int D[MAXN];
vector<int> E[MAXN];

bool cmp(int a, int b){
    return Q[a] < Q[b];
}
int main(){

    freopen("buffet.in", "r", stdin);
    //freopen("buffet.out", "w", stdout);

    int N, ECST;
    cin>>N>>ECST;
    for(int i = 0; i < N; i++){
        int D;
        cin>>Q[i]>>D;
        for(int j = 0; j < D; j++){
            int v;
            cin>>v;
            E[i].push_back(v-1);
        }
    }
    cout<<N<<endl;
    /*vector<int> PI;
    for(int i = 0; i < N; i++){
        PI.push_back(i);
    }
    sort(PI.begin(), PI.end(), cmp);

    for(int i = 0; i < PI.size(); i++){
        cout<<PI[i]<<endl;
    }*/
}

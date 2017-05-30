/*
ID: j316chuck
PROG: lightsout January 2016
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

int main(){

    Rd("lightsout.in");
    Wt("lightsout.out");

    int N;
    cin>>N;
    vector<pii> G(N+1);
    for(int i = 0; i < N; i++){
        cin>>G[i].first>>G[i].second;
    }
    G[N].first = G[0].first; G[N].second = G[0].first;

    //-1 = 270  -2 = 90
    //0 = origin
    vector<int> A;
    A.push_back(0);
    for(int i = 1; i < N; i++){
        int dis = abs(G[i].first-G[i-1].first) + abs(G[i].second-G[i-1].second);
        A.push_back(dis);
        int pos = (G[i].first-G[i-1].first)*(G[i+1].second-G[i].second)
                +(G[i].second-G[i-1].second)*(G[i+1].first-G[i].first);
        A.push_back(pos > 0 ? -1:-2);
    }
    A.push_back(abs(G[0].first-G[N-1].first) + abs(G[0].second-G[N-1].second));
    A.push_back(0);

    vector<int> D(N+1);
    D[0] = 0;
    for(int i = 1; i < N; i++){
        D[i] = D[i-1] + A[2*i-1];
    }
    int cnt = 0;
    for(int i = N-1; i >= 1; i--){
        cnt+=A[2*i+1];
        D[i] = min(D[i], cnt);
    }
    D[N] = 0;
    multiset< vector<int> > st;
    for(int i = 1; i < N; i++){
        vector<int> v;
        v.push_back(A[2*i]);
        st.insert(v);
        for(int j = 2*i; j < 2*N; j+=2){
            v.push_back(A[j+1]);
            v.push_back(A[j+2]);
            st.insert(v);
        }
    }
    int res = 0;
    for(int i = 1; i < N; i++){
        vector<int> v;
        v.push_back(A[i*2]);
        int total = 0;
        int j = i;
        while(j < N && st.count(v) != 1){
            total+=A[j*2+1];
            v.push_back(A[j*2+1]);
            v.push_back(A[j*2+2]);
            j++;
        }
        total+=D[j];
        res = max(res, total-D[i]);
    }
    cout<<res<<endl;
}

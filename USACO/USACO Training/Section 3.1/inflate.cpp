/*
ID: j316chuck
PROG: inflate
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

int M, N;
vector<pii> W;

int main(){

    Rd("inflate.in");
    Wt("inflate.out");

    cin>>M>>N;
    for(int i = 0; i < N; i++){
        int c, w;
        cin>>c>>w;
        W.push_back(make_pair(c, w));
    }

    int maximum = -1;
    vector<int> A(M+1, -1);
    A[0] = 0;
    for(int i = 0; i < N; i++){
        for(int k = W[i].second; k <= M; k++){
            if(A[k-W[i].second] != -1 && A[k-W[i].second] + W[i].first > A[k]){
                A[k] = A[k-W[i].second] + W[i].first;
                maximum = max(maximum, A[k]);
            }
        }
    }

    cout<<maximum<<endl;

    return 0;
}


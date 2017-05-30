/*
ID: j316chuck
PROG: bphoto
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

using namespace std;

int score(char B, char F){
    if(B == 'H' && F == 'S'){
        return 1;
    }else if(B == 'S' && F == 'P'){
        return 1;
    }else if(B == 'P' && F == 'H'){
        return 1;
    }
    return 0;
}
int H[100001][21];
int P[100001][21];
int S[100001][21];

int main(){

    Rd("hps.in");
    Wt("hps.out");

    int N, K;
    cin>>N>>K;
    vector<char> A(N+1);
    for(int i = 1; i <= N; i++){
        cin>>A[i];
    }
    //cout<<A[1]<<endl;
    for(int i = 1; i <= N; i++){
        H[i][0] = H[i-1][0] + score('H' , A[i]);
        S[i][0] = S[i-1][0] + score('S' , A[i]);
        P[i][0] = P[i-1][0] + score('P' , A[i]);
    }
    int result = -1;
    int h, s, p;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= K; j++){
            h = score('H', A[i]);
            H[i][j] = h + max(H[i-1][j], max(P[i-1][j-1], S[i-1][j-1]));
            p = score('P', A[i]);
            P[i][j] = p + max(P[i-1][j], max(H[i-1][j-1], S[i-1][j-1]));
            s = score('S', A[i]);
            S[i][j] = s + max(S[i-1][j], max(H[i-1][j-1], P[i-1][j-1]));
        }
    }
    for(int i = 0; i <= K; i++){
        result = max(result, H[N][i]);
        result = max(result, P[N][i]);
        result = max(result, S[N][i]);
    }
    cout<<result<<endl;
    //cout<<P[4][0]<<endl;
}


/*
ID: j316chuck
PROG: mooomoo
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

int DP[21][100010];

int main(){

    freopen("mooomoo.in", "r", stdin);
    freopen("mooomoo.out", "w", stdout);

    int N, b;
    cin>>N>>b;

    vector<int> B(b+1);
    for(int i = 1; i <= b; i++){
        cin>>B[i];
    }
    vector<int> A(N+1);
    for(int i = 0; i < N; i++){
        cin>>A[i];
    }

    int NO_PATH = 10000000;
    for(int i = 0; i <= b; i++){
        for(int j = 0; j <= 100000; j++){
            DP[i][j] = NO_PATH;
        }
    }
    for(int i = 0; i <= b; i++)
        DP[i][0] = 0;
    for(int i = B[1]; i <= 100000; i+=B[1]){
        DP[1][i] = DP[1][i-B[1]]+1;
    }
    for(int i = 2; i <= b; i++){
        for(int j = 0; j <= 100000; j++){
            if(j-B[i] < 0){
                DP[i][j] = DP[i-1][j];
                continue;
            }
            DP[i][j] = min(DP[i-1][j], DP[i][j-B[i]]+1);
        }
    }
    int prev = 0; int cows = 0;
    for(int i = 0; i < N; i++){
        if(prev > A[i]){
            cout<<-1<<endl;
            return 0;
        }
        if(DP[b][A[i]-prev] == NO_PATH){
            cout<<-1<<endl;
            return 0;
        }
        cows += DP[b][A[i]-prev];
        prev = A[i]-1;
        if(prev < 0){
            prev = 0;
        }
    }
    cout<<cows<<endl;
}

/*
ID: j316chuck
PROG: subset
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

int main(){
    Rd("subset.in");
    Wt("subset.out");

    int N;
    cin>>N;
    long long dp[1600];
    Set(dp, 0);

    dp[0]=1;
    if((N*(N+1)/2)%2!=0)
        cout<<"0"<<endl;
    else{
        //cout<<"Hi"<<endl;
        for(int i=1; i<=N; i++){
            for(int k=1599; k>=0; k--){
                if(dp[k]!=0 && i+k< 1600){
                    dp[i+k]+=dp[k];
                }
            }
        }

        cout<<dp[(N*(N+1))/2/2]/2<<endl;
    }
}

/*ID: j316chuck
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
#include <cstdlib>

const double Pi=acos(-1.0);
typedef long long LL;

#define Set(a, s) memset(a, s, sizeof (a))
#define Rd(r) freopen(r, "r", stdin)
#define Wt(w) freopen(w, "w", stdout)
#define pii pair<int, int>

using namespace std;

long long mem[40][1600];

long long dp(int x, int sum){
    if(sum == 0){
        return 1;
    }else if(x == 0){
        return 0;
    }else if(mem[x][sum]!=-1){
        return mem[x][sum];
    }
    return mem[x][sum] = dp(x-1, sum) + dp(x-1, sum-x);
}

int main(){

    Rd("subset.in");
    Wt("subset.out");

    int n;
    cin>>n;
    if((n*(n+1)/2) % 2 == 1){
        printf("0\n");
    }/*else{
        //int mem[40][1600];
        memset(mem, -1, sizeof(mem));
        cout<<dp(n, (n*(n+1))/4)/2<<endl;
    }*/
    else{
        mem[1][0] = 1; mem[1][1] = 1;
        for(int i = 2; i <= n; i++){

        }
    }
}

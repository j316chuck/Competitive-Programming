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

int main(){

    long long ts = 1;
    long long s = 1;
    int n;
    cin>>n;
    long long mod = pow(10, 9)+7;
    long long ans = 0;
    for(int i = 0; i < 317; i++){
        ts*=27;
        ts = ts%mod;
        s*=7;
        s = s%mod;
    }
    //cout<<s<<' '<<ts<<endl;

    for(int i = 0; i < n; i++){
        long long mul = 1;
        int twenty_seven = i;
        int seven = n-i-1;
        while(seven - 317 > 0 ){
            mul*= s;
            mul = mul % mod;
            seven-=317;
        }while(twenty_seven - 317 > 0){
            mul*=ts;
            mul = mul % mod;
            twenty_seven-=317;
        }

        for(int j = 0; j < seven; j++){
            mul*=7;
            mul = mul % mod;
        }for(int j = 0; j < twenty_seven; j++){
            mul*=27;
            mul = mul % mod;
        }
        ans+=mul;
        ans = ans % mod;
    }
    ans = ans*20;
    ans = ans % mod;
    cout<<ans<<endl;

}

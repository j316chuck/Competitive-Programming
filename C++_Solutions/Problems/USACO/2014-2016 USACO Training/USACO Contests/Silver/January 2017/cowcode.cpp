/*
ID: j316chuck
PROG: cowdance
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

    Rd("cowcode.in");
    //Wt("cowcode.out");

    long long N;
    string s;
    cin>>s>>N;
    int S = s.size();
    while(N > S){
        long long bit = S;
        while(bit < N){
            bit = bit<<1;
        }
        bit = bit>>1;
        if(bit+1 == N){
            N = bit;
        }else{
            N = N-bit-1;
        }
    }
    cout<<s[N-1]<<endl;

}

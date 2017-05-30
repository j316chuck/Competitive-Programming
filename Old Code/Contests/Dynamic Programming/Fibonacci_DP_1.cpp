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

int mem[1000];

int fib(int N){
    if(N==0)
        return 0;
    if(N==1)
        return 1;
    if(mem[N]!=-1)
        return mem[N];

    mem[N]=fib(N-1)+fib(N-2);
    return mem[N];
}
int main(){
    memset(mem, -1, sizeof(mem));
    int N;
    cin>>N;
    //cout<<fib(N);
    mem[0]=0;
    mem[1]=1;
    for(int i=2; i<=N; i++){
        mem[i]=mem[i-1]+mem[i-2];
    }
    cout<<mem[N];

}

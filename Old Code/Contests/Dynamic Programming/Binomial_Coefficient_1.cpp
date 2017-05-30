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

int mem[1000][1000];
int bin(int n, int k){
    if(k==0)
        return 1;
    if(n==0)
        return 0;
    if(mem[n][k]!=-1)
        return mem[n][k];
    return mem[n][k]=bin(n-1, k)+bin(n-1, k-1);
}

int main(){
    memset(mem, -1, sizeof(mem));
    int n,k;
    cin>>n>>k;
    //cout<<bin(n,k);
    for(int i=0; i<n; i++){
        mem[0][i]=0;
    }
    for(int i=0; i<n; i++){
        mem[i][0]=1;
    }
    for(int i=1; i<=n; i++){
        for(int k=1; k<=n; k++){
            mem[i][k]=mem[i-1][k]+mem[i-1][k-1];
        }
    }
    cout<<mem[n][k];
    //int a=-7001%7;
    //cout<<a;
}


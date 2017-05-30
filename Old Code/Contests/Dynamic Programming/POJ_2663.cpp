/*
ID: j316chuck
PROG: concom
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
#define MAX 1001
using namespace std;

long long A[31], B[31];

int main(){
    //freopen("POJ_2663.in", "r", stdin);
    int n;
    A[0] = 1;
    A[2] = 3;
    A[4] = 11;
    B[2] = 1;
    B[4] = 4;
    for(int i = 6; i<= 30; i+=2){
        B[i] = B[i-2] + A[i-2];
        A[i] = A[i-2] + 2*B[i];
    }
    while(cin>>n && n!=-1){
        if(n%2 == 1){
            cout<<0<<endl;
        }else{
            cout<<A[n]<<endl;
        }
    }
    return 0;
}

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

int minimum=10000000;
int b1, b2, moves, goal;
int visited[201][201];

void Recurse(int bucket1, int bucket2, int m){
    if(visited[bucket1][bucket2]==1)
        return;
    visited[bucket1][bucket2]=1;
    if(m==0){
        if(abs(bucket1+bucket2-goal)<minimum){
            minimum=abs(bucket1+bucket2-goal);
        }
        return;
    }
    if(abs(bucket1+bucket2-goal)==0){
        minimum=0;
        return;
    }
    if(abs(bucket1+bucket2-goal)<minimum){
        minimum=abs(bucket1+bucket2-goal);
    }
    m--;
    Recurse(0, bucket2, m);
    Recurse(bucket1, 0, m);
    Recurse(b1, bucket2, m);
    Recurse(0, b2, m);
    if(bucket1+bucket2<=b2){
        Recurse(0, bucket1+bucket2, m);
    }else{
        Recurse(bucket1-b2+bucket2, b2, m);
    }
    if(bucket1+bucket2<=b1){
        Recurse(bucket1+bucket2,0, m);
    }else{
        Recurse(b1, bucket2+bucket1-b1, m);
    }
}

int main(){
    Rd("pails.in");
    Wt("pails.out");
    cin>>b1>>b2>>moves>>goal;
    Recurse(0,0,moves);
    cout<<minimum<<endl;
}

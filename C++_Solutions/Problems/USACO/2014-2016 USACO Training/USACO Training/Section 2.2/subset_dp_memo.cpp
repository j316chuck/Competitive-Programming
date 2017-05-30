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
#define MAX 1001
using namespace std;

long long mem[1700];
int used[50];
int N;

void Recurse(int k){
    if(k == N+1)
        return;
    for(int i = 1600; i >= 1; i--){
        /*if(mem[i] < 0)
            cout<<mem[i]<<' '<<i<<' '<<k<<endl;*/
        if(i-k == 0){
            mem[i] += 1;
        }else if(i-k < 0){
            continue;
        }else if(mem[i-k] == 0){
            continue;
        }else if (mem[i-k]!=0){
            mem[i] += mem[i-k];
        }
    }
    Recurse(k+1);
}

int main(){

    freopen("subset.in", "r", stdin);
    freopen("subset.out", "w", stdout);
    memset(mem, 0, sizeof(mem));
    scanf("%d ", &N);
    int sum = N * (N+1);
    sum = sum / 2;
    if(sum % 2 == 1){
        printf("0");
        printf("\n");
    }else{
        Recurse(1);
        /*for(int i = 0; i <= N*(N+1)/2; i++){
            cout<<mem[i]<<' ';
        }*/
        printf("%d", mem[N*(N+1)/4]/2);
        printf("\n");
    }
}





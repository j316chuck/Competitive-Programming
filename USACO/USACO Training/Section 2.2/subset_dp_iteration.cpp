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
int N;

int main(){
    freopen("subset.in", "r", stdin);
    freopen("subset.out", "w", stdout);
    scanf("%d ", &N);
    if((N*(N+1)/2) %2 == 1){
        printf("0");
        printf("\n");
    }else{
        for(int i = 1; i <= N; i++){
            for(int j = 1600; j >=0; j--){
                if(j-i == 0)
                    mem[j] += 1;
                else if(j-i < 0)
                    continue;
                else if(mem[j-i] == 0){
                    continue;
                }else if(mem[j-i] != 0){
                    mem[j]+=mem[j-i];
                }
            }

        }

        printf("%d", mem[N*(N+1)/4]/2);
        printf("\n");
    }
}

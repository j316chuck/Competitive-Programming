/*ID: j316chuck
PROG: cbarn
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

using namespace std;

int mem[8][101];
int arr[101];
int cost[101][101];

int main(){

    Rd("cbarn2.in");
    //Wt("cbarn2.out");
    int n, d;
    cin>>n>>d;

    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    for(int i = 0; i < d; i++){
        for(int k = 0; k < n; k++){
            mem[i][k] = INT_MAX;
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            for(int k = i; k < j; k++){
                cost[i][j]+=(j-k)*arr[k];
            }
        }
    }
    for(int i = n-1; i >=0; i--){
        for(int j = i-1; j >=0; j--){
            for(int k = i; k < n; k++){
                cost[i][j]+=(n+j-k)*arr[k];
            }for(int k = 0; k < j; k++){
                cost[i][j]+=(j-k)*arr[k];
            }
        }
    }
    for(int i = 0; i < n-1; i++){
        mem[0][i] = cost[i+1][i];
    }mem[0][n-1] = cost[0][n-1];

    for(int j = 1; j < t; j++){
        for(int i = 0; i < n; i++){
            for(int k = 0; k < i; k++){
                for(int l = )
                mem[j][i] = min(mem[j][i], mem[j-1][k]-)
            }
        }
    }
    /*for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout<<cost[i][j]<<' ';
        }cout<<endl;
    }*/

}

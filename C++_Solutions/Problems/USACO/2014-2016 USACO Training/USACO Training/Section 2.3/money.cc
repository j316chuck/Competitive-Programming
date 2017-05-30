/*
ID: j316chuck
PROG: money
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

vector<int> money;

long long mem[10001][26];

/*long long Recurse(int m, int n){
    if(n == 0)
        return 1;
    else if(m == -1|| n < 0){
        return 0;
    }else if(mem[n][m]!=-1){
        return mem[n][m];
    }else{
        mem[n][m] = Recurse(m-1, n)+ Recurse(m, n-money[m]);
        return mem[n][m];
    }
}*/

int main(){
    freopen("money.in", "r", stdin);
    freopen("money.out", "w", stdout);
    int N, V;
    cin>>V>>N;
    for(int i = 0; i < V; i++){
        int a;
        cin>>a;
        money.push_back(a);
    }
    sort(money.begin(), money.end());
    //memset(mem, 0, sizeof(mem));
    //cout<<Recurse(V-1, N)<<endl;
    for(int i = 0; i <= N; i++){
        if(i % money[0] == 0)
            mem[i][0] = 1;
    }
    for(int i = 0; i < V; i++){
        mem[0][i] = 1;
    }
    /*for(int i = 0; i < N; i++)
        cout<<mem[i][0]<<' ';
    cout<<endl;*/
    for(int i = 1; i < V; i++){
        for(int k = 1; k <= N; k++){
            if(k-money[i]>=0){
                mem[k][i] = mem[k-money[i]][i]+mem[k][i-1];
                //if(k == 10 )
            }
            else{
                mem[k][i] = mem[k][i-1];
            }
            //cout<<mem[k][i]<<' ';
        }//cout<<endl;
    }
    cout<<mem[N][V-1]<<endl;
    exit(0);
}


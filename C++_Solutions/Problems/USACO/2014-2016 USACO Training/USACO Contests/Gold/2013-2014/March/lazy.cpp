/*
ID: j316chuck
PROG: irrigation
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

int G[410][410];
//int C[410][410][410];

int main(){

    //Rd("lazy.in");
    //Wt("lazy.out");
    freopen("lazy.in", "r", stdin);
    freopen("lazy.out", "w", stdout);

    int N, K;
    cin>>N>>K;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cin>>G[i][j];
        }
    }
    memset(C, 0, sizeof(C));
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            for(int k = 1; k <= N-i+1; k++){
                C[i][j][k] = C[i][j][k-1] + G[i+k-1][j];
            }
        }
    }

    int total = 0;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            int sum = 0;
            int upper = -1;
            int lower = -1;
            bool sub = false;
            for(int k = j-K; k <= j+K; k++){
                if(!sub){
                    upper++; lower++;
                }else{
                    upper--; lower--;
                }
                if(k == j){
                    sub = true;
                }
                if(k < 1 || k > N){
                    continue;
                }
                int top = i-upper;
                int bot = i+lower;
                if(top < 1){
                    top = 1;
                }if(bot > N){
                    bot = N;
                }
                sum+=C[top][k][bot-top+1];
                /*if(i-upper < 1){
                    sum += C[1][k][i-1];
                }else{
                    sum += C[i-upper][k][upper];
                }
                if(lower + i > N){
                    sum += C[i+1][k][N-i];
                }else{
                    sum+= C[i+1][k][lower];
                }
                sum+=G[i][k];*/
            }
            total = max(total, sum);
        }
    }
    cout<<total<<endl;
}

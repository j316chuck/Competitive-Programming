/*
ID: j316chuck
PROG: zombie
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

double spell[25][25];
int t, h, sp;
double mem[20010][7][25];

int nd(double dice){
    if(dice == 4) return 0;
    if(dice == 6) return 1;
    if(dice == 8) return 2;
    if(dice == 10) return 3;
    if(dice == 12) return 4;
    if(dice == 20) return 5;
}

double dfs(int hp, double dice, int moves){
    if(mem[hp][nd(dice)][moves] != -1){
        return mem[hp][nd(dice)][moves];
    }
    if(hp <= 0){
        return 1;
    }if(moves == 0){
        return mem[hp][nd(dice)][moves] = 0;
    }
    double res = 0.0;
    for(int i = 1; i <= dice; i++){
        res += (dfs(hp-i, dice, moves-1)/dice);
    }
    return mem[hp][nd(dice)][moves] = res;
}

int main(){

    freopen("zombie.in", "r", stdin);
    //freopen("zombie.out", "w", stdout);

    /*for(int i = 0; i <= 20009; i++){
        for(int j = 0; j <= 6; j++){
            for(int k = 0; k <= 22; k++){
                mem[i][j][k] = -1;
            }
        }
    }*/
    cin>>t;
    for(int i = 0; i < t; i++){
        cin>>h>>sp;
        string s; double res = 0;

        for(int k = 0; k < sp; k++){
            cin>>s;
            int d, m = -1, p = -1;
            for(int j = 0; j < s.size(); j++){
                if(s[j] == 'd'){
                    d = j;
                }else if(s[j] == '-'){
                    m = j;
                }else if(s[j] == '+'){
                    p = j;
                }
            }

            int x, y, z;
            if(m == -1 && p == -1){
                stringstream a(s.substr(0, d)); a>>x;
                stringstream b(s.substr(d+1)); b>>y;
                z = 0;
            }else if(m == -1){
                stringstream a(s.substr(0, d)); a>>x;
                stringstream b(s.substr(d+1, p-d-1)); b>>y;
                stringstream c(s.substr(p+1)); c>>z;
            }else{
                stringstream a(s.substr(0, d)); a>>x;
                stringstream b(s.substr(d+1, m-d-1)); b>>y;
                stringstream c(s.substr(m+1)); c>>z;
                z = -z;
            }
            res = max(res, dfs(h-z, double (y), x));
        }
        printf("Case #%d: %1.6f\n", i+1, res);
    }

    return 0;

}


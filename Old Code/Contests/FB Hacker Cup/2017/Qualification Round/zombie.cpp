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

double dfs(int hp, double dice, int moves){
    if(hp <= 0){
        return 1;
    }if(moves == 0){
        return 0;
    }
    double res = 0.0;
    for(int i = 1; i <= dice; i++){
        res+=(dfs(hp-i, dice, moves-1)/dice);
    }
    return res;
}

int main(){

    freopen("zombie.in", "r", stdin);
    //freopen("zombie.out", "w", stdout);

    /*double sum = 0;
    for(int i = 1; i <= 20; i++){
        sum+=i;
        spell[i][1] = sum/i;
    }
    for(int i = 1; i <= 20; i++){
        for(int k = 2; k <= 20; k++){
            spell[i][k] = spell[i][1] * k;
        }
    }*/
    /*for(int i = 1; i <= 20; i++){
        for(int j = 1; j <= 20; j++){
            cout<<spell[i][j]<<' ';
        }cout<<endl;
    }*/
    //cout<<spell[20][2]<<' '<<spell[4][10]<<endl;
    cin>>t;
    for(int i = 0; i < t; i++){
        cin>>h>>sp;
        string s;

        double ev = -5000, mx, my, mz;
        double res = 0;
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
            /*if(ev < spell[y][x] + z){
                ev = spell[y][x] + z;
                mx = x; my = y; mz = z;
            }*/
            //printf("%1.6f\n", dfs(h-z, double (y), x));
            res = max(res, dfs(h-z, double (y), x));
        }
        printf("Case #%d: %1.6f\n", i+1, res);
        //cout<<mx<<' '<<my<<' '<<mz<<endl;
    }
}

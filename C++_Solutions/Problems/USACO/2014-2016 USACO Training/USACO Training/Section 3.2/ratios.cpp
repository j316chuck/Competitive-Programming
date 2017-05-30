/*ID: j316chuck
PROG: ratios
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
#define pii pair<int, int>

using namespace std;

class pp{
public:
    int a, b, c;
    bool operator < (const pp &p) const{
        return (p.a + p.b + p.c) < (a + b + c);
    }
};

int main(){

    Rd("ratios.in");
    Wt("ratios.out");

    pp G;
    pp A[3];
    scanf("%d %d %d", &G.a, &G.b, &G.c);
    for(int i = 0;  i < 3; i++){
        scanf("%d %d %d", &A[i].a, &A[i].b, &A[i].c);
    }

    pp res, ei; 
    int multiple = 400;
    for(int i = 0; i < 100; i++){
        for(int j = 0; j < 100; j++){
            for(int k = 0; k < 100; k++){
                ei.a = A[0].a * i + A[1].a * j + A[2].a * k;
                ei.b = A[0].b * i + A[1].b * j + A[2].b * k;
                ei.c = A[0].c * i + A[1].c * j + A[2].c * k;    
                /*if(ei.a > G.a && ei.b > G.b && ei.c > G.c
                    && ei.a % G.a == 0 && ei.b % G.b == 0 && ei.c % G.c == 0){
                    if(ei.a/G.a < multiple && ei.b/G.b == ei.a/G.a && ei.a/G.a == ei.c/G.c){
                        multiple = ei.a/G.a;
                        res.a = i; res.b = j; res.c = k;
                    }
                }
                if(ei.a == G.a && ei.b == G.b && ei.c == G.c
                    && ei.a % G.a == 0 && ei.b % G.b == 0 && ei.c % G.c == 0){
                    if(ei.a/G.a < multiple && ei.b/G.b == ei.a/G.a && ei.a/G.a == ei.c/G.c){
                        multiple = ei.a/G.a;
                        res.a = i; res.b = j; res.c = k;
                    }
                }*/
                for(int ii = 1; ii <= 297 && ii <= multiple; ii++){
                    if(ei.a == G.a * ii && ei.b == G.b * ii && ei.c == G.c * ii){
                        multiple = ii;
                        res.a = i; res.b = j; res.c = k;
                    }if(ei.a < G.a * ii || ei.b < G.b * ii || ei.c < G.c * ii){
                        break;
                    }
                }
            }
        }
    }

    if(multiple == 400){
        printf("NONE\n");
    }else{
        printf("%d %d %d %d\n", res.a, res.b, res.c, multiple);
    }
    return 0;
}


/*ID: j316chuck
PROG: bgm
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


int main(){

    Rd("bgm.in");
    Wt("bgm.out");

    int n;
    cin>>n;
    vector<int> B(7, 0); vector<int> E(7, 0);
    vector<int> S(7, 0); vector<int> I(7, 0);
    vector<int> G(7, 0); vector<int> O(7, 0);
    vector<int> M(7, 0);
    for(int i = 0; i < n; i++){
        char c; int a;
        cin>>c>>a;
        a = a%7;
        if(a < 0){
            a = a+7;
        }
        if(c == 'B'){
            B[a]++;
        }else if(c == 'E'){
            E[a]++;
        }else if(c == 'S'){
            S[a]++;
        }else if(c == 'I'){
            I[a]++;
        }else if(c == 'G'){
            G[a]++;
        }else if(c == 'O'){
            O[a]++;
        }else{
            M[a]++;
        }
    }
    //cout<<-34%7 + 7<<endl;
    /*for(int i = 0; i < 7; i++){
        cout<<I[i]<<' ';
    }*/
    long long res = 0;
    for(int b = 0; b < 7; b++){
    for(int e = 0; e < 7; e++){
    for(int s = 0; s < 7; s++){
    for(int i = 0; i < 7; i++){
    for(int g = 0; g < 7; g++){
    for(int o = 0; o < 7; o++){
    for(int m = 0; m < 7; m++){
        if( (b + 2*e + i + 2*s) % 7 == 0 || (g + o + e + s) % 7 == 0
           || (m + o + o ) % 7 == 0){
            res += 1ll * B[b] * E[e] * S[s] * I[i] * G[g] * O[o] * M[m];
        }
    }
    }
    }
    }
    }
    }
    }

    cout<<res<<endl;

    return 0;

}



/*ID: j316chuck
PROG: CF_245
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

#define HM 1000000007
int hext(int h, int ch){
    return (1ll * h * 26 + ch) % HM;
}

int N;
string S;
int mem[5001][5001];
bool pal[5001][5001];

int main(){

    //Rd("CF_245H.in");
    cin>>S>>N;

    /*construct left and right hash*/
    vector<int> rhsh(1, 0);
    vector<int> pow(1, 1);
    for(int i = 0; i < S.size(); i++){
        rhsh.push_back(hext(rhsh.back(), S[i]-'a'));
        pow.push_back((1ll * pow.back() * 26) % HM);
    }
    vector<int> lhsh(1, 0);
    for(int i = S.size()-1; i >= 0; i--){
        lhsh.push_back(hext(lhsh.back(), S[i]-'a'));
    }
    /*check if palindrome for pal[l][r]*/
    for(int len = 0; len <= S.size(); len++){
        for(int i = 1; len+i <= S.size(); i++){
            int r = (rhsh[len+i] - (rhsh[i-1] * pow[len+1]) + HM) % HM;
            int l = (lhsh[S.size()-i+1] - (lhsh[S.size()-len-i] * pow[len+1]) + HM) % HM;
            pal[i][i+len] = (r == l);
        }
    }

    /* dynamic programming */
    for(int i = 0; i <= S.size(); i++){
        mem[i][i] = 1;
    }
    for(int len = 1; len <= S.size(); len++){
        for(int i = 1; len+i <= S.size(); i++){
            mem[i][i+len] = mem[i][i+len-1] + mem[i+1][i+len] - mem[i+1][i+len-1];
            mem[i][i+len] += pal[i][i+len]? 1 : 0;
        }
    }

    /*read in input and solve*/
    for(int i = 0; i < N; i++){
        int a, b;
        cin>>a>>b;
        cout<<mem[a][b]<<endl;
    }
}

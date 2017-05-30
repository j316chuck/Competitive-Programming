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


int main(){

    Rd("CF_245H.in");
    cin>>S>>N;
    for(int i = 0; i < N; i++){
        int a, b;
        cin>>a>>b;
    }
    vector<int> rhsh(1, 0);
    vector<int> lhsh(1, 0);
    vector<int> pow(1, 1);
    for(int i = 0; i < S.size(); i++){
        rhsh.push_back(hext(rhsh.back(), S[i]-'a'));
        pow.push_back((1ll * 26 * pow.back()) % HM);
        //cout<<rhsh.back()<<' '<<pow.back()<<endl;
    }
    for(int i = S.size()-1; i >= 0; i--){
        lhsh.push_back(hext(lhsh.back(), S[i]-'a'));
    }
    string str = "aab";
    int chsh = 0;
    for(int i = 0; i < str.size(); i++){
        chsh = hext(chsh, str[i]-'a');
    }
    //cout<<chsh<<endl;
    int hsub = rhsh[2]*pow[str.size()];
    cout<<rhsh[S.size()-str.size()]*pow[str.size()]<<endl;
    cout<<rhsh[rhsh.size()-2]-hsub<<endl;
    cout<<lhsh[4]<<endl;
    cout<<lhsh[4]-(lhsh[4-str.size()]*pow[str.size()])<<endl;
}


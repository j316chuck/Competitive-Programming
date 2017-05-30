/*ID: j316chuck
PROG: censor
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
#define HA 100000007

int hext(int h, int ch){
    return (1ll * h * HA + ch) % HM;
}

int main(){

    Rd("censor.in");
    //Wt("censor.out");
    string S, T;
    cin>>S>>T;
    int thsh = 0;
    for(int i = 0; i < T.size(); i++){
        thsh = hext(thsh, T[i]-'a');
    }

    string R;
    vector<int> rhsh(1, 0);
    vector<int> HAPW(1, 1);
    for(int i = 0; i < S.size(); i++){
        R+=S[i];
        /*rhsh.push_back(hext(rhsh.back(), S[i]-'a'));
        HAPW.push_back((1ll * HAPW.back() * HA) % HM);

        if(R.size() >= T.size()){
            int hsub = (1ll * HAPW[T.size()] * rhsh[R.size()-T.size()])%HM;
            int hsh =(rhsh.back()-hsub + HM)%HM;
            if(thsh == hsh && R.substr(R.size()-T.size()) == T){
                R.resize(R.size()-T.size());
                rhsh.resize(rhsh.size()-T.size());
                HAPW.resize(HAPW.size()-T.size());
            }
        }*/
        rhsh.push_back(hext(rhsh.back(), S[i]-'a'));
        HAPW.push_back((1ll * HAPW.back() * HA) % HM);

        if(R.size() >= T.size()){
            int hsub = (1ll * HAPW[T.size()] * rhsh[R.size()-T.size()]) %HM;
            int hsh = (rhsh.back()-hsub + HM) % HM;
            if(thsh == hsh && R.substr(R.size()-T.size()) == T){
                R.resize(R.size()-T.size());
                rhsh.resize(rhsh.size()-T.size());
                HAPW.resize(HAPW.size()-T.size());
            }
        }
    }
    cout<<R<<endl;
    return 0;

}




/*ID: j316chuck
PROG: 39J
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

int main(){

    Rd("CF_39J.in");

    string S, T;
    cin>>S>>T;

    vector<int> rhsh(1, 0);
    vector<int> lhsh(1, 0);
    for(int i = 0; i < S.size(); i++){
        rhsh.push_back(hext(rhsh.back(), S[i]-'a'));
    }
    for(int i = S.size()-1; i >= 0; i--){
        lhsh.push_back(hext(lhsh.back(), S[i]-'a'));
    }
    reverse(lhsh.begin(), lhsh.end());

    vector<int> r(1, 0);
    vector<int> l(1, 0);
    for(int i = 0; i < T.size(); i++){
        r.push_back(hext(r.back(), T[i]-'a'));
    }
    for(int i = T.size()-1; i >= 0; i--){
        l.push_back(hext(l.back(), T[i]-'a'));
    }
    reverse(l.begin(), l.end());
    vector<int> ans;
    for(int i = 0; i < r.size(); i++){
        long long a = (long long) l[i] + r[i];
        long long b = (long long) rhsh[i] + lhsh[i+1];
        if(a == b){
            ans.push_back(i+1);
        }
    }
    cout<<ans.size()<<endl;
    for(int i = 0; i < ans.size(); i++){
        cout<<ans[i]<<" ";
    }cout<<endl;
    return 0;
}

/*
ID: j316chuck
PROG: auto
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
#define HM 1000000007

using namespace std;

int hext(int h, int ch){
    return (1ll * h * 26 + ch) % HM;
}

class pp{
public:
    string str;
    int pos;
    vector<int> hsh;
    //int cmp;
    bool operator < (const pp & a) const{
        return (str < a.str); //sort from low to high
    }
};

/*bool cmp(pp ei, pp ai){
    return ei.str.substr(ei.cmp) < ai.str.substr(ai.cmp);
}*/

int W, N;
vector<pp> S;

int main(){

    Rd("auto.in");
    Wt("auto.out");
    cin>>W>>N;

    for(int i = 0; i < W; i++){
        string str;
        cin>>str;
        vector<int> hsh(1, 0);
        for(int j = 0; j < str.size(); j++){
            hsh.push_back(hext(hsh.back(), str[j]-'a'));
        }
        pp ei;
        ei.str = str;
        ei.hsh = hsh;
        ei.pos = i+1;
        S.push_back(ei);
    }
    sort(S.begin(), S.end());
    //cout<<S[0].str<<' '<<S[1].str<<endl;

    for(int i = 0; i < N; i++){
        int k;
        string str;
        cin>>k>>str;
        int hsh = 0;
        for(int j = 0; j < str.size(); j++){
            hsh = hext(hsh, str[j]-'a');
        }

        for(int j = 0; j < S.size(); j++){
            if(hsh == S[j].hsh[str.size()] && str == S[j].str.substr(0, str.size())){
                k--;
                if(k == 0){
                    cout<<S[j].pos<<endl;
                    break;
                }
            }
        }
        if(k!=0){
            cout<<-1<<endl;
        }
    }
    return 0;
}

/*ID: j316chuck
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
#include <cstdlib>

const double Pi=acos(-1.0);
typedef long long LL;

#define Set(a, s) memset(a, s, sizeof (a))
#define Rd(r) freopen(r, "r", stdin)
#define Wt(w) freopen(w, "w", stdout)
#define pii pair<int, int>

using namespace std;

int main(){

    Rd("auto.in");
    Wt("auto.out");

    int W, N;
    cin>>W>>N;

    vector< pair<string, int> > dict;
    for(int i = 0; i < W; i++){
        pair<string, int> a;
        cin>>a.first;
        a.second = i+1;
        dict.push_back(a);
    }
    sort(dict.begin(), dict.end());
    for(int i = 0; i < N; i++){
        int k; string s;
        cin>>k>>s;
        int pos = lower_bound(dict.begin(), dict.end(), make_pair(s, 0)) - dict.begin();
        if(pos+k-1 < dict.size() && dict[pos+k-1].first.substr(0, s.size()) == s){
            cout<<dict[pos+k-1].second<<endl;
        }else{
            cout<<-1<<endl;
        }
    }
    return 0;
}

/*ID: j316chuck
PROG: 248
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
int dp(vector<int> l, vector<int> r){
    if(r.size() == 1){
        return r[0];
    }
    int used_r = -1;
    int first = r[0];
    if(r[0] == r[1]){
        r.erase(r.begin());
        r[0]++;
        used_r = dp(l, r);
        r[0]--;
        r.insert(r.begin(), first);
    }
    int used_l = -1;
    if(l.size()!=0 && l[l.size()-1] == r[0]){
        int fy = l[l.size()-1];
        l.pop_back();
        r[0]++;
        used_l = dp(l, r);
        r[0]--;
        l.push_back(fy);
    }

    int no_used_r = -1;
    l.push_back(r[0]);
    r.erase(r.begin());
    no_used_r = dp(l, r);

    return max(used_r, max(used_l, no_used_r));
}
int main(){

    freopen("248.in", "r", stdin);
    freopen("248.out", "w", stdout);

    int n;
    cin>>n;
    vector<int> right;
    int a;
    for(int i = 0; i < n; i++){
        cin>>a;
        right.push_back(a);
    }
    vector<int> left;
    cout<<dp(left, right)<<endl;

}

/*ID: j316chuck
PROG: radio
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
int distance(const pair<int, int> &a, const pair<int, int> &c){
    return (a.first-c.first)*(a.first-c.first) + (a.second-c.second)*(a.second-c.second);
}
int main(){
    pair<int, int> f;
    f.first = 1;
    f.second = 2;
    pair<int, int> t;
    t.first = 1;
    t.second = 2;
    cout<<distance(f, t)<<endl;
}

/*ID: j316chuck
PROG: lasers
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
    map<string, int> words;
    words.insert(make_pair("earth", 1));
    words["sun"] = 3;
    map<string, int>::iterator it = words.begin();
    while(it!=words.end()){
        cout<<it->first<<"::"<<it->second<<endl;
        it++;
    }
    it = words.find("earth");
    cout<<it->second<<endl;

}

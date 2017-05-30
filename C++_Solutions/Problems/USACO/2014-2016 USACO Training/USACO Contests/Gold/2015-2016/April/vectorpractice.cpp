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

int main(){

    freopen("248.in", "r", stdin);
    //freopen("248.out", "w", stdout);

    /*int n;
    cin>>n;
    vector<int> right;
    int a;
    for(int i = 0; i < n; i++){
        cin>>a;
        right.push_back(a);
    }
    vector<int> subvector(right.begin()+1, right.end());
    subvector.pop_back();
    for(int i = 0; i < subvector.size(); i++){
        cout<<subvector[i]<<' ';
    }*/
    set<int> myset;
    for(int i = 1; i <= 20; i++){
        myset.insert(i);
    }
    myset.erase(myset.find(40));

    for(set<int>::iterator it = myset.begin(); it!=myset.end(); it++){
        cout<<*it<<endl;
    }
}

/*ID: j316chuck
PROG:
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

    Rd("circlecross.in");
    Wt("circlecross.out");

    int n;
    cin>>n;
    vector<int> A(2*n);
    for(int i = 0; i < 2*n; i++){
        cin>>A[i];
    }
    int total = 0;
    vector<int> pairs;
    for(int i = 0; i < A.size(); i++){
        if(pairs.size() == 0){
            pairs.push_back(A[i]);
            continue;
        }
        auto it = find(pairs.begin(), pairs.end(), A[i]);
        if(it == pairs.end()){
            pairs.push_back(A[i]);
        }else{
            total += pairs.size() - (it - pairs.begin()) - 1;
            pairs.erase(it);
        }
    }
    cout<<total<<endl;
    return 0;
}

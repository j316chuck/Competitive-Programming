/*ID: j316chuck
PROG: nocross
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

vector<int> A(1005);
vector<int> B(1005);

bool cross(int i, int j){
    if(abs(A[i] - B[j]) <= 4){
        return true;
    }
    return false;
}
int main(){

    Rd("nocross.in");
    Wt("nocross.out");

    int n;
    cin>>n;

    for(int i = 0; i < n; i++){
        cin>>A[i];
    }for(int i = 0; i < n; i++){
        cin>>B[i];
    }

    vector<int> D(n, 0);
    for(int i = 0; i < n; i++){
        if(cross(0, i)){
            D[i] = 1;
        }
    }

    for(int i = 1; i < n; i++){
        if(cross(i, 0)) D[0] = 1;
        for(int j = 1; j < n; j++){
            D[j] = max(D[j-1], D[j]);
        }
        for(int j = n-1; j >= 1; j--){
            if(cross(i, j)){
                D[j] = max(D[j], D[j-1] + 1);
            }
        }
    }
    int m = -1;
    for(int i = 0; i < n; i++){
        //cout<<D[i]<<endl;
        m = max(D[i], m);
    }
    cout<<m<<endl;
    return 0;
}



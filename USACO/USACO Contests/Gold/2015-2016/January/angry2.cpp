/*ID: j316chuck
PROG: angry
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

double mem[50010][2];

int main(){

    freopen("angry.in", "r", stdin);
    //freopen("angry.out", "w", stdout);

    int n;
    cin>>n;
    vector<double> A(n);

    for(int i = 0; i < n; i++){
        cin>>A[i];
    }
    sort(A.begin(), A.end());

    mem[0][0] = 0;
    mem[0][1] = 0;

    for(int k = 0; k < 2; k++){
        for(int i = 1; i < n; i++){
            mem[i][k] = max(abs(A[i] - A[i-1]), mem[i-1][k] + 1);
            //cout<<mem[i][k]<<' '<<A[i]-A[i-1]<<' '<<i<<endl;
        }
        reverse(A.begin(), A.end());
    }
    reverse(A.begin(), A.end());

    double res = 999999;
    for(int i = 0; i < n-1; i++){
        double c = (A[i+1] - A[i]);
        double l = mem[i][0];
        double r = mem[n-i-2][1];
        if(r >= c && r >= l+1){
            res = min(r, res);
        }else if(l >= r+1 && l >= c){
            res = min(l, res);
        }else{
            res = min(res, max(c/2, max(r+1, c+1)));
        }
    }

    printf("%.1f\n", res);
}

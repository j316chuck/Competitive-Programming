/*ID: j316chuck
PROG: agrinet
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

int G[101][101];

int main(){

    Rd("agrinet.in");
    Wt("agrinet.out");

    int N;
    cin>>N;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin>>G[i][j];
        }
    }
    vector<bool> used(N, false);
    vector<int> D(N, pow(10, 8));

    D[0] = 0;
    int result = 0;
    for(int i = 0; i < N; i++){
        int j = -1;
        for(int k = 0; k < N; k++){
            if(used[k]) continue;
            if(j == -1 || D[k] < D[j]){
                j = k;
            }
        }
        if(j == -1){
            break;
        }
        used[j] = true;
        result+=D[j];

        for(int k = 0; k < N; k++){
            if(!used[k] && G[j][k]!=0 && D[k] > G[j][k]){
                D[k] = G[j][k];
            }
        }
    }

    cout<<result<<endl;

}

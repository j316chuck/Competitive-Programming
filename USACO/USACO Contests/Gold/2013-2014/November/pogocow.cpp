/*ID: j316chuck
PROG: pogocow
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
#define NOPATH -10000000

using namespace std;

vector<int> X;
vector<int> P;
int DP[1001][1001];
int DP2[1001][1001];

bool cmp(int a, int b){
	return X[a] < X[b];
}

int main(){

    Rd("pogocow.in");
    Wt("pogocow.out");
    //-std = c++11 or c++0x
    int N;
    cin>>N;
    X.resize(N+1);
    P.resize(N+1);
    vector<int> index(N+1);
    for(int i = 1; i <= N; i++){
    	cin>>X[i]>>P[i];
        index[i] = i;
    }
    sort(index.begin()+1, index.end(), cmp);
    sort(X.begin()+1, X.end());

    /*for(int i = 1; i <= N; i++){
        cout<<X[i]<<' '<<P[index[i]]<<endl;
    }*/

    /*Interval DP)*/
    int res = 0;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j < i; j++){
            DP[i][j] = NOPATH;
            for(int k = j; k >= 1; k--){
                if(X[i]-X[j] >= X[j]-X[k]){
                    if(DP[j][k] != NOPATH){
                        DP[i][j] = max(DP[i][j], DP[j][k]+P[index[i]]);
                    }
                }else{
                    break;
                }
            }
            res = max(res, DP[i][j]);
        }
        DP[i][i] = P[index[i]];
        res = max(res, DP[i][i]);
    }
    
    reverse(X.begin(), X.end());
    reverse(index.begin(), index.end());

    for(int i = 1; i <= N; i++){
        for(int j = 1; j < i; j++){
            DP2[i][j] = NOPATH;
            for(int k = j; k >= 1; k--){
                if(abs(X[i]-X[j]) >= abs(X[j]-X[k])){
                    if(DP2[j][k] != NOPATH){
                        DP2[i][j] = max(DP2[i][j], DP2[j][k]+P[index[i]]);
                    }
                }else{
                    break;
                }
            }
            res = max(res, DP2[i][j]);
        }
        DP2[i][i] = P[index[i]];
        res = max(res, DP2[i][i]);
    }

    printf("%d\n", res);
    return 0;
}
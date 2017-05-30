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

const double Pi=acos(-1.0);
typedef long long LL;

#define Set(a, s) memset(a, s, sizeof (a))
#define Rd(r) freopen(r, "r", stdin)
#define Wt(w) freopen(w, "w", stdout)
using namespace std;

int best[301][31];
int cost[301][31];
int x[301];

int main(){

    //freopen("POJ_1160.in", "r", stdin);

    int v, p;
    cin>>v>>p;

    for(int i = 0; i < v; i++){
        cin>>x[i];
    }

    for(int i = 0; i < v-1; i++){
        for(int j = i+1; j < v; j++){
            for(int k = i; k <= j; k++){
                cost[i][j] += min(abs(x[k]-x[i]), abs(x[k]-x[j]));
            }
        }
    }

    for(int i = 0; i < v; i++){
        for(int j = 0; j <=i; j++){
             best[i][0] += abs(x[i]-x[j]);
        }
    }

    for(int i = 0; i < v; i++){
        for(int j = 1; j < p; j++){
            best[i][j] = 9999999;
            for(int k = 0; k < i; k++){
                best[i][j] = min(best[i][j], best[k][j-1] + cost[k][i]);
            }
        }
    }
    int result = 999999;
    for(int i = 0; i < v; i++){
        for(int k = i; k < v; k++){
            best[i][p-1]+=abs(x[i]-x[k]);
        }
        result = min(result, best[i][p-1]);
    }
    cout<<result<<endl;
}

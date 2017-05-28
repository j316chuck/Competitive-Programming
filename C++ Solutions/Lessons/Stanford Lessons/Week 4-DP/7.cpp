/*ID: j316chuck
PROG: poj_2127
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


class pp{
public:
    int v, n, m;
    bool operator < (const pp &a) const{
        return v < a.v;
    }
};

int main(){

    //Rd("7.in");
    int n, m;
    cin>>n;
    vector<int> A(n+1);
    for(int i = 0; i < n; i++){
        cin>>A[i];
    }
    cin>>m;
    vector<int> B(m+1);
    for(int i = 0; i < m; i++){
        cin>>B[i];
    }

    vector<pp> G;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(A[i] == B[j]){
                pp ei;
                ei.n = i; ei.m = j; ei.v = A[i];
                G.push_back(ei);
            }
        }
    }
    sort(G.begin(), G.end());
    /* LIS dp on a pair */
    /*for(int i = 0; i < G.size(); i++){
        cout<<G[i].v<<' '<<G[i].n<<' '<<G[i].m<<endl;
    }*/

    int parent[510];
    memset(parent, -1, sizeof(parent));
    int lis[510];
    for(int i = 0; i <= 501; i++){
        lis[i] = 1;
    }

    int max = -1, pos = -1;
    for(int i = 1; i < G.size(); i++){
        for(int j = 0; j < i; j++){
            if(G[i].n > G[j].n && G[i].m > G[j].m && G[i].v > G[j].v && lis[i] < lis[j] + 1){
                lis[i] = lis[j] + 1;
                parent[i] = j;
            }
        }
        if(max < lis[i]){
            max = lis[i];
            pos = i;
        }
    }
    /*for(int i = 0; i < G.size(); i++){
        cout<<parent[i]<<' '<<lis[i]<<endl;
    }*/
    vector<int> result;
    while(1){
        result.push_back(G[pos].v);
        pos = parent[pos];
        if(pos == -1){
            break;
        }
    }

    printf("%d\n", max);
    for(int i = result.size()-1; i >= 0; i--){
        printf("%d ", result[i]);
    }
    printf("\n");
    return 0;

}

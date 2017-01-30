/*ID: j316chuck
PROG: cbarn
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
#define edge pair< int, int >

using namespace std;

int n, m, a, b;
int parent[4000010];
long long result;

int findset(int x, int *parent){
    if(x != parent[x])
        parent[x] = findset(parent[x], parent);
    return parent[x];
}
int nd(int r, int c){
    return r * n + c;
}

int main(){

    Rd("fencedin.in");
    //Wt("fencedin.out");

    cin>>a>>b>>n>>m;
    vector<int> v(n+1);
    vector<int> h(m+1);
    for(int i = 0; i < n; i++){
        cin>>v[i];
    }
    for(int j = 0; j < m; j++){
        cin>>h[j];
    }

    sort(v.begin(), v.end());
    sort(h.begin(), h.end());
    v[n] = a - v[n-1];
    for(int i = 0; i < n-1; i++){
        v[i+1] = v[i+1]-v[i];
    }
    h[m] = b - h[m-1];
    for(int i = 0; i < m-1; i++){
        h[i+1] = h[i+1]-h[i];
    }
    int vi = 0, hi = 0;
    sort(v.begin(), v.end());
    sort(h.begin(), h.end());
    n++; m++;
    for(int i = 1; i <= n*m; i++){
        parent[i] = i;
    }
    while(vi < n || hi < m){
        if(hi == m || (vi < n && v[vi] < h[hi])){
            for(int i = 0; i < m-1; i++){
                int pu = findset(nd(i, vi), parent);
                int pv = findset(nd(i+1, vi), parent);
                if(pu!=pv){
                    parent[pu] = parent[pv];
                    result+=v[vi];
                }
            }
            vi++;
        }else{
            for(int i = 0; i < n-1; i++){
                int pu = findset(nd(hi, i), parent);
                int pv = findset(nd(hi, i+1), parent);
                if(pu!=pv){
                    parent[pu] = parent[pv];
                    result+=h[hi];
                }
            }
            hi++;
        }
    }
    cout<<result<<endl;
    /*
    algorithm -> read in numbers 400001 array
    give values and edges weights etc.
    use kruskal to solve :D
    */


}

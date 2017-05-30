/*ID: j316chuck
PROG: checklist
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

int gur[1005][1005];
int hol[1005][1005];

int dist(pair<int, int> a, pair<int, int> b){
    return (a.first-b.first)*(a.first-b.first) + (a.second-b.second)*(a.second-b.second);
}

int main(){
    Rd("checklist.in");
    Wt("checklist.out");
    int h, g;
    cin>>h>>g;
    pair<int, int> a;
    vector< pair<int, int> > H;
    vector< pair<int, int> > G;

    for(int i = 0; i < h; i++){
        cin>>a.first>>a.second;
        H.push_back(a);
    }
    for(int i = 0; i < g; i++){
        cin>>a.first>>a.second;
        G.push_back(a);
    }
    for(int i = 0; i < h; i++){
        for(int j = 0; j < g; j++){
            if(i == 0){
                hol[i][j] = 0;
                if(j == 0){
                    gur[i][j] = dist(G[0], H[0]);
                }else{
                    gur[i][j] = dist(G[j], G[j-1])+gur[i][j-1];
                }
            }else{
                if(j == 0){
                    hol[i][j] = dist(H[i], H[i-1])+hol[i-1][j];
                    gur[i][j] = 0;
                }else{
                    hol[i][j] = min(dist(H[i], H[i-1]) + hol[i-1][j], dist(H[i], G[j]) + gur[i-1][j]);
                    gur[i][j] = min(dist(G[j], G[j-1]) + gur[i][j-1], dist(G[j], H[i]) + hol[i][j-1]);
                }
            }
        }
    }
    cout<<hol[h-1][g-1]<<endl;
}


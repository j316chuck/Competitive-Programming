/*ID: j316chuck
PROG: poj_2292
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

int C[35];
int best[15][35];
int cost[35][35];
int parent[15];

void update(string s){
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '+'){
            C[26]++;
        }else if(s[i] == '*'){
            C[27]++;
        }else if(s[i] == '/'){
            C[28]++;
        }else if(s[i] == '?'){
            C[29]++;
        }else{
            C[s[i]-'a']++;
        }
    }
}

int main(){

    freopen("8.in", "r", stdin);

    int t;
    cin>>t;
    for(int it = 0; it < t; it++){
        memset(best, 0, sizeof(best));
        memset(C, 0, sizeof(C));
        memset(cost, 0, sizeof(cost));
        memset(parent, -1, sizeof(parent));
        int n;
        cin>>n;
        for(int k = 0; k < n; k++){
            string s;
            cin>>s;
            update(s);
        }

        for(int i = 0; i < 30; i++){
            for(int j = i+1; j < 30; j++){
                for(int k = i; k <= j; k++){
                    cost[i][j]+=(k-i)*C[k];
                }
            }
        }
        for(int i = 1; i < 30; i++){
            best[1][i] = cost[0][i];
        }
        for(int i = 2; i <= 12; i++){
            for(int j = i; j < 30; j++){
                best[i][j] = best[i-1][i-2] + cost[i-1][j];
                parent[i][j] = i-1;
                for(int k = i-1; k < j; k++){
                    if(best[i][j] > best[i-1][k] + cost[k+1][j]){
                        best[i][j] = best[i-1][k] + cost[k+1][j];
                        parent[i][j] = k+1;
                    }
                }
            }
        }


        //cout<<best[12][29]<<endl;
    }

    return 0;
}

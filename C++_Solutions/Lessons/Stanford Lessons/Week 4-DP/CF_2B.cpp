/*ID: j316chuck
PROG: CF2B
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

pair<int, int> dp[1010][1010];
bool up[1010][1010];

int main(){

    //freopen("CF_2B.in", "r", stdin);
    int n;
    cin>>n;
    bool zero = false; int zr = -1, zc = -1;
    vector< vector< pair<int, int> > > G;
    for(int i = 0; i < n; i++){
        vector< pair<int, int> > temp;
        for(int j = 0; j < n; j++){
            int a, b, c;
            cin>>a;
            if(!a){
                zero = true; zr = i, zc = j;
            }
            int counter1 = 0, counter2 = 0;
            b = a, c = a;
            while(b%2 == 0){
                b = b/2;
                counter1++;
            }while(c%5 == 0){
                c = c/5;
                counter2++;
            }
            temp.push_back(make_pair(counter1, counter2));
        }
        G.push_back(temp);
    }
    /*for(int i = 0; i < n; i++){
        for(int j = 0; j < n;j++){
            cout<<G[i][j].first<<' ';
        }cout<<endl;
    }*/

    memset(dp, 0x3f, sizeof(dp));
    memset(up, 0, sizeof(up));
    for(int i = 1; i <= n; i++){
        dp[i][0].first = 1000000; dp[0][i].first = 1000000;
        dp[i][0].second = 1000000; dp[0][i].second = 1000000;
    }
    dp[1][0].first = 0; dp[1][0].second = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(min(dp[i-1][j].first, dp[i-1][j].second) <
               min(dp[i][j-1].first, dp[i][j-1].second)
               || (min(dp[i-1][j].first, dp[i-1][j].second) ==
               min(dp[i][j-1].first, dp[i][j-1].second)) &&
               (dp[i-1][j] <= dp[i][j-1])){
                dp[i][j].first = dp[i-1][j].first;
                dp[i][j].second = dp[i-1][j].second;
                up[i][j] = true;
            }else{
                dp[i][j].first = dp[i][j-1].first;
                dp[i][j].second = dp[i][j-1].second;
                up[i][j] = false;
            }
            dp[i][j].first+=G[i-1][j-1].first;
            dp[i][j].second+=G[i-1][j-1].second;
            //cout<<dp[i][j].first<<' '<<dp[i][j].second<<' ';
        }//cout<<endl;
    }
    if(min(dp[n][n].first, dp[n][n].second) <= 1 ||  zero == false){
        cout<<min(dp[n][n].first, dp[n][n].second)<<endl;
        string str = "";
        int r = n, c = n;
        while(1){
            if(r == 1 && c == 1){
                break;
            }
            if(up[r][c]){
                str+='D';
                r = r-1;
            }else{
                str+='R';
                c = c-1;
            }
        }
        for(int i = str.size()-1; i >= 0; i--){
            cout<<str[i];
        }cout<<endl;
    }else{
        cout<<1<<endl;
        for(int i = 0; i < zr; i++){
            cout<<"D";
        }for(int j = 0; j < zc; j++){
            cout<<"R";
        }for(int i = zr; i < n; i++){
            cout<<"D";
        }for(int j = zc; j < n; j++){
            cout<<"R";
        }
        cout<<endl;
    }

}

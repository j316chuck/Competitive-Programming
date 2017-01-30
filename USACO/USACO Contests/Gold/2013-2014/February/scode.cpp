/*ID: j316chuck
PROG: scode
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

int mem[101][101];
string S;

int dp(int i, int j){

    if(mem[i][j]!=-1){
        return mem[i][j];
    }

    mem[i][j] = 1;
    int left = i;
    int right = j;
    string l = "";
    string r = "";
    int len = 1;
    //cout<<mem[i][j]<<' '<<left<<' '<<right<<endl;
    while(left < right-1){
        l += S[left];
        r.insert(0, string(1, S[right]));
        if(l == r){
            mem[i][j] += dp(left+1, j);
            mem[i][j] += dp(i, right-1);
        }
        if(l == S.substr(left+1, len)){
            mem[i][j] += dp(left+1, j);
        }
        if(r == S.substr(j-2*len+1, len)){
            mem[i][j] += dp(i, right-1);
        }
        mem[i][j] = mem[i][j] % 2014;
        left++;
        right--;
        len++;
    }
    //cout<<i<<' '<<j<<' '<<mem[i][j]<<' '<<l<<' '<<r<<endl;
    return mem[i][j];

}

int main(){

    Rd("scode.in");
    Wt("scode.out");
    memset(mem, -1, sizeof(mem));

    cin>>S;
    cout<<(dp(0, S.size()-1)-1 + 2014) % 2014<<endl;
}  e

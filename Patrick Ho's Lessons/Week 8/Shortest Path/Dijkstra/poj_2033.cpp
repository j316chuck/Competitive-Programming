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

int main(){

    //freopen("POJ_2033.in", "r", stdin);
    string s;
    int mem[5005];
    while(cin>>s){
        if(s=="0"){
            break;
        }
        memset(mem, 0, sizeof(mem));
        mem[0] = 1; mem[1] = 1;
        for(int i = 2; i <= s.size(); i++){
            if(s[i-1]-'0' == 0){
                mem[i] = mem[i-2];
            }else if((s[i-1]-'0')+(s[i-2]-'0')*10 <= 26 && s[i-2]-'0'!=0){
                mem[i] = mem[i-2]+mem[i-1];
            }else{
                mem[i] = mem[i-1];
            }
        }
        cout<<mem[s.size()]<<endl;
    }
}

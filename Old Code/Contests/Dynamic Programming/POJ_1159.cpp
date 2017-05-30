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

short mem[5001][5001];
int Recurse(string s, int l, int r){
	if(s.size()== 1 ||s.size()==0){
		mem[l][r] = 0;
        //cout<<s<<' '<<l<<' '<<r<<' '<<mem[l][r]<<endl;
		return 0;
	}if(mem[l][r] != -1){
	    //cout<<mem[l][r]<<endl;
		return mem[l][r];
	}
	if(s[0] == s[s.size()-1]){
		mem[l][r] = Recurse(s.substr(1, s.size()-2), l+1, r-1);
        //cout<<s<<' '<<l<<' '<<r<<' '<<mem[l][r]<<' '<<mem[l+1][r-1]<<endl;
		return mem[l][r];
	}else{

		mem[l][r] = 1+ min(Recurse(s.substr(0, s.size()-1), l, r-1), Recurse(s.substr(1, s.size()-1), l+1, r));
        //cout<<Recurse(s.substr(0, s.size()-1), l, r-1)<<' '<<Recurse(s.substr(1, s.size()-1), l+1, r)<<' ';
        //cout<<s<<' '<<l<<' '<<r<<' '<<mem[l][r]<<' '<<mem[l][r-1]<<' '<<mem[l+1][r]<<endl;
		return mem[l][r];
	}
}
int main(){
    //freopen("POJ_1159.in", "r", stdin);
	string s;
	int n;
	cin>>n>>s;
	for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            mem[i][j] = -1;
            if(i == j){
                mem[i][j] = 0;
            }
        }
	}
    for(int j = 0; j <= n; j++){
        mem[0][j] = 0;
    }
    for(int j = 0; j <= n; j++){
        mem[1][j] = 0;
    }
    for(int i = 2; i <= n; i++){
        for(int j = 0; j <= n-i; j++){
            if(s[j] == s[j+i-1]){
                mem[i][j] = mem[i-2][j+1];
            }else{
                mem[i][j] = 1+min(mem[i-1][j], mem[i-1][j+1]);
            }
        }
    }
    cout<<mem[n][0]<<endl;
	//cout<<n<<s<<endl;
    //cout<<Recurse(s, 0, n-1)<<endl;

    /*for(int i = 0; i <= n; i++){
        for(int j =  0; j <= n; j++){
            cout<<mem[i][j]<<' ';
        }cout<<endl;
	}*/
}

/*ID: j316chuck
PROG: ratios
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

int A[1010];
int DP[1010][1010];
int N;
string S;

int mem(int i, int a){
	if(i == N){
		return 1;
	}if(DP[i][a] >= 0){
		return DP[i][a];
	}if(S[i] == '('){
		return DP[i][a] = (mem(i+1, a+1) + mem(i+1, a)) % 2012; 
	}
	
	int b = A[i] - a;
	int ans = 0;
	if(a > 0) 
		ans += mem(i+1, a-1);
	if(b > 0)
		ans += mem(i+1, a);
	return DP[i][a] = ans % 2012;
}

int main(){

	Rd("bbreeds.in");
	//Wt("bbreeds2.out");

	cin>>S;
	N = S.size();

	A[0] = 0;
	for(int i = 0; i < N; i++){
		A[i+1] = A[i] + S[i] == '(' ? 1 : -1;
	}
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			DP[i][j] = -1;
		}
	}

	cout<<mem(0, 0)<<endl;
}
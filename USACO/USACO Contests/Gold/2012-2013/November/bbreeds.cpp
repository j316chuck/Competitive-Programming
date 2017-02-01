/*ID: j316chuck
PROG: recording
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
#define NOPATH -100000000

using namespace std;

int DP[1010][1010];

int main(){

    Rd("bbreeds.in");
    Wt("bbreeds.out");

    string S;
    cin>>S;
    vector<int> A;
    A.push_back(0);
    int left = 0, right = 0;
    for(int i = 0; i < S.size(); i++){
    	if(S[i] == '('){
    		left++;
    	}else{
    		right++;
    	}
    	if(right > left){
    		cout<<0<<endl;
    		return 0;
    	}else if(right == left){
    		A.push_back(i+1);
    	}
    }
    A.push_back(S.size());
    
    if(right!=left){
    	cout<<0<<endl;
    }
    for(int i = 0; i <= 1000; i++){
    	for(int j = 0; j <= 1000; j++){
    		if(j == 0){
    			DP[i][j] = 1;
    		}else if(i == 0){
    			DP[i][j] = 0;
    		}else{
    			DP[i][j] = (DP[i-1][j-1] + DP[i-1][j]) % 2012;
    		}
    	}
    }

    int result = 1;
    for(int i = 1; i < A.size(); i++){
    	int c = A[i]-A[i-1];
    	result *= DP[c][c/2];
    	result = result % 2012;
    }
    cout<<result<<endl;
    return 0;
}
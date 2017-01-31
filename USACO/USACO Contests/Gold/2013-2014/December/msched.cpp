/*ID: j316chuck
PROG:
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

int main(){

    Rd("msched.in");
    Wt("msched.out");

    int N;
    cin>>N;

    vector<pii> A(N);
    int t = 0;
    for(int i = 0; i < N; i++){
    	cin>>A[i].first>>A[i].second;
    	t = max(t, A[i].second);
    }        
    vector<int> V;
    for(int i = 0; i <= t; i++){
    	V.push_back(i);
    }
    sort(A.begin(), A.end());
    reverse(A.begin(), A.end());
    
    int total = 0;
    for(int i = 0; i < A.size(); i++){
    	int it = lower_bound(V.begin(), V.end(), A[i].second) - V.begin();
    	it--;
    	if(it < 0){
    		continue;
    	}else{
    		total += A[i].first;
    		V.erase(V.begin()+it);
    	}
    }
    cout<<total<<endl;
    return 0;  
}


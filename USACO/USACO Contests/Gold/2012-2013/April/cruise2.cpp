/*ID: j316chuck
PROG: cruise
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

int N, M, K;

int main(){

	Rd("cruise.in");
	//Wt("cruise.out");
	
	cin>>N>>M>>K;
	vector<pii> G(N);
	vector<int> A[N];
	string S;

	for(int i = 0; i < N; i++){
		pair<int, int> a;
		cin>>a.first>>a.second;
		a.first--; 
		a.second--;
		G[i] = a;
	}
	for(int i = 0; i < M; i++){
		cin>>S[i];
	}
	int current = 0;
	int mod = -1, residue = -1;
	for(int i = 0; i < K; i++){
		for(int j = 0; j < M; j++){
			//cout<<current + 1 <<' ';
			if(S[j] == 'L'){
				current = G[current].first;
			}else{
				current = G[current].second;
			}
		}
		//cout<<current + 1 <<endl;
		A[current].push_back(i);
		int length = A[current].size();
		if(length > 2){
			int d1 = A[current][length - 1] - A[current][length - 2];
			int d2 = A[current][length - 2] - A[current][length - 3];
			if(d1 == d2){
				mod = d1;
				residue = A[current][length - 2];
				break;
			}
		}
	}
	if(mod == -1) {
		cout<<current + 1<<endl;
	}else {
		K -= residue;
		K = K % mod;
		for(int i = 0; i < K; i++){
			for(int j = 0; j < M; j++){
				if(S[j] == 'L'){
					current = G[current].first;
				}else{
					current = G[current].second;
				}
			}
		}
		cout<<current + 1<<endl;
	}
	return 0;
}
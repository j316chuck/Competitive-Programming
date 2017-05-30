/*ID: j316chuck
PROG: fuel
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

int N, G, B, D;

class pp{
public:
	int pos, cost;
	bool operator < (const pp & a) const{
		return pos < a.pos;
	}
};

int main(){

	Rd("fuel.in");
	//Wt("fuel.out");

	cin>>N>>G>>B>>D;
	vector<pp> A(N);
	vector<int> dist(N, 0);

	for(int i = 0; i < N; i++){
		cin>>A[i].pos>>A[i].cost;
	}
	sort(A.begin(), A.end());

	dist[N-1] = N-1;
	if(A[N-1].pos + G < D){
			cout<<-1<<endl;
			return 0;
	}
	for(int i = N-2; i >= 0; i--){
		if(A[i].pos + G < A[i+1].pos){
			cout<<-1<<endl;
			return 0;
		}
		int current = i + 1, prev = -1; 
		while(A[i].cost < A[current].cost){
			if(prev == current){	
				break;
			}else{
				prev = current;
				current = dist[current];
			}
		}
		if(A[i].cost > A[current].cost){
			dist[i] = current;
		}else{
			dist[i] = i;
		}
	}
	if(B < A[0].pos){
		cout<<-1<<endl;
		return 0;
	}
	for(int i = 0; i < N; i++){
		if(dist[i] == i){
			dist[i] = -1;
		}
	}

	int fuel = B - A[0].pos;
	long long total = 0;
	for(int i = 0; i < N; i++){
		int gasNeeded = min(G, dist[i] == -1 ? D: A[dist[i]].pos - A[i].pos);
		if(gasNeeded > fuel){
			total += (long long) (gasNeeded - fuel) * (long long) A[i].cost;
			fuel = gasNeeded;
		}
		
	}

	return 0;
}
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

int N, M;
char G[510][510];
int visit[510][510][2];

class pp{
public:
	int i, j, dir, moves;
	bool operator < (const pp & a) const{
		return a.moves < moves;
	}
};

int main(){

	Rd("gravity.in");
	Wt("gravity.out");

	cin>>N>>M;
	pp ai;
	int R, C;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			cin>>G[i][j];
			if(G[i][j] == 'C'){
				ai.i = i;
				ai.j = j;
				ai.dir = 1;
				ai.moves = 0; 
				G[i][j] = '.';
			}if(G[i][j] == 'D'){
				G[i][j] = '.';
				R = i; 
				C = j;
			}
		}
	}

	priority_queue<pp> Q;
	Q.push(ai);
	memset(visit, -1, sizeof(visit));

	while(!Q.empty()){
		pp ei = Q.top();
		Q.pop();
		int i = ei.i, j = ei.j, dir = ei.dir, moves = ei.moves;
		if(i == R && j == C){
			cout<<moves<<endl;
			return 0; //termination condition
		}else if(moves != 0 && i <= 0 || i >= N-1 || j < 0 || j >= M || G[i][j] == '#'){
			continue;  //boundary checks and rule 1 + game rule
		}else if(visit[i][j][(dir+1)/2]!=-1){
			continue; //visited states already
		}else if(G[i+dir][j] == '.'){
			visit[i][j][(dir+1)/2] = moves; //may be wrong
			ai.i = i+dir; ai.j = j; ai.moves = moves; ai.dir = dir;
			Q.push(ai);//rule 2
		}else{
			visit[i][j][(dir+1)/2] = moves;
			ai.i = i; ai.j = j-1; ai.moves = moves; ai.dir = dir;
			Q.push(ai);
			ai.j = j+1; 
			Q.push(ai);
			ai.moves = moves+1; ai.j = j; ai.dir = -dir;
			Q.push(ai);
		}
	}
	
	cout<<-1<<endl;
	return 0;
}
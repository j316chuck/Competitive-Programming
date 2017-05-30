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
const int MX=41;
int dp[MX][MX][MX][MX], mapa[MX][MX], row[MX][MX];
int N,M,Q,a,b,c,d,e,r;

int main(){
    Rd("372B.in");
	scanf("%d%d%d",&N,&M,&Q);

	for(int i=1;i<=N;i++)
	for(int j=1;j<=M;j++){
		scanf("%1d",&mapa[i][j]);
		row[i][j]=row[i][j-1];
		if(mapa[i][j]) row[i][j]=0;
		else row[i][j]++;
	}
    /*for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            cout<<row[i][j]<<' ';
        }cout<<endl;
    }*/

	for(a=1;a<=N;a++)
	for(b=1;b<=M;b++)
	for(c=a;c<=N;c++)
	for(d=b;d<=M;d++){
		dp[a][b][c][d]=dp[a][b][c-1][d]+dp[a][b][c][d-1]-dp[a][b][c-1][d-1];
		r=d-b+1;
		for(e=c;e>=a && r;e--){
			r=(r<row[e][d])? r : row[e][d] ;
			dp[a][b][c][d]+=r;
		}
	}

	while(Q--){
		scanf("%d%d%d%d",&a,&b,&c,&d);
		printf("%d\n",dp[a][b][c][d]);
	}
	return 0;
}

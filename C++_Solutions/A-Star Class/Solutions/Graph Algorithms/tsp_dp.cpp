/*
PROG: tsp
LANG: C++
ID:  fatih
*/

// TSP with DP: O(2^N)
#include <fstream>

#define MAX 19
#define INF 20000

using namespace std;

short n,g[MAX][MAX],dp[1<<MAX][MAX];

int main()
{
	short m,a,b,c;

	ifstream fin("tsp.in");
	fin >> n >> m;
	for (int i=0; i<m; i++)
	{
		fin >> a >> b >> c;
		g[--a][--b]=g[b][a]=c;
	}
	fin.close();

	// initialization
	for (int i=0; i<(1<<n); i++)
		for (int j=0; j<n; j++)
			dp[i][j]=INF;

	// dp[s][i]=0 where s={i}
	for (int i=0; i<n; i++)
		dp[1<<i][i]=0;

	// f(s,x): tsp of set s with c cities that finishes at x
	for (int s=2; s<(1<<n); s++)
		for (int x=0; x<n; x++)
			// if x is in set s
			if (s & (1<<x))
				// try all possible paths that finishes at i
				//    f(s,x) = min{ f(s-{x},i)+g[i][x] }
				for (int i=0; i<n; i++)
					if (g[i][x])
						dp[s][x]=min(dp[s][x],(short)(dp[s & ~(1<<x)][i]+g[i][x]));

	// search tsp for any starting vertex i
	short best=INF;
	for (int i=0; i<n; i++)
		best=min(best,dp[(1<<n)-1][i]);

	ofstream fout("tsp.out");
	if (best==INF)
		fout << "IMPOSSIBLE" << endl;
	else
		fout << best << endl;
	fout.close();
}

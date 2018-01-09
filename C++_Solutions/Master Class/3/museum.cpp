#include <cstdio>
#include <vector>

using namespace std;

#define FOR(i,a,b) for (int i=(a);i<=(b);i++)

typedef pair<int,int> PII;

#define M 10000
#define INF 1000000000

int N,K,X;
vector<PII> adj[M+1];
int sz[M+1];
int f[M+1][M+1][2];
int g[2][M+1][2];

void solve(int x, int p=-1)
{
	vector<PII> ch={{-1,-1}};
	int c=0;
	sz[x]=1;
	for (PII yt : adj[x]) if (yt.first!=p)
	{
		solve(yt.first, x);
		sz[x]+=sz[yt.first];
		ch.push_back(yt);
		c++;
	}
	FOR (k,0,K)
		for (int t=0; t<2; t++)
			f[x][k][t]=INF;
	if (c==0) {
		f[x][1][0]=0;
		f[x][1][1]=0;
	} else {
		FOR (k,0,K)
			for (int t=0; t<2; t++)
				g[0][k][t]=INF;
		g[0][0][0]=0;
		g[0][0][1]=0;
		int s=0;
		FOR (i,1,c) {
			FOR (k,0,K)
				for (int t=0; t<2; t++)
					g[i%2][k][t]=INF;
			int si=sz[ch[i].first];
			FOR (k,0,min(s,K)) {
				// t=0
				g[i%2][k][0]=min(g[i%2][k][0], g[(i-1)%2][k][0]);
				FOR (h,1,min(si,K-k)) {
					g[i%2][k+h][0]=min(g[i%2][k+h][0], g[(i-1)%2][k][0]+2*ch[i].second+f[ch[i].first][h][0]);
				}
				// t=1 (wildcard)
				g[i%2][k][1]=min(g[i%2][k][1], g[(i-1)%2][k][1]);
				FOR (h,1,min(si,K-k)) {
					int score = min(g[(i-1)%2][k][1]+2*ch[i].second+f[ch[i].first][h][0], // don't use it
					                g[(i-1)%2][k][0]+1*ch[i].second+f[ch[i].first][h][1]); // use it
					g[i%2][k+h][1]=min(g[i%2][k+h][1], score);
				}
			}
			s+=si;
		}

		FOR (k,1,min(sz[x],K))
			for (int t=0; t<2; t++)
				f[x][k][t]=g[c%2][k-1][t];
	}
}

int main()
{
	scanf("%d %d %d",&N,&K,&X);
	for (int i=0; i<N-1; i++) {
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		adj[a].push_back({b,c});
		adj[b].push_back({a,c});
	}
	solve(X);
	printf("%d\n",f[X][K][1]);
}

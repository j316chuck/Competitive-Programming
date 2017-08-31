#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define MAXN 100005
using namespace std;
vector < int > G[MAXN];
int N,Q;
int depth[MAXN];
int next[MAXN][18];
void BFS()
{
	queue < int > Q;
	vector < int > :: iterator it;
	int x;
	Q.push(1);
	while(!Q.empty())
	{
		x = Q.front(); Q.pop();
		for( it = G[x].begin(); it != G[x].end(); ++it )
			if( *it != next[x][0] )
			{
				Q.push(*it);
				next[*it][0] = x;
				depth[*it] = depth[x] + 1;
			}
	}
}
int LCA(int a,int b)
{
	if( depth[a] < depth[b] ) swap(a,b);
	
	int i,k = depth[a] - depth[b];
	
	for(i=0; k; i++,k>>=1)
		if( k&1 )
			a = next[a][i];
	
	if( a == b ) return a;
			
	TFOR(i,17,0)
		if( next[a][i] != next[b][i] )
		{
			a = next[a][i];
			b = next[b][i];
		}
		
	return next[a][0];
	
}
int main()
{
	freopen( "distance.in" , "r" , stdin );
	freopen( "distance.out" , "w" , stdout );
	int a,b,i,j;
	scanf("%d %d" , &N , &Q );
	FOR(i,1,N-1)
	{
		scanf("%d %d" , &a , &b );
		G[a].push_back(b);
		G[b].push_back(a);
	}
	
	BFS();
	
	FOR(j,1,17)
		FOR(i,1,N)
			next[i][j] = next[ next[i][j-1] ][j-1];
	
	while(Q--)
	{
		scanf("%d %d" , &a , &b );
		printf("%d\n" , depth[a] + depth[b] - 2 * depth[ LCA(a,b) ] );
	}
	
	return 0;
}

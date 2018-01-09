#include <stdio.h>
#include <stdlib.h>

#define	maxN 100001

using namespace std;

typedef	struct	LList
{
	int	to;
	LList *next;
}LList;

typedef enum Paletta {White, Gray, Black, Blue} Paletta;
LList* G[maxN];

int m,n, r;
int inDeg [maxN];	//node in-degree
int outDeg [maxN];	//node out-degree
Paletta Color [maxN];	//DFS coloring
int Parent [maxN];	//DFS spanning	tree	representation
int B[maxN];	//B[p]	is	the highest node in the DFS	tree
//that	is	reachable from p by 1 or 0	back edge
int H[maxN];	//H[p]	is	the highest node in the DFS	tree
//that	is	reachable from p
int TRn[maxN];	//# reachable nodes in the DFS tree
int	Sol [maxN];	// solution	edges :	(p, Sol [p]),	Sol [p]!=0

void ReadIn()
{
	int p, q;
	LList* pq;
	scanf (" %d %d %d", &n,&m,&r );
	for	(p=1; p<=n;p++)
	{
		Color [p]=White; G[p]=NULL;
		inDeg [p]=0; outDeg [p]=0;
		Sol [p]=0;
	}

	for	( int	i =1; i<=m; i++)
	{
		scanf (" %d %d", &p,&q );
		pq = new LList;
		pq->to=q; pq->next=G[p];
		G[p]=pq;
		outDeg [p]++; inDeg [q]++;
	}
}

void DFS1( int p)
{
	Color [p]=Gray;
	LList* pq=G[p];
	int q, rep=0;
	B[p]=p;

	while (pq!=NULL)
	{
		q=pq->to;
		if ( Color [q]==White )
		{
			Parent [q]=p;
			DFS1(q );
			if (B[q]!=q && B[q]!=p) B[p]=B[q];
			rep+=TRn[q];
		}
		else if ( Color [q]==Gray)
		{ //p->q back edge
			B[p]=q;
			int x=p;
			while (x!=q)
			{	//"removing" edges that are in the
				inDeg [x]--;	// cycle p~>q->p
				outDeg [x]--;
				x=Parent [x];
			}
			inDeg [x]--; outDeg [x]--;
		}
		pq=pq->next;
	}
	TRn[p]=1+rep;
}//DFS1

void DFS2( int p)
{
	Color [p]=Black;
	LList* pq=G[p];
	int q;
	if (B[p]==p)
		H[p]=p;
	else
		H[p]=H[B[p]];

	while (pq!=NULL)
	{
		q=pq->to;
		if ( Color [q]==Gray)
		DFS2(q );
		pq=pq->next;
	}
}//DFS2

int main()
{
	ReadIn ();
	DFS1( r );
	DFS2( r );

	for	( int p=1;p<n;p++)
		printf ("%d ",TRn[H[p]] );
	printf ("%d\n",TRn[H[n]] );

	int	Soln=0;
	for	( int p=1;p<=n;p++) if (inDeg [p]==1 && outDeg [p]==0)
	{
		int x=p;

		do
		{
			Color [x]=Blue;
			x=Parent [x];
		}
		while ( Color [x]==Black && inDeg [x]!=0);

		//x is	either	root	of a tree or contained	in a cycle
		Color [x]=Blue;
		Sol [p]=x;
		Soln++;
	}

	printf ("%d\n", Soln );
/*
	for	( int	i =1;i<=n; i++)
		if ( Sol [i]>0)
			printf ("%d %d\n", i, Sol [i] );
*/
}

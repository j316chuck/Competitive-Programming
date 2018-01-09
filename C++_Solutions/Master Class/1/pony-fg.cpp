/*
ID: fatih
PROB: pony
LANG: C++
*/

// all shortest path
// O(N^3)
#include <iostream>
#include <algorithm>
#include <iomanip>

#define INF 1000000000000000000ll
#define EPS 0.00000001

using namespace std;

void solve(int t)
{
	// read input
	int n,q;
	cin >> n >> q;
	long long e[n],s[n],d[n][n];
	for (int i=0; i<n; i++)
		cin >> e[i] >> s[i];
	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
			cin >> d[i][j];

	// floyd warshall on distances
	for (int k=0; k < n; k++)
		for (int i=0; i < n; i++)
			if (d[i][k] > 0)
				for (int j=0; j < n; j++)
					if (d[k][j] > 0)
						if (d[i][j] == -1 || (d[i][j] > d[i][k]+d[k][j]))
							d[i][j]=d[i][k]+d[k][j];
	// distance from vertex i to i should be 0
	for (int i=0; i < n; i++)
		if (d[i][i]>0) d[i][i]=0;

	// initialize times
	double mat[n][n];
	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
			mat[i][j]=INF;

	// transform distances to time
	// calculate the time a horse at city i can go to city j
	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
		{
			double t=(double)d[i][j]/s[i];
			if (d[i][j]!=-1 && e[i]>=d[i][j] && mat[i][j]>t)
				mat[i][j]=t;
		}

	// floyd-warshall
	for (int k=0; k < n; k++)
		for (int i=0; i < n; i++)
			if (mat[i][k] > 0)
				for (int j=0; j < n; j++)
					if (mat[k][j] > 0)
						if ((mat[i][j] < EPS && mat[i][j] > -EPS) || (mat[i][j] > mat[i][k]+mat[k][j]))
							mat[i][j]=mat[i][k]+mat[k][j];
	// time from city i to i should be 0
	for (int i=0; i < n; i++) mat[i][i]=0;

	// not reachable city should not be a case
	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
			if (mat[i][j]==INF) mat[i][j]=-1;

	// format output
	cout.setf(ios::fixed,ios::floatfield);
	cout << "Case #" << setprecision(0) << t << ": ";
	cout << setprecision(6);

	for (int i=0,u,v; i<q; i++)
	{
		cin >> u >> v;
		cout << mat[u-1][v-1] << " ";
	}
	cout << endl;
}

int main()
{
	int t;
	cin >> t;

	for (int i=1; i<=t; i++)
		solve(i);
}

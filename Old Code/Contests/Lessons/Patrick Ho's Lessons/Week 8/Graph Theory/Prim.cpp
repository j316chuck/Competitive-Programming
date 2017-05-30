/*
ID: peiqistar1
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

const double Pi=acos(-1.0);
typedef long long LL;

#define Set(a, s) memset(a, s, sizeof (a))
#define Rd(r) freopen(r, "r", stdin)
#define Wt(w) freopen(w, "w", stdout)

using namespace std;

int n; // total nodes

int weight[100][100];
char inTree[100]; /* inTree[i] is 1 if the node i is already in the minimum
spanning tree; 0 otherwise*/

int d[100]; /* d[i] is the distance between node i and the minimum spanning
tree; this is initially infinity (INT_MAX); if i is already in
the tree, then d[i] is undefined;
this is just a temporary variable. It's not necessary but speeds
up execution considerably (by a factor of n) */

int whoTo[100]; /* whoTo[i] holds the index of the node i would have to be
linked to in order to get a distance of d[i] */

/* updateDistances(int target)
should be called immediately after target is added to the tree;
updates d so that the values are correct (goes through target's
neighbours making sure that the distances between them and the tree
are indeed minimum)
 */
void updateDistances(int target)
{
	for (int i = 0; i < n; ++i)
	{
		if ((weight[target][i] != 0) && (d[i] > weight[target][i]))
		{
			d[i] = weight[target][i];
			whoTo[i] = target;
		}
	}
}

int main(int argc, char *argv[])
{
	Rd("prim.in");

	scanf("%d", &n);

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			scanf("%d", &weight[i][j]);

	// Using Prim algorithm

	/* Initialise d with infinity */
	for (int i = 0; i < n; ++i)
		d[i] = INT_MAX;

	/* Mark all nodes as NOT being in the minimum spanning tree */
	for (int i = 0; i < n; ++i)
		inTree[i] = 0;

	/* Add the first node to the tree */
	printf("Adding node %d\n", 1);

	inTree[0] = 1;

	updateDistances(0);

	int total = 0;

	int treeSize;

	for (treeSize = 1; treeSize < n; ++treeSize) {

		/* Find the node with the smallest distance to the tree */
		int min = -1;

		for (int i = 0; i < n; ++i)
		{
			if (!inTree[i])
				if ((min == -1) || (d[min] > d[i]))
					min = i;
		}

		/* And add it */
		printf("Adding edge %d-%d\n", whoTo[min] + 1, min + 1);
		inTree[min] = 1;
		total += d[min];

		updateDistances(min);

	}

	printf("Total distance: %d\n", total);

	return 0;

}



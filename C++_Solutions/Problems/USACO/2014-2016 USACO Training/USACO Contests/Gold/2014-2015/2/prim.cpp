(Analysis by Nick Wu and Mark Gordon)
Let us reformulate this problem as a graph problem - we have N vertices, and every pair of vertices has an edge between them with some weight. All vertices start out being uncolored - in a given turn, we pick an edge between two uncolored vertices and we must color one of the vertices - we can pick which vertex to color. Our goal is to maximize the sum of the weights of the edges that we choose. Note that this sounds similar to Kruskal's minimum spanning tree algorithm.

Indeed we can observe that the final tournament structure forms a tree over all teams with the sum of edge weights giving the number of points scored. Therefore this problem is equivalent to the maximum spanning tree problem which is the same as the minimum spanning tree problem with negated edge weights.

Because the graph is dense it is preferable to use Prim's algorithm for computing the maximum spanning tree. Note that we should use the O(V2)O(V2) version of Prim's rather than the version that makes use of a heap. Kruskal's algorithm, on the other hand, requires the edges to be sorted by edge weight which can be too computationally intensive for some implementations.

Because edge weights can be very large, the answer must be stored in a 64-bit integer.

Here is Mark Gordon's code implementing Prim's algorithm:

#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int main() {
  freopen("superbull.in", "r", stdin);
  freopen("superbull.out", "w", stdout);

  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  long long result = 0;
  vector<bool> used(N, false);
  vector<int> D(N, 0);
  for (int i = 0; i < N; i++) {
    /* Find the index, j, of the 'furthest' node from the current spanning tree. */
    int j = -1;
    for (int k = 0; k < N; k++) {
      if (used[k]) continue;
      if (j == -1 || D[k] > D[j]) {
        j = k;
      }
    }

    /* Update the result and 'relax' the edges out of vertex j. */
    result += D[j];
    used[j] = true;
    for (int k = 0; k < N; k++) {
      D[k] = max(D[k], A[j] ^ A[k]);
    }
  }

  cout << result << endl;
  return 0;
}

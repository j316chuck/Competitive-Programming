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

using namespace std;


const int MAXN = 1010;
const int INF = 1 << 29;


void setmin(int &a, int b) {
	if (b < a) a = b;
}

typedef pair<int, int> pii;
typedef pair<pii, int> edge;

int N, M;
vector<edge> edgelist;
int dist[MAXN][MAXN]; // matrix form

// O(n^3) all pairs
void floydwarshall() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < i; j++) {
			dist[i][j] = dist[j][i] = INF;
		}
	}
	for (int i = 0; i < N; i++) {
		dist[i][i] = 0;
	}
	for (int i = 0; i < M; i++) {
		int a = edgelist[i].first.first;
		int b = edgelist[i].first.second;
		int d = edgelist[i].second;
		dist[a][b] = d;
	}
	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				// relax distance
				setmin(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
}

// O(nm) single source, works on negative weight edges, return false if there is a negative weight cycle
bool bellmanford(int s, int tdist[MAXN]) {
	for (int i = 0; i < N; i++) {
		tdist[i] = INF;
	}
	tdist[s] = 0;
	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < M; j++) {
			int a = edgelist[j].first.first;
			int b = edgelist[j].first.second;
			int d = edgelist[j].second;
			// relax edge
			setmin(tdist[a], tdist[b] + d);
		}
	}
	for (int i = 0; i < M; i++) {
		int a = edgelist[i].first.first;
		int b = edgelist[i].first.second;
		int d = edgelist[i].second;
		// relax edge
		if (tdist[a] + d < tdist[b]) return false;
	}
	return true;
}

// O(m logn) single source
vector<pii> adj[MAXN];
void dijkstra(int s, int tdist[MAXN]) {
	for (int i = 0; i < M; i++) {
		int a = edgelist[i].first.first;
		int b = edgelist[i].first.second;
		int d = edgelist[i].second;
		adj[a].push_back(pii(b, d));
	}
	for (int i = 0; i < N; i++){
		tdist[i] = INF;
	}
	set<pii> pq;
	tdist[s] = 0;
	pq.insert(pii(tdist[s], s));
	while (pq.size()) {
		int cur = pq.begin()->second;
		pq.erase(pq.begin());
		for (int i = 0; i < adj[cur].size(); i++) {
			int nxt = adj[cur][i].first;
			int t = tdist[cur] + adj[cur][i].second;
			if (t < tdist[nxt]) {
				// erase previous
				pq.erase(pii(tdist[nxt], nxt));
				tdist[nxt] = t;
				// insert new
				pq.insert(pii(tdist[nxt], nxt));
			}
		}
	}
}

int main() {

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b, d;
		cin >> a >> b >> d;
		a--; b--;
		edgelist.push_back(edge(pii(a, b), d));
	}
	cout << "floyd-warshall" << endl;
	floydwarshall();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (j) cout << ' ';
			cout << dist[i][j];
		}
		cout << endl;
	}
	cout << "bellman-ford" << endl;
	for (int i = 0; i < N; i++) {
		bellmanford(i, dist[i]);
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (j) cout << ' ';
			cout << dist[i][j];
		}
		cout << endl;
	}
	cout << "dijkstra" << endl;
	for (int i = 0; i < N; i++) {
		dijkstra(i, dist[i]);
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (j) cout << ' ';
			cout << dist[i][j];
		}
		cout << endl;
	}
}

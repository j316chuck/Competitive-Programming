// O(m logn) single source
vector<pii> adj[MAXN];
void dijkstra(int s, int tdist[MAXN]) {
	for (int i = 0; i < M; i++) {
		int a = edgelist[i].first.first;
		int b = edgelist[i].first.second;
		int d = edgelist[i].second;
		adj[a].push_back(pii(b, d));
	}
	for (int i = 0; i < N; i++) {
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


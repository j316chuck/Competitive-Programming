void bfs(int n) {
    vector<int> D(n);
    queue<int> q;
    memset(D, -1, sizeof(D));
    q.push(u);
    D[u] = 0;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int i = 0; i < G[v].size(); i++) {
            int nv = G[v][i];
            if (D[nv] == -1) {
                D[nv] = D[v] + 1;
                q.push(nv);
            }
        }
    }
}

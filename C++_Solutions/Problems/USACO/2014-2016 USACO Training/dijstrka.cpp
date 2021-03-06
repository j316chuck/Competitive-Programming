queue<int> q;
memset(D, -1, sizeof(D));
q.push(u);
D[u] = 0;
while (!q.empty()) {
  int v = q.front();
  q.pop();
  for (int i = 0; i < E[v].size(); i++) {
    int nv = E[v][i];
    if (D[nv] == -1) {
      D[nv] = D[v] + 1;
      q.push(nv);
    }
  }
}
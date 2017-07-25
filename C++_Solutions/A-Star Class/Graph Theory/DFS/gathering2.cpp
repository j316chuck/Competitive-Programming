#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int N;
long long cost[1<<17], cows[1<<17], down[1<<17], up[1<<17];
vector<vector<long long> > e, w;

long long dfs1(int cur, int prev) {
  down[cur] = cows[cur];
  long long c = 0;
  for(int i = 0; i < e[cur].size(); i++) {
    if(e[cur][i] == prev) continue;
    c += dfs1(e[cur][i], cur);
    c += down[e[cur][i]]*w[cur][i];
    down[cur] += down[e[cur][i]];
  }
  return c;
}

long long dfs2(int cur, int prev) {
  long long c = cost[cur];
  //cout << cost[cur] << ' ' << cur << endl;
  for(int i = 0; i < e[cur].size(); i++) {
    if(e[cur][i] == prev) continue;
    cost[e[cur][i]] = cost[cur]-down[e[cur][i]]*w[cur][i]+up[e[cur][i]]*w[cur][i];
    c = min(c, dfs2(e[cur][i], cur));
  }
  return c;
}

int main() {
    freopen("gathering.in", "r", stdin);
  //FILE* in = fopen("gathering.in", "r");
  //FILE* out = fopen("gather.out", "w");

  scanf("%d", &N);
  e.resize(N); w.resize(N);
  for(int i = 0; i < N; i++) scanf("%lld", &cows[i]);
  for(int i = 0; i < N-1; i++) {
    long long a, b, c;
    scanf("%lld %lld %lld", &a, &b, &c);
    a--; b--;
    e[a].push_back(b); w[a].push_back(c);
    e[b].push_back(a); w[b].push_back(c);
  }

  cost[0] = dfs1(0, -1);
  //cout << cost[0] << endl;
  for(int i = 0; i < N; i++) up[i] = down[0] - down[i];
  printf("%lld\n", dfs2(0, -1));

  //close(in);
  //fclose(out);
}

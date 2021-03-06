int P[2010*2010];

int find(int x) {
  return x == P[x] ? x : P[x] = find(P[x]);
}

bool merge(int x, int y) {
  int X = find(x);
  int Y = find(y);
  if (X == Y) return false;
  P[X] = P[Y] = P[x] = P[y] = rand() % 2 ? X : Y;
  return true;
}
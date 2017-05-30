#include <iostream>
#include <fstream>
#include <string>
#define MAX_N 100
using namespace std;

string A[MAX_N];
int N;
bool valid[256][256];
bool visited[MAX_N][MAX_N];

void visit(int i, int j)
{
  if (visited[i][j]) return;
  visited[i][j] = true;
  if (i > 0   && valid[A[i-1][j]][A[i][j]]) visit(i-1, j);
  if (j > 0   && valid[A[i][j-1]][A[i][j]]) visit(i, j-1);
  if (i < N-1 && valid[A[i+1][j]][A[i][j]]) visit(i+1, j);
  if (j < N-1 && valid[A[i][j+1]][A[i][j]]) visit(i, j+1);
}

int solve(void)
{
  int count = 0;
  for (int i=0; i<N; i++)
    for (int j=0; j<N; j++)
      visited[i][j] = false;
  for (int i=0; i<N; i++)
    for (int j=0; j<N; j++)
      if (!visited[i][j]) {
	count++;
	visit(i,j);
      }
  return count;
}

int main(void)
{

  cin >> N;
  for (int i=0; i<N; i++) cin >> A[i];


  valid['R']['R'] = valid['G']['G'] = valid['B']['B'] = true;
  int regions_human = solve();
  valid['R']['G'] = valid['G']['R'] = true;
  int regions_cow = solve();


  cout << regions_human << " " << regions_cow << "\n";

  return 0;
}

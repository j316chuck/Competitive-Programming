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
#define MAX 1001
using namespace std;

void bfs(int source)  {
  seen[source] = 1;
  queue<int> Q;
  Q.push(source);
  while(not Q.empty())  {
    int node = Q.top();
    Q.pop();
    for(int next: graph[node])  {
      if(not seen[next])  {
        Q.push(next);
        seen[next] = 1;
      }
    }
  }
}
int main(){


}

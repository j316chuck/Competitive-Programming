/*
ID: j316chuck
PROG: numtri
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
#define MAX 1001
using namespace std;

int maximum=0; int a[MAX][MAX];

void dfs(int i,int j,int end,int sum)
{
 if(i<=end)
 {
      sum += a[i][j];
      dfs(i+1,j,end,sum);
      dfs(i+1,j+1,end,sum);
 }
 else
 {
      if(sum>maximum)
      maximum= sum;

 }

}
int main() {
Rd("numtri.in");
Wt("numtri.out");
int r,i,j;

cin>>r;
for(i = 1;i<=r;i++)
 for(j = 1;j<=i;j++)
    cin>>a[i][j];

dfs(1,1,r,0);

cout<<maximum<<endl;
}

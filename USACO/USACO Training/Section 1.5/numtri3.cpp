
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
int N;
int dp[1001][1001];
int dfs(int i,int j,int end)
{


}
int main()
{
     Rd("numtri.in");
    //Wt("numtri.out");
    cin>>N;
    for(int i=0; i <N; i++)
    {
        vector<int> random;
        for(int j=0; j<=i; j++)
        {
            int a;
            cin>>a;
            random.push_back(a);
            visited[i][j]=-1;
        }
        graph.push_back(random);
    }



    dp(0,0,sum);
}

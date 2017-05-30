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

int dp[1000][1000], sum[1000][1000];

int main()
{
    Rd("numtri.in");
    Wt("numtri.out");
    int N;
    cin>>N;

    for(int i =0; i < N; i++)
        for(int j =0; j <= i; j++)
            cin>>dp[i][j];

    sum[0][0]=dp[0][0];

    for(int i=1; i < N; i++)
    {
        for(int j=0; j<=i; j++)
        {
            if(j==0||sum[i-1][j]>sum[i-1][j-1])
               sum[i][j]=dp[i][j]+sum[i-1][j];
            else
                sum[i][j]=dp[i][j]+sum[i-1][j-1];
        }
    }
    int maximum=0;
    for(int i=0; i <N; i++)
    {
        if(sum[N-1][i]>maximum)
        maximum=sum[N-1][i];
    }
    cout<<maximum<<endl;
}

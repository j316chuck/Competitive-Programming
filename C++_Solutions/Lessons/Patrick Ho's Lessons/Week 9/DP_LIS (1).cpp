/*
ID: peiqistar1
PROG:
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

using namespace std;

int a[1001]; // input
int f[1001];  // each substructure LIS
int prev[1001]; // position
vector<int> v; // result position in reversed order

int LIS_Length(int n)
{
	f[1] = 1;
	prev[1] = -1;
    for(int i=2;i<=n;i++)
    {
		prev[i] = -1;
        for(int j=1;j<i;j++)
        {
            if( (f[j]>f[i]) && (a[j]<=a[i]) ) {
                f[i]=f[j];
                prev[i] = j;
            }
        }
        f[i]++;
    }
    int maxn=0, maxi = -1;
    for(int i=1;i<=n;i++)
    {
        if(f[i]>maxn) {
            maxn=f[i];
            maxi = i;
        }
    }

    while (maxi != -1) {
    	v.push_back(maxi);
    	maxi = prev[maxi];
    }

    return maxn;
}

int main()
{
	Rd("data.in");

    int iN;

    cin>>iN;

    for(int i=1; i<=iN; i++)
    	cin>>a[i];

    int iLen=LIS_Length(iN);

    cout<< iLen<<endl;

    // for each a[i], max no
    for (int i=iLen-1; i>=0; i--)
    {
   	    cout << a[v[i]] << " ";
    }
    cout << endl;
    return 0;
}

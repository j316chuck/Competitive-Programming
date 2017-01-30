/*
ID:
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
#include <cstdlib>

const double Pi=acos(-1.0);
typedef long long LL;

#define Set(a, s) memset(a, s, sizeof (a))
#define Rd(r) freopen(r, "r", stdin)
#define Wt(w) freopen(w, "w", stdout)

using namespace std;

int iX[1024];
int iY[1024];

int main (int argc, char ** argv)
{
	int iN;
	scanf("%d", &iN);
	for (int i=0; i<2*iN; i++)
	{
		scanf("%d %d", &iX[i], &iY[i]);
	}
	for(int iA=0; iA<=100; iA++)
	{
		for (int iB=-100; iB<=100; iB++)
		{
			int iNumA = 0;
			int iNumB = 0;
			for (int i=0; i<2*iN; i++)
			{
				if (iA * iX[i] + iB * iY[i]>0)
					iNumA++;
				else if (iA * iX[i] + iB * iY[i]<0)
					iNumB++;
			}
			if (iNumA == iN && iNumB == iN)
			{
				cout << iNumA << endl;
				printf("%d %d\n", iA, iB);
				return 0;
			}
		}
	}
	return 0;
}






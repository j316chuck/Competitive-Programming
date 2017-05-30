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

int iA[4][4];
int iGood=0;

bool Check(int r1, int r2, int r3, int r4)
{
	if (r1==r2 || r1==r2 || r1==r3 || r1==r4 ||
			r2==r3 || r2==r4 || r3== r4)
		return false;
	if (r1==0 && (r2==1 || r3==2 || r4==3))
		return false;
	if (r1==1 && (r2==0 || r2==2 || r3==3))
		return false;
	if (r1==2 && (r2==1 || r2==4 || r3==0))
		return false;
	if (r1==3 && (r2==2 || r3==1 || r4==0))
		return false;
	if (r2==0 && (r3==1 || r4==2))
		return false;
	if (r2==1 && (r3==2 || r3==0 || r4==3))
		return false;
	if (r2==2 && (r3==3 || r3==1))
		return false;
	if (r2==3 && (r3==2 || r4==1))
		return false;
	if (r3==1 && (r4==2 || r4==0))
		return false;
	if (r3==2 && (r4==1 || r4==3))
		return false;
	return true;
}

void PrintOut()
{
	iGood++;
	printf("Solution:%d\n", iGood);
	for(int i=0; i<4; i++)
	{
		for(int j=0; j<4; j++)
		{
			printf("%3d", iA[i][j]);
		}
		printf("\n");
	}
}

int main (int argc, char ** argv)
{
	int iNum=0;
	/* total: 256
	for(int r1=0; r1<4; r1++)
	{
		memset(iA[0], 0, 4*sizeof(int));
		iA[0][r1] = 1;
		for(int r2=0; r2<4; r2++)
		{
			memset(iA[1], 0, 4*sizeof(int));
			iA[1][r2] = 1;
			for(int r3=0; r3<4; r3++)
			{
				memset(iA[2], 0, 4*sizeof(int));
				iA[2][r3] = 1;
				for(int r4=0; r4<4; r4++)
				{
					memset(iA[3], 0, 4*sizeof(int));
					iA[3][r4] = 1;
					iNum ++;
					if (Check(r1,r2,r3,r4))
						PrintOut();
				}
			}
		}
	}
	*/

	// set condition check, cut step to 24
	for(int r1=0; r1<4; r1++)
	{
		memset(iA[0], 0, 4*sizeof(int));
		iA[0][r1] = 1;
		for(int r2=0; r2<4; r2++)
		{
			if(r2 == r1)
				continue;
			memset(iA[1], 0, 4*sizeof(int));
			iA[1][r2] = 1;
			for(int r3=0; r3<4; r3++)
			{
				if(r3==r1 || r3 == r2)
					continue;
				memset(iA[2], 0, 4*sizeof(int));
				iA[2][r3] = 1;
				for(int r4=0; r4<4; r4++)
				{
					if(r4==r1 || r4==r2 || r4==r3)
						continue;
					memset(iA[3], 0, 4*sizeof(int));
					iA[3][r4] = 1;
					iNum ++;
					if (Check(r1,r2,r3,r4))
						PrintOut();
				}
			}
		}
	}
	cout << "total step: "<<iNum<<endl;
	return 0;
}






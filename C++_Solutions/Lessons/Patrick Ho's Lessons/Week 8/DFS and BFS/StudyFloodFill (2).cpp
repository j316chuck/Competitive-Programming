/*
ID:
PROG: StudyFloodFill
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

#define XSIZE 10
#define YSIZE 20

char cA[XSIZE][YSIZE];

void Init()
{
	Set(cA, '-');
	for(int i=1; i<YSIZE-1; i++)
	{
		cA[1][i] = '*';
		for(int j=2; j<XSIZE; j++)
		{
			if (i==j)
			{
				cA[i][j] = '*';
				cA[i][YSIZE-1-j] = '*';
			}
		}
	}
	/*
	// A 3,8
	cA[3][8] = 'A';
	// B 8,17
	cA[8][17] = 'B';
	// C 5,12
	cA[5][12] = 'C';
	 */
}

void Print()
{
	for(int i=0; i<XSIZE; i++)
	{
		for(int j=0; j<YSIZE; j++)
			cout<<cA[i][j];
		cout << '\n';
	}
}

void FloodRecur(int x,int y,char fill_color, char orig_color)
{
	if (x<0 || x>=XSIZE || y<0 || y>=YSIZE)
		return; // check boundary

	if (cA[x][y] == orig_color) // not filled
	{
		cA[x][y] = fill_color;
		// four points
		FloodRecur(x+1, y, fill_color, orig_color);
		FloodRecur(x-1, y, fill_color, orig_color);
		FloodRecur(x, y+1, fill_color, orig_color);
		FloodRecur(x, y-1, fill_color, orig_color);
	}
}

void FloodDFSIter(int x, int y, char fillColor, char origColor)
{
	stack< pair<int, int> > S;
	S.push(make_pair(x,y));
	while(!S.empty())
	{
		pair<int, int> a = S.top();
		S.pop();
		int i=a.first;
		int j=a.second;
		cA[i][j] = fillColor;
		if(i+1 < XSIZE && cA[i+1][j] == origColor)
			S.push(make_pair(i+1, j));
		if(i-1 >= 0 && cA[i-1][j] == origColor)
			S.push(make_pair(i-1, j));
		if(j+1 < YSIZE && cA[i][j+1] == origColor)
			S.push(make_pair(i, j+1));
		if(j-1 >= 0 && cA[i][j-1] == origColor)
			S.push(make_pair(i, j-1));
	}
}

void FloodScanline(int x, int y, char fillColor, char origColor)
{
	stack< pair<int, int> > S;
	S.push(make_pair(x,y));
	while(!S.empty())
	{
		pair<int, int> a = S.top();
		S.pop();
		int i=a.first;
		int j=a.second;
		printf("i:%d, j:%d\n", i, j);
		//fill Y direction
		//   does up
		int yui = j;
		for(; yui<YSIZE; yui++)
		{
			if (cA[i][yui] == origColor)
				cA[i][yui] = fillColor;
			else
				break;
		}
		//   does down
		int ydi = j-1;
		for(; ydi>=0; ydi--)
		{
			if (cA[i][ydi] == origColor)
				cA[i][ydi] = fillColor;
			else
				break;
		}
		ydi++;

//		printf("   ydi:%d, yui:%d\n",
//				ydi, yui);

		// move scanline right
		for(int yi=ydi; yi<yui; yi++)
		{
			if(i+1 < XSIZE &&
					cA[i+1][yi] == origColor)
				S.push(make_pair(i+1, yi));
		}
		// move scanline right
		for(int yi=ydi; yi<yui; yi++)
		{
			if(i-1 >= 0 && cA[i-1][yi] == origColor)
				S.push(make_pair(i-1, yi));
		}
	}
}

int main (int argc, char ** argv)
{
	Init();
	cout << "Original:\n";
	Print();

	// fill A
	//FloodRecur(3, 8, 'A', '-');
	//cout << "FloodRecur:\n";
	//Print();

	// FloodDFSIteration
	//FloodDFSIter(3, 8, 'A', '-');
	//cout << "FloodDFSIter:\n";
	//Print();

	// FloodScanline
	FloodScanline(3, 8, 'A', '-');
	cout << "FloodScanline:\n";
	Print();

	// check A,B in same area
	if (cA[3][8] == cA[8][17])
		cout << "A,B is in same area\n";
	else
		cout << "A,B is not in same area\n";

	// check A,C in same area
	if (cA[3][8] == cA[5][12])
		cout << "A,C is in same area\n";
	else
		cout << "A,C is not in same area\n";

	return 0;
}



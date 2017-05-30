/*
ID:
PROG: StudyFloodFillDistance
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
int Dist[XSIZE][YSIZE];

void Flood(int x, int y, int d, char original_color)
{
	if (x<0 || x>=XSIZE || y<0 || y>=YSIZE)
		return; // check boundary

	if (cA[x][y] == original_color && d < Dist[x][y])
    {
            Dist[x][y] = d;
            Flood(x+1, y, d+1, original_color);
            Flood(x-1, y, d+1, original_color);
            Flood(x, y+1, d+1, original_color);
            Flood(x, y-1, d+1, original_color);
    }
}

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
		{
			if (Dist[i][j]==999)
				cout << 0;
			else
			    cout<<Dist[i][j];
		}
		cout << '\n';
	}
}

int main (int argc, char ** argv)
{
	Init();
    for (int i=0; i<XSIZE; i++)
        for (int j=0; j<YSIZE; j++)
            Dist[i][j] = 999;

    Flood(3, 8, 0, '-');

    Print();

    cout << "Distance:"<<
		Dist[5][12] - Dist[3][8] << "\n";
}


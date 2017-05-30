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
const int INF = 1<<29;
using namespace std;

int main()
{

    int A[9][9];
    Set(A, 0);
    for(int i =0; i < 9; i++)
    {
        for(int j = 0; j < i; j++)
        {
            A[i][j]=A[j][i]=INF;
        }
    }

    for(int i = 0; i <9;i++)
    {
        A[i][i]=0;
    }
    A[0][1]=2;
    A[0][2]=4;
    A[0][3]=2;
    A[1][4]=7;
    A[1][5]=4;
    A[1][6]=6;
    A[2][4]=3;
    A[2][5]=2;
    A[2][6]=4;
    A[3][4]=4;
    A[3][5]=1;
    A[3][6]=5;
    A[4][7]=1;
    A[4][8]=4;
    A[5][7]=6;
    A[5][8]=3;
    A[6][7]=3;
    A[6][8]=3;
    A[7][9]=3;
    A[8][9]=4;

    for(int k = 0; k < 9; k++)
        for(int i = 0; i < 9; i++)
            for(int j = 0; j < 9; j++)
            {
                A[i][j]=min(A[i][j], A[i][k]+A[k][j]);
            }


    cout<<A[0][9]<<endl;
    return 0;
}

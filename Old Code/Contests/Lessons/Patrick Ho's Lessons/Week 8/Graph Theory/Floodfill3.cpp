/*
assdxzID:
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


int mygraph[3][3];
int counter;
/*bool Floodfill(int i , int j)
{
    if(mygraph[i][j]!=1||i<0||j<0||i>3||j>3)
        return false;

    mygraph[i][j]=2;
    if(Floodfill(i+1, j)||Floodfill(i-1,j)||Floodfill(i,j-1)||Floodfill(i,j+1))
    {
        counter--;
    }


    Floodfill(i+1, j);
    Floodfill(i-1, j);
    Floodfill(i, j-1);
    Floodfill(i, j+1);

    return true;
}*/
int main()
{
    //Rd("Floodfill.in");
    //Wt("Floodfill.out");
        counter=0;
    for(int i = 0; i < 4; i++)
    {
        for(int k = 0; k < 4; k++)
        {
            int n;
            cin>>n;
            if(n==1)
                counter++;
           mygraph[i][k]=n;
        }
    }
cout<<counter<<endl;
}

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

vector< vector<int> > mygraph;
int counter;
/*void Floodfill(int x, int y)
{
    if(x>=4||y>=4||x<0||y<0||mygraph[x][y]!="1")
        return;

    counter--;
    mygraph[x][y]="2";
    Floodfill(x-1, y);
    Floodfill(x+1, y);
    Floodfill(x, y-1);
    Floodfill(x, y+1);
}*/
/*
void floodFill(int i, int j) {
    if (mygraph[i][j] != "1")
        return;
    mygraph[i][j] = "2";
    counter++;
    floodFill(i - 1, j);
    floodFill(i + 1, j);
    floodFill(i, j + 1);
    floodFill(i, j - 1);
}*/

void Floodfill(int i , int j)
{
    if(mygraph[i][j]!=1||i<0||j<0||i>3||j>3)
        return;


    if(mygraph[i][j+1]==1||mygraph[i][j-1]==1||mygraph[i+1][j]==1||mygraph[i-1][j]==1)
    {
        counter--;
    }
    mygraph[i][j]=2;
    Floodfill(i+1, j);
    Floodfill(i-1, j);
    Floodfill(i, j-1);
    Floodfill(i, j+1);

    return;
}
int main()
{
    Rd("Floodfill.in");
    Wt("Floodfill.out");
    counter =0;
    for(int i = 0; i < 4; i++)
    {
        vector<int> myline;
        for(int k = 0; k < 4; k++)
        {
          int a;
            cin>>a;
            if(a==1)
            {
                counter++;
            }
            myline.push_back(a);
        }
        mygraph.push_back(myline);
    }
    for(int i = 0; i < 4; i++)
    {
        for(int k = 0; k < 4; k++)
        {
            Floodfill(i,k);
        }
    }

    cout<<counter<<endl;

}

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
#include <iostream>
using namespace std;

class maze
{
public:
    bool bvisited;
    bool bwall[4];
};

int iNx, iNy; //current board size
int iSx, iSy; //start
int iEx, iEy; //end

maze myMaze[100][100];
vector < pair<int, int> > result;

bool Backtracking(int iX, int iY)
{

    if(iX<0 || iY<0||iX>=iNx||iY>=iNy||myMaze[iX][iY].bvisited)
    {
        return false;
    }
    if(iX==iEx&& iY==iEy)
    {
        pair<int, int> p;
        p.first = iX;
        p.second= iY;

        result.push_back(p);
        vector< pair<int, int> >::iterator itr;
        for(itr = result.begin(); itr!=result.end(); itr++)
        {
            cout<<(*itr).first+1<<' '<<(*itr).second+1<<'\n';
        }
        return true;
    }

    myMaze[iX][iY].bvisited=true;
    pair<int, int> p;
    p.first = iX;
    p.second = iY;
    result.push_back(p);

    if(!myMaze[iX][iY].bwall[0]&&Backtracking(iX-1,iY)==true)
        return true;
    if(!myMaze[iX][iY].bwall[1]&&Backtracking(iX+1,iY)==true)
        return true;
    if(!myMaze[iX][iY].bwall[2]&&Backtracking(iX,iY+1)==true)
        return true;
    if(!myMaze[iX][iY].bwall[3]&&Backtracking(iX,iY-1)==true)
        return true;



    //myMaze[iX][iY].bvisited = false; not neccesary
    result.pop_back();
    return false;

}

int main()
{
    Rd("blah.in");
    //Wt("blah.out");

    cin>>iNx>>iNy;

    cin>>iSx>>iSy;
    cin>>iEx>>iEy;

    iSx--;iSy--;iEx--;iEy--; //shift to (0,0)
    for(int i = 0; i < iNx*iNy; i++)
    {
        int ix, iy;
        cin>>ix>>iy;
        ix--; iy--; //shift to (0,0)
        myMaze[ix][iy].bvisited=false;
        char cIn;
        for(int k = 0; k < 4; k++)
        {
            cin>>cIn;
            if(cIn=='W')
            {
                myMaze[ix][iy].bwall[k]=true;
            }
            else
            {
                myMaze[ix][iy].bwall[k]=false;
            }
        }
    }

    Backtracking(iSx,iSy);

}

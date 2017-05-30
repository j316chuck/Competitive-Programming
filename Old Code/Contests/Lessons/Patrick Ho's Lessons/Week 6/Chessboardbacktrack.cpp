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

class board
{
    public:
    bool bworks;
    bool b[2];
};

int iSx = 0, Sy = 0;
int iNx, iNy;
int iEx, iEy;
vector < pair<int, int> > result;
board myboard[100][100];
int counter = 0;

bool Backtrack(int iSx, int iSy, int iNx,int iNy)
{
    myboard[iSx][iSy].bworks = false;
    if(iSy>iEx|| iSx>iEy||myboard[iSx][iSy].bworks==false)
    {
        return false;
    }
    else if(iSx==iNx+2 && iSy== iNy+1){
       return false;
   } else if(iSx==iNx+2 && iSy== iNy-1){
       return false;
   }  else if(iSx==iNx-2 && iSy== iNy+1){
       return false;
   }  else if(iSx==iNx-2 && iSy== iNy-1){
       return false;
   }  else if(iSx==iNx-1 && iSy== iNy+2){
       return false;
   }  else if(iSx==iNx+1 && iSy== iNy+2){
       return false;
   }  else if(iSx==iNx-1 && iSy== iNy-2){
       return false;
   }  else if(iSx==iNx+1 && iSy== iNy-2){
       return false;
   }  else if(iSx==iNx && iSy== iNy){
       return false;
   }

    if(iSx==iEx && iSy == iEy){
        counter++;
        cout<<counter<<endl;

    myboard[iSx][iSy].bworks = true;
        return true;
    }
    myboard[iSx][iSy].bworks = true;
    if(Backtrack(iSx+1, iSy, iNy, iNx)==true)
        myboard[iSx][iSy].bworks = true;
        return true;
    if(Backtrack(iSx, iSy+1 , iNy, iNx)==true)
        myboard[iSx][iSy].bworks = true;
        return true;


        return false;


}

int main()
{
    cin>>iEx>>iEy>>iNx>>iNy;

Backtrack(0, 0 , iNx, iNy);
}

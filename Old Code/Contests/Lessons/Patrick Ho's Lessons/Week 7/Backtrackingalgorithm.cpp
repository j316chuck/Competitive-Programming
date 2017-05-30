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
int matrix [100][100];
class square
{
    public:
    int x;
    int y;
    char left, right, up,down;

};
int xstart, ystart;
    int xend, yend;
void Backtrack(int xstart, int ystart)
{

    if(xstart==xend && ystart ==yend)
    {

    }
    if(xstart)
}
int main()
{

    vector<square> box
    Rd("random.in");
    Wt("random.out");
    int xsize, ysize;

    cin>>xsize>>ysize>>xstart>>ystart>>xend>>yend;
    for(int i = 0; i <xsize;i++)
    {
        int x1, y1;
        char left1, right1, up1, down1;
        for(int j =0; j < ysize; j++)
        {
            cin>>x1>>y1>>left>>right>>up>>down;
            vector<box> a;

            a.x.push_back(x1);
            a.y.push_back(y1);
            a.left.push_back(left1);
            a.right.push_back(right1);
            a.up.push_back(up1);
            a.down.push_back(down1);

            box.push_back(a);
        }
    }

    Backtrack( xstart, ystart);


}

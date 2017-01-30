/*
ID: j316chuck
PROG: castle
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
#define MAX 1001
using namespace std;

int mygraph[100][100];
int R,C;
int counting;
int maximum;
void floodfill(int row, int col){
    if(row<0||row>=R)
        return;
    if(col<0||col>=C)
        return;
    if(mygraph[row][col]==1)
        return;
    if(mygraph[row][col]==0){
        mygraph[row][col]=1;
        counting++;
        maximum=max(maximum,counting);
        floodfill(row+1,col);
        floodfill(row-1,col);
        floodfill(row,col+1);
        floodfill(row,col-1);
    }

}
int main()
{
    Rd("input.in");
    //Wt("input.out");
    //int R,C;
    cin>>R>>C;
    for(int i=0; i<R; i++){
        for(int k=0; k<C; k++){
            cin>>mygraph[i][k];
        }
    }
    int counter=0;
    for(int i=0; i<R; i++){
        for(int k=0; k<C; k++){
            if(mygraph[i][k]==0){
                counter++;
                counting=0;
            }
            floodfill(i,k);
        }
    }
    cout<<counter<<' '<<maximum<<endl;
    double k=3.14159265359;
    cout<<k*k*9<<endl;
}


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


#define Set(a, s) memset(a, s, sizeof (a))
#define Rd(r) freopen(r, "r", stdin)
#define Wt(w) freopen(w, "w", stdout)

using namespace std;

int mygraph[2001][2001];
int xmax=-1;
int xmin=20000;
int ymax=-1;
int ymin=20000;
class square{
public:
    int x1;
    int y1;
    int x2;
    int y2;
};
vector<square> mysquare;

void Recurse(int x, int y, int U, int D, int L, int R, char direction, int startx, int starty){
    if(mygraph[x][y]!=1){
        return;
    }if(x==startx&&y==starty&&U!=0&&D!=0&&L!=0)
    if(){
        Recurse()
    }

}
int main(){
    Rd("gates.in");
    Wt("gates.out");

    int N;
    cin>>N;
    int xpos=1000;
    int ypos=1000;
    mygraph[1000][1000]=1;
    for(int i=0; i<N; i++){
        char c;
        cin>>c;
        if(c=='N'){
            ypos++;
        }if(c=='S'){
            ypos--;
        }if(c=='W'){
            xpos--;
        }if(c=='E'){
            xpos++;
        }

        mygraph[xpos][ypos]=1;
        xmax=max(xmax, xpos);
        xmin=min(xmin, xpos);
        ymax=max(ymax, ypos);
        ymin=min(ymin, ypos);
        //cout<<xpos<<ypos<<endl;
    }
    for(int i=xmin; i<xmax; i++){
        for(int k=ymin; k<ymax; k++){
            if(mygraph[i][k]==1)
                Recurse(i, k, 0, 0, 0, 0, U, i, k);
                Recurse(i, k, 0, 0, 0, 0, D, i, k);
                Recurse(i, k, 0, 0, 0, 0, L, i, k);
                Recurse(i, k, 0, 0, 0, 0, R, i, k);
        }
    }
    cout<<mysquare.size()<<endl;
}

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
using namespace std;

//int mygraph[101][101][101][101];
class graph{
public:
    int startx, starty, endx, endy;
};
vector<graph> mygraph2;
vector< pair<int, int> > mylight;
int canwalk[101][101];  //can walk
int havekey[101][101]; //have key

int M, N;

void Recurse(int x, int y){
    if(x-1>0){
        canwalk[x-1][y]=1;
    }if(x+1<=M){
        canwalk[x+1][y]=1;
    }if(y-1>0){
        canwalk[x][y-1]=1;
    }if(y+1<=M){
        canwalk[x][y+1]=1;
    }
    cout<<x<<y<<endl;
    for(int i=0; i<mygraph2.size(); i++){
        if(mygraph2[i].startx==x&&mygraph2[i].starty==y){
            havekey[mygraph2[i].endx][mygraph2[i].endy]=1;
        }
    }

    for(int i=0; i<mygraph2.size(); i++){
        if(havekey[mygraph2[i].endx][mygraph2[i].endy]==1&&canwalk[mygraph2[i].startx][mygraph2[i].starty]==1){
            mylight.push_back(make_pair(mygraph2[i].endx, mygraph2[i].endy));
            Recurse(mygraph2[i].endx, mygraph2[i].endy);
        }
    }

}
int main(){
    Rd("lightson.in");
    //Wt("lightson.out");


    cin>>M>>N;
    for(int i=0; i<N; i++){
        int x, y, a, b;
        cin>>x>>y>>a>>b;
        //mygraph[x][y][a][b]=1;
        graph a1;
        a1.startx=x; a1.starty=y; a1.endx=a; a1.endy=b;
        mygraph2.push_back(a1);
    }
    //mylight.push_back(make_pair(1,1));
    canwalk[1][1]=2;
    Recurse(1,1);
    cout<<mylight.size()<<endl;

}

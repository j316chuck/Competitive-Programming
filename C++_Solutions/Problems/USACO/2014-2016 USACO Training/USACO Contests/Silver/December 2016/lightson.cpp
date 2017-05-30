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

class graph{
public:
    int startx, starty, endx, endy;
    bool visited;
};
vector<graph> mygraph;
vector< pair<int, int> > mylight;

void Recurse(int x, int y){
    for(int k=0; k<mylight.size(); k++){
        x=mylight[k].first;
        y=mylight[k].second;
        for(int i=0; i<mygraph.size(); i++){
            //cout<<x<<' '<<y<<' '<<mygraph[i].startx<<' '<<mygraph[i].starty<<' '<<mygraph[i].endx<<' '<<mygraph[i].endy<<endl;
            for(int m=0; m<mylight.size(); m++){
                if(mylight[m].first==mygraph[i].startx && mylight[m].second==mygraph[i].starty&&mygraph[i].visited==false){
                    int counter=0;
        if(mygraph[i].endx==x+1 && mygraph[i].endy==y){
            counter=1;
        }if(mygraph[i].endx==x-1 && mygraph[i].endy==y){
            counter=1;
        }if(mygraph[i].endx==x && mygraph[i].endy==y+1){
            counter=1;
        }if(mygraph[i].endx==x && mygraph[i].endy==y-1){
            counter=1;
        }
        if(counter==1){
            //cout<<"yep"<<endl;
            mygraph[i].visited=true;
            pair<int, int> a; a.first=mygraph[i].endx; a.second=mygraph[i].endy;
            for(int j=0; j<mylight.size(); j++){
                if(mylight[j].first==a.first && mylight[j].second==a.second){
                    break;
                }if(j==mylight.size()-1){
                    mylight.push_back(a);
                }
            }
            Recurse(mygraph[i].endx, mygraph[i].endy);
        }

            }
            //if(mygraph[i].startx==x && mygraph[i].starty==y && mygraph[i].visited==false)
            }
        }
    }
}
int main(){
    Rd("lightson.in");
    Wt("lightson.out");
    int N, M;
    cin>>M>>N;
    for(int i=0; i<N; i++){
        graph x;
        cin>>x.startx>>x.starty>>x.endx>>x.endy;
        x.visited=false;
        mygraph.push_back(x);
    }
    pair<int, int> a;
    a.first=1;
    a.second=1;
    mylight.push_back(a);
    Recurse(1,1);

    cout<<mylight.size()<<endl;

}



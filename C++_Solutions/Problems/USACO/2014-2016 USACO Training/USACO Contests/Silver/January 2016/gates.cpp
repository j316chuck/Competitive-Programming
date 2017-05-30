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
int main(){
    Rd("gates.in");
    Wt("gates.out");

    int N;
    cin>>N;
    int xpos=1000;
    int ypos=1000;
    int xmax=-1;
    int xmin=20000;
    int ymax=-1;
    int ymin=20000;
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
    int counter=0;
    for(int i=xmin; i<xmax; i++){
        for(int k=ymin; k<ymax; k++){
            if(mygraph[i][k]!=1)
                break;
            else{
                for(int j=i+1; j<=xmax; j++){
                    if(mygraph[j][k]!=1)
                        break;
                    for(int l=k+1; l<=ymax; l++){
                        if(mygraph[i][l]!=1){
                            break;
                        }else if(mygraph[j][l]!=1){
                            continue;
                        }else{
                            int temp=0;
                            for(int m=k; m<l;m++){
                                if(mygraph[j][m]!=1){
                                    temp=1;
                                    break;
                                }
                            }
                            for(int m=i; m<j; m++){
                                if(mygraph[m][l]!=1){
                                    temp=1;
                                    break;
                                }
                            }
                            if(temp==0){
                                counter++;
                                //cout<<i<<' '<<k<<"     "<<i<<' '<<l<<"      "<<j<<' '<<k<<"        "<<j<<' '<<l<<endl;
                            }
                        }
                    }
                }
            }
        }
    }
    cout<<counter<<endl;
    //cout<<xmax<<xmin<<ymax<<ymin;
}

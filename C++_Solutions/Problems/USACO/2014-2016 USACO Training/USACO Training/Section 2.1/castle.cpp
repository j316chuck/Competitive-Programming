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

int R,C;
class castle{
public:
    int n,e,s,w, visited, rooom, num;
};
castle mygraph[52][52];

int mycastle[51][51];
int myroom[52];
class three{
    public:
    int r, c;
    char dir;
};

void formgraph(int a, int row, int column){
    castle b;
    b.visited=0;
    b.rooom=0;
    b.num=0;
    if(a==0){
        b.n=0;b.s=0;b.w=0;b.e=0;
    }if(a==1){
        b.n=0;b.s=0;b.w=1;b.e=0;
    }if(a==2){
        b.n=1;b.s=0;b.w=0;b.e=0;
    }if(a==4){
        b.n=0;b.s=0;b.w=0;b.e=1;
    }if(a==8){
        b.n=0;b.s=1;b.w=0;b.e=0;
    }if(a==3){
        b.n=1;b.s=0;b.w=1;b.e=0;
    }if(a==5){
        b.n=0;b.s=0;b.w=1;b.e=1;
    }if(a==9){
        b.n=0;b.s=1;b.w=1;b.e=0;
    }if(a==6){
        b.n=1;b.s=0;b.w=0;b.e=1;
    }if(a==10){
        b.n=1;b.s=1;b.w=0;b.e=0;
    }if(a==12){
        b.n=0;b.s=1;b.w=0;b.e=1;
    }if(a==7){
        b.n=1;b.s=0;b.w=1;b.e=1;
    }if(a==14){
        b.n=1;b.s=1;b.w=0;b.e=1;
    }if(a==11){
        b.n=1;b.s=1;b.w=1;b.e=0;
    }if(a==13){
        b.n=0;b.s=1;b.w=1;b.e=1;
    }if(a==15){
        b.n=1;b.s=1;b.w=1;b.e=1;
    }
    mygraph[row][column]=b;
}
int counter=0;
int maximum;
void floodfill(int row, int col, int rooms){
    if(mygraph[row][col].visited==1){
        return;
    }if(mygraph[row][col].visited==0){
        counter++;
        mygraph[row][col].rooom=rooms;
        maximum=max(counter,maximum);
        myroom[rooms]=counter;
        mygraph[row][col].visited=1;
    }if(mygraph[row][col].n==0){
        floodfill(row-1, col,rooms);
    }if(mygraph[row][col].s==0){
        floodfill(row+1, col,rooms);
    }if(mygraph[row][col].w==0){
        floodfill(row, col-1,rooms);
    }if(mygraph[row][col].e==0){
        floodfill(row, col+1,rooms);
    }
}

int main()
{
    Rd("castle.in");
    Wt("castle.out");
    cin>>C>>R;

    for(int i=0; i<R; i++){
        for(int k=0; k<C; k++){
            cin>>mycastle[i][k];
        }
    }
    for(int i=0; i<R; i++){
        for(int k=0; k<C; k++){
            formgraph(mycastle[i][k],i,k);
        }
    }
    int rooms=0;
    for(int i=0; i<R; i++){
        for(int k=0; k<C; k++){
            if(mygraph[i][k].visited==0){
                rooms++;
                counter=0;
            }
            floodfill(i,k, rooms);
        }
    }
    //cout<<rooms<<endl;

    for(int i=0; i <R; i++){
        for(int k=0; k<C; k++){
            for(int j=1; j <=rooms; j++)
                if(mygraph[i][k].rooom==j){
                    mygraph[i][k].num=myroom[j];
                    //cout<<i<<' '<<k<<' '<<myroom[j]<<' '<<j<<endl;
                }
        }
    }
    /*for(int i=0; i<R; i++){
        for(int k=0; k<C; k++){
            cout<<mygraph[i][k].rooom;
        }
        cout<<endl;
    }*/
    int maximum2=0;
    three maximum3;
    for(int i=0; i<R; i++){
        for(int k=0; k <C-1; k++){
            if(mygraph[i][k].rooom!=mygraph[i][k+1].rooom&&mygraph[i][k].e==1){
                if(mygraph[i][k].num+mygraph[i][k+1].num > maximum2){
                    maximum2=mygraph[i][k].num+mygraph[i][k+1].num;
                    maximum3.r=i;
                    maximum3.c=k;
                    maximum3.dir='E';
                }
                if(mygraph[i][k].num+mygraph[i][k+1].num==maximum2){
                    if(maximum3.c>k){
                        maximum3.c=k;
                        maximum3.r=i;
                        maximum3.dir='E';
                    }if(maximum3.c==k){
                        if(maximum3.r<i){
                            maximum3.r=i;
                            maximum3.c=k;
                            maximum3.dir='E';
                        }
                    }
                }
            }
            //cout<<maximum3.r<<maximum3.c<<maximum3.dir<<mygraph[i][k].rooom<<mygraph[i][k+1].rooom<<' ';
        }
       // cout<<endl;
    }
    for(int i=0; i <R-1; i++){
        for(int k=0; k<C; k++){
           if(mygraph[i][k].rooom!=mygraph[i+1][k].rooom&& mygraph[i][k].s==1){
                if(maximum2<(mygraph[i][k].num+mygraph[i+1][k].num)){
                    maximum2=mygraph[i][k].num+mygraph[i+1][k].num;
                    maximum3.r=i+1;
                    maximum3.c=k;
                    maximum3.dir='N';
                }if(maximum2==mygraph[i][k].num+mygraph[i+1][k].num){
                    if(maximum3.c>k){
                        maximum3.r=i+1;
                        maximum3.c=k;
                        maximum3.dir='N';
                    }if(maximum3.c==k){
                        if(maximum3.r<i+1){
                            maximum3.r=i+1;
                            maximum3.c=k;
                            maximum3.dir='N';
                        }if(maximum3.r==i+1){
                            if(maximum3.dir=='E'){
                                maximum3.dir='N';
                            }
                        }
                    }
                }//cout<<maximum3.r<<maximum3.c<<maximum3.dir<<mygraph[i+1][k].rooom<<mygraph[i][k].rooom<<' ';
           }
        }
        //cout<<endl;
    }

    cout<<rooms<<endl;
    cout<<maximum<<endl;
    cout<<maximum2<<endl;
    cout<<maximum3.r+1<<' '<<maximum3.c+1<<' '<<maximum3.dir<<endl;
}

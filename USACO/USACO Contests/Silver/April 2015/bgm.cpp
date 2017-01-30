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

int mygraph[7][7];

int main(){
    Rd("bgm.in");
    Wt("bgm.out");
    int N;
    cin>>N;
    //cout<<mygraph[0][0];
    for(int i=0; i<N; i++){
        int k;
        char s;
        cin>>s>>k;
        if(k>=0){
        if(s=='B')
            mygraph[0][k%7]++;
        if(s=='E')
            mygraph[1][k%7]++;
        if(s=='S')
            mygraph[2][k%7]++;
        if(s=='I')
            mygraph[3][k%7]++;
        if(s=='G')
            mygraph[4][k%7]++;
        if(s=='O')
            mygraph[5][k%7]++;
        if(s=='M')
            mygraph[6][k%7]++;
        }
        else{
        if(s=='B')
            mygraph[0][7+(k%7)]++;
        if(s=='E')
            mygraph[1][7+(k%7)]++;
        if(s=='S')
            mygraph[2][7+(k%7)]++;
        if(s=='I')
            mygraph[3][7+(k%7)]++;
        if(s=='G')
            mygraph[4][7+(k%7)]++;
        if(s=='O')
            mygraph[5][7+(k%7)]++;
        if(s=='M')
            mygraph[6][7+(k%7)]++;
        }
    }

    /*for(int i=0; i<7; i++){
        for(int r=0; r<7; r++){
            cout<<mygraph[i][r];
        }
        cout<<endl;
    }*/
    long long total=0;

    for(int B=0; B<7; B++){
        for(int E=0; E<7; E++){
            for(int S=0; S<7; S++){
                for(int I=0; I<7; I++){
                    for(int G=0; G<7; G++){
                        for(int O=0; O<7; O++){
                            for(int M=0; M<7; M++){
                                    if((M+O+O)%7==0||(B+E+S+S+I+E)%7==0||(G+O+E+S)%7==0){
                                        total+=mygraph[0][B]*mygraph[1][E]*mygraph[2][S]*mygraph[3][I]*mygraph[4][G]*mygraph[5][O]*mygraph[6][M];
                                    }
                            }
                        }
                    }
                }
            }
        }
    }
    cout<<total<<endl;

}



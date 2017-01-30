/*
ID: j316chuck
PROG: sprime
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

int mygraph[9][100000];

int n1=4,n2=0,n3(0),n4(0),n5(0),n6(0),n7(0),n8(0);

bool check(int a){
    for(int i=2; i <=sqrt(a); i++){
        if(a%i==0)
            return false;
    }
    return true;
}

void solve(int N){

    for(int i=1; i<10; i+=2){
        for(int j=0; j<n1;j++){
              if(check((mygraph[1][j]*10)+i)==true){
                mygraph[2][n2]=mygraph[1][j]*10+i;
                n2++;
            }
        }
    }
    for(int i=1; i<10; i+=2){
        for(int j=0; j<n2;j++){
              if(check((mygraph[2][j]*10)+i)==true){
                mygraph[3][n3]=mygraph[2][j]*10+i;
                n3++;
            }
        }
    }
    for(int i=1; i<10; i+=2){
        for(int j=0; j<n3;j++){
              if(check((mygraph[3][j]*10)+i)==true){
                mygraph[4][n4]=mygraph[3][j]*10+i;
                n4++;
            }
        }
    }
    for(int i=1; i<10; i+=2){
        for(int j=0; j<n4;j++){
              if(check((mygraph[4][j]*10)+i)==true){
                mygraph[5][n5]=mygraph[4][j]*10+i;
                n5++;
            }
        }
    }
     for(int i=1; i<10; i+=2){
        for(int j=0; j<n5;j++){
              if(check((mygraph[5][j]*10)+i)==true){
                mygraph[6][n6]=mygraph[5][j]*10+i;
                n6++;
            }
        }
    }
     for(int i=1; i<10; i+=2){
        for(int j=0; j<n6;j++){
              if(check((mygraph[6][j]*10)+i)==true){
                mygraph[7][n7]=mygraph[6][j]*10+i;
                n7++;
            }
        }
    }
     for(int i=1; i<10; i+=2){
        for(int j=0; j<n7;j++){
              if(check((mygraph[7][j]*10)+i)==true){
                mygraph[8][n8]=mygraph[7][j]*10+i;
                n8++;
            }
        }
    }

}

int main()
{
    Rd("sprime.in");
    Wt("sprime.out");
    mygraph[1][0]=2;
    mygraph[1][1]=3;
    mygraph[1][2]=5;
    mygraph[1][3]=7;
    int N;
    cin>>N;
    //cout<<mygraph[1][0]<<endl;
    solve(N);
    vector<int> ans;
    if(N==1){
        for(int i=0; i <n1; i++){
            ans.push_back(mygraph[N][i]);
        }
    }if(N==2){
        for(int i=0; i <n2; i++){
            ans.push_back(mygraph[N][i]);
        }
    }if(N==3){
        for(int i=0; i <n3; i++){
            ans.push_back(mygraph[N][i]);
        }
    }if(N==4){
        for(int i=0; i <n4; i++){
            ans.push_back(mygraph[N][i]);
        }
    }if(N==5){
        for(int i=0; i <n5; i++){
            ans.push_back(mygraph[N][i]);
        }
    }if(N==6){
        for(int i=0; i <n6; i++){
            ans.push_back(mygraph[N][i]);
        }
    }if(N==7){
        for(int i=0; i <n7; i++){
            ans.push_back(mygraph[N][i]);
        }
    }if(N==8){
        for(int i=0; i <n8; i++){
            ans.push_back(mygraph[N][i]);
        }
    }
    sort(ans.begin(), ans.end());

    for(int i=0; i <ans.size(); i++)
        cout<<ans[i]<<endl;


}

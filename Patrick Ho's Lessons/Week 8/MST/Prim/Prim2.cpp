/*
ID: peiqistar1
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

const double Pi=acos(-1.0);
typedef long long LL;

#define Set(a, s) memset(a, s, sizeof (a))
#define Rd(r) freopen(r, "r", stdin)
#define Wt(w) freopen(w, "w", stdout)

using namespace std;

int N;
int weight[100][100];
int d[100];
int inTree[100];
int whoTo[100];

void updateDistance(int target){
    for(int i=0; i<N; i++){
        if(weight[target][i]!=0){
            d[i]=min(d[i],weight[target][i]);
            whoTo[i]=target;
        }
    }
}
int total;

int main()
{
    Rd("Prim.in");
    cin>>N;
    for(int i=0; i<N; i++){
        for(int k=0; k<N; k++){
            cin>>weight[i][k];
        }
    }

    for(int i=0; i<N; i++){
        d[i]=100000;
    }

    inTree[0]=1;
    updateDistance(0);
    cout<<"adding node 1"<<endl;

    for(int i=1; i<N; i++){
        int min=-1;
        for(int k=0; k <N; k++){
            if(inTree[k]==0){
                if(min==-1||d[i]<d[min]){
                   min=i;
                }
            }
        }
        cout<<"adding edge "<<whoTo[min]+1<<'-'<<min+1<<endl;
        total+=d[min];
        inTree[min]=1;
        updateDistance(min);

    }
    cout<<total<<endl;
}

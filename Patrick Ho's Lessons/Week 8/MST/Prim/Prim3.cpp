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
int matrix[100][100];
int whoTo[100];
int d[100];
int ingraph[100];

void updateDistance(int target){
    for(int i=0; i<N; i++){
        if(d[i]>matrix[target][i]&&matrix[target][i]!=0){
            d[i]=matrix[target][i];
            whoTo[i]=target;
        }
    }
}

int main(int argc, char *argv[])
{
	Rd("prim.in");
	cin>>N;
	for(int i=0; i<N; i++){
        for(int k=0; k<N; k++){
            cin>>matrix[i][k];
        }
	}
	for(int i=0; i<N; i++){
        d[i]=INT_MAX;
	}
	//printf("Adding node %d\n", 1);
	ingraph[0]=1;
	updateDistance(0);
	int total=0;
	for(int i=1; i<N; i++){
        int min=-1;
        for(int k=0; k<N; k++){
            if(ingraph[k]==0){
                if(min==-1||d[k]<d[min]){
                    min=k;
                }
            }
        }
        total+=d[min];
        updateDistance(min);
       // cout<<total<<endl;
       //cout<<total<<endl;
        ingraph[min]=1;
	}
	cout<<total<<endl;


}

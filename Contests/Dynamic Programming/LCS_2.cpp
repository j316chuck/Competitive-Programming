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

int main(){
    Rd("LCS.txt");
    string s1;
    string s2;
    cin>>s1>>s2;
    int m=s1.size();
    int n=s2.size();
    int mygraph[m+1][n+1];

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(i==0||j==0)
                mygraph[i][j]=0;
            else if(s1[i]==s2[i]){
                mygraph[i][j]=1+mygraph[i-1][j-1];
            }else{
                mygraph[i][j]=max(mygraph[i-1][j], mygraph[i][j-1]);
            }
        }
    }
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cout<<mygraph[i][j]<<' ';
        }
        cout<<endl;
    }

    //cout<<m;
}



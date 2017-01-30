/*
ID: j316chuck
PROG: numtri
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

int dp[1001][1001];

int main(){
    //freopen("numtri.in", "r", stdin);
    Rd("numtri.in");
    Wt("numtri.out");
    //freopen("numtri.out", "w", stdout);
    int n;
    scanf("%d", &n);
    //cin>>n;
    vector< vector<int> > numtri;
    //cout<<n<<endl;
    //printf("%d", n);
    for(int i = 1; i <= n; i++){
        vector<int> temp;
        for(int j = 0; j < i; j++){
            int k;
            //scanf("%d", &k);
            cin>>k;
            temp.push_back(k);
            //cout<<k;
        }
        numtri.push_back(temp);
    }
    /*for(int i=0; i < n; i++){
        for(int j=0; j< numtri[i].size(); i++){
            cout<<numtri[i][j]<<' ';
        } cout<<endl;
    }*/
    //cout<<numtri[0][0]<<endl;
    //cout<<numtri[4][0]<<endl;
    /*for(int i = 0; i < numtri.size(); i++){
        for(int j = 0; j < numtri[i].size(); j++){
            printf("%d ", numtri[i][j]);
        }
        printf("\n");
    }*/
    //top down solution
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < numtri[n-1].size(); i++){
        dp[0][i] = numtri[n-1][i];
    }
    /*for(int i=0; i<numtri[n-1].size(); i++)
        cout<<dp[0][i]<<' ';
    cout<<endl;*/
    //cout<<dp[0][4];
    for(int i = 1; i < n; i++){
        for(int j = 0; j < numtri[n-i-1].size(); j++){
            dp[i][j] = numtri[n-i-1][j]+max(dp[i-1][j], dp[i-1][j+1]);
            //cout<<dp[i][j]<<' ';
        }//cout<<endl;
    }
    /*for(int i = 0; i < n; i++){
        for(int j = 0; j < numtri[n-i-1].size(); j++){
            printf("%d ", dp[i][j]);
            //cout<<dp[i][j]<<' ';
        }//cout<<endl;
        printf("\n");
    }*/
    printf("%d\n", dp[n-1][0]);



}

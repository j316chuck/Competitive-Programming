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


int dp[1001][1001];//A, B

int main(){

    freopen("LCS.in", "r", stdin);
    char temp[1001];
    scanf("%1001s", temp);
    string A = temp;
    scanf("%1000s", temp);
    string B = temp;

    for(int i = 0; i < B.size(); i++){
        if(B[i] == A[0]){
            dp[0][i] = 1;
            break;
        }
    }

    for(int i = 1; i < A.size(); i++){
        for(int j = 0; j < i; j++){
            for(int k = 0; k < B.size(); k++){
                if(A[i]==B[k]){
                    dp[i][k] = 1;
                    break;
                }
            }
            for(int k = 0; k < B.size(); k++){
                if(dp[j][k] != 0){
                    for(int l = k+1; l < B.size(); l++){
                        if(A[i] == B[l]){
                            dp[i][l] = 1 + dp[j][k];
                            /*cout<<dp[j][k]<<' '<<dp[i][l]<<endl;
                            cout<<A[j]<<B[k]<<' '<<A[i]<<B[l]<<endl;
                            cout<<j<<k<<' '<<i<<l<<endl;
                            cout<<endl;*/
                            break;
                        }
                    }
                }
            }
        }
    }
    int maximum = -1;
    for(int i = 0; i < A.size(); i++){
        for(int j = 0; j < B.size(); j++){
            cout<<dp[i][j]<<A[i]<<B[j]<<' ';
            maximum = max(maximum, dp[i][j]);
        }cout<<endl;
    }
    cout<<maximum<<endl;
    int counter = maximum;
    string result = "";
    //int r = A.size(); int c = B.size();

    for(int r = A.size(); r >= 0; r--){
        for(int c = B.size(); c >= 0; c--){
            if(dp[r][c] == counter && counter!=0){
                counter--;
                result += A[r];
            }
        }
    }

    for(int i = result.size()-1; i>=0; i--)
        cout<<result[i];
    cout<<endl;
}

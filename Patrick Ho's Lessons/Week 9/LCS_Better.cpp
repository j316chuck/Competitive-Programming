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

string A, B;
int dp[1001][1001];

int Recurse(int i, int j){
    if(dp[i][j] == -1){
        if(A[i] =='\0'|| B[j] == '\0'){
            dp[i][j] = 0;
        }else if(A[i] == B[j]){
            dp[i][j] = 1 + Recurse(i+1, j+1);
        }else{
            dp[i][j] = max(Recurse(i+1, j), Recurse(i, j+1));
        }
    }
    return dp[i][j];
}

int dp2[1000][1000];

int main(){
    freopen("LCS.in", "r", stdin);
    char temp[1001];
    scanf("%1001s", temp);
    A = temp;
    A+='\0';
    scanf("%1000s", temp);
    B = temp;
    B+='\0';

    //int M = A.size()- 1;
    //int N = B.size()- 1;
    memset(dp, -1, sizeof(dp));
    memset(dp2, -1, sizeof(dp2));
    //cout<<dp[0][0]<<endl;

   // N = A.size()-1;
    for(int i = A.size()-1; i >=0; i--){
        for(int j = B.size()-1; j>= 0; j--){
            if(A[i]=='/0'||B[j] == '/0')
                dp2[i][j] = 0;
            else if(A[i] == B[j]){
                dp2[i][j] = 1 + dp2[i+1][j+1];
            }else{
                dp2[i][j] = max(dp2[i+1][j], dp2[i][j+1]);
            }
        }
    }
    //cout<<dp2[0][0]<<endl;
    cout<<Recurse(0, 0)<<endl;
    string result = "";
    int counter = dp2[0][0];
    /*for(int i = 0; i < A.size() -1; i++){
        for(int j = 0; j < B.size()-1; j++){
            if(dp2[i+1][j] == counter-1 && dp2[i][j+1] == counter-1 && counter!=0){
                counter -= 1;
                result += A[i];
            }
        }
    }*/
    int i = 0, j = 0;
    while(i < A.size()-1 && j < B.size()-1){
        if(A[i] == B[j]){
            result+=A[i];
            i++;
            j++;
        }else if(dp2[i+1][j] >= dp2[i][j+1]){
            i++;
        }else{
            j++;
        }
    }
    cout<<result<<endl;

}

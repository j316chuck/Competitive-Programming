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

int dp[1000];

int main(){

    freopen("LIS.in", "r", stdin);
    int N;
    scanf("%d ", &c);
    //cin>>N;
    vector<int> sequence;
    for(int i = 0; i < N; i++){
        int a;
        scanf("%d ", &a);
        sequence.push_back(a);
    }
    for(int i = 0; i < N; i++)
        dp[i] = 1;

    for(int i = N-2; i >= 0; i--){
        for(int j = i+1; j <= N-1; j++){
            if(sequence[i] < sequence[j]){
                dp[i] = max(1 + dp[j], dp[i]);
            }
        }
    }
    int result = 0;
    for(int i = 0; i < N; i++){
        //printf("%d ", dp[i]);
        result = max(result, dp[i]);
    }
    int counter = result;
    for(int i = 0; i < N; i++){
        if(counter == dp[i]){
            //printf("%d ", sequence[i]);
            counter--;
        }
    }
    printf("%d \n", result);

    /*for(int i = 0; i < sequence.size(); i++){
        printf("%d ", sequence[i]);
    }*/

}

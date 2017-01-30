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

class knap{
public:
    int id;
    int value;
    int weight;
    //vector<int> used;
};

int dp[1000][1000];
//int solutions[1000][1000];

int main(){

    freopen("knapsack.in", "r", stdin);
    //freopen("knapsack.out", "w", stdout);
    int N, W;
    scanf("%d %d", &N, &W);
    vector<knap> mysack;

    for(int i = 0; i < N; i++){
        knap a;
        scanf("%d %d %d", &a.id, &a.value, &a.weight);
        mysack.push_back(a);
    }
    /*for(int i = 0; i < N; i++){
        printf("%d %d %d \n", mysack[i].id, mysack[i].value, mysack[i].weight);
    }*/
    memset(dp, 0, sizeof(dp));
    for(int i = 1; i <= W; i++){
        dp[0][i] = mysack[0].value*(i/mysack[0].weight);
        //if(i >= mysack[0].weight)
        //solutions[0][] = 1;
    }
    //cout<<solutions[0][5]<<endl;
    for(int i = 1; i < N; i++){
        for(int j = 1; j <= W; j++){
            dp[i][j] = dp[i-1][j];
            /*for(int k = 0; k < W; k++){

            }*/
            if (j >= mysack[i].weight)
                dp[i][j] = max(dp[i-1][j], dp[i][j-mysack[i].weight]+mysack[i].value);
        }
    }

    /*for(int i = 0; i < N; i++){
        for(int j = 1; j <= W; j++){
            printf("%d ", dp[i][j]);
        }printf("\n");
    }*/
    //printf("%d", dp[N-1][W]);
    //for(int i = 0; i < )
}

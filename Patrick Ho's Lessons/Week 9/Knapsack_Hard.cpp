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
    vector<int> used;
};

int dp[1000][1000]; //add a third option of what used [1000][1000][1000]
//int solutions[1000][1000];
bool keep[1000][1000]; // name: knap, row: if used item blank, for what weight, used
bool results[1000];

int main(){

    freopen("knapsack.in", "r", stdin);
    //freopen("knapsack.out", "w", stdout);
    //printf("%d", keep[0][0]);
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
        if (i >= mysack[0].weight){
            keep[mysack[0].id][i] = 1;
        }
        //if(i >= mysack[0].weight)
         //       mysack[0].used.push_back(mysack[0].id);
    }
    /*for(int i = 1; i <= W; i++)
        printf("%d ", keep[mysack[0].id][i]);
    */
    //cout<<solutions[0][5]<<endl;
    for(int i = 1; i < N; i++){ //which sack your on in mysack mysack[i].id
        for(int j = 1; j <= W; j++){ //weight your on/columns
            //dp[i][j] = dp[i-1][j];
            //if (j >= mysack[i].weight)
            //  dp[i][j] = max(dp[i-1][j], dp[i][j-mysack[i].weight]+mysack[i].value);
            if (j >= mysack[i].weight && dp[i][j-mysack[i].weight] + mysack[i].value > dp[i-1][j]){
                dp[i][j] = dp[i][j - mysack[i].weight] + mysack[i].value;
                keep[mysack[i].id][j] = 1;
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    //method 1
    /*int r = N, c = W;
    while(c != 0){
        if(keep[r][c] == 1){
            //printf("%d", r);
            results[r] = 1;
            //printf("%d %d \n", r, results[r]);
            c = c - mysack[r-1].weight;
        }else{
            r = r - 1;
        }
    }
    printf("%d \n", dp[N-1][W]);
    //sort(results.begin(), results.end());
    for(int i = 1; i <= N; i++){
        if(results[i]==1)
            printf("%d ", i);
    }*/
    //method 2
    int c = W;
    for (int i = N; i >= 1; i--){
        if(keep[i][c] == 1){
            results[i] = 1;
            c = c - mysack[i-1].weight;
        }
    }

    printf("%d \n", dp[N-1][W]);
    for(int i = 1; i <= N; i++){
        if(results[i]==1)
            printf("%d ", i);
    } printf("\n");
    /*for(int i = 0; i < N; i++){
        for(int j = 1; j <= W; j++){
            printf("%d ", dp[i][j]);
        }printf("\n");
    }*/
    //printf("%d", dp[N-1][W]);
    //for(int i = 0; i < )
}


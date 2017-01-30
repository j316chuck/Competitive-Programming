#include <iostream>
using namespace std;

int main()
{
unsigned long long N = 20;
unsigned long  long dp[N+1][N+1];

for (int i = 0; i <= N; ++i){
  dp[0][i] = 1;
  dp[i][0] = 1;
}

for (int i = 1; i <= N; ++i)
  for (int j = 1; j <= N; ++j) {
    dp[i][j] =  dp[i-1][j] + dp[i][j-1];
  }

unsigned long long answer = dp[N][N];
cout<<dp[N][N];

}

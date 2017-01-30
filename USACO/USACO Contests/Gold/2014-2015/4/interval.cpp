for(int len = 1; len <= n; len++) {
    for(int i = 0; i + len <= n; i++) {
        int j = i+len-1;
        dp[i][j] = -1;
        if(len == 1) {
            dp[i][j] = list[i];
        }
        for(int k = i; k < j; k++) {
            if(dp[i][k] == dp[k+1][j] && dp[i][k] > 0) {
                dp[i][j] = Math.max(dp[i][j], dp[i][k] + 1);
            }
        }
        ret = Math.max(ret, dp[i][j]);
    }
}

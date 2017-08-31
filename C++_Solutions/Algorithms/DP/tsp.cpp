void tsp ()
{
    memset(dp, 0x3f, sizeof(dp));
    for (int i = 0; i < n; i++) dp[1 << i][i] = 0;
    int m = 0;
    for (int i = 1; i < (1 << n); i++) {
        masks[m++] = i;
    }
    sort(masks, masks + m, comp);
    for (int i = 0; i < m; i++) {
        int msk = masks[i];
        for (int j = 0; j < n; j++) {
            if (dp[msk][j] > inf) continue;
            for (int k = 0; k < n; k++) {
                dp[msk | (1 << k)][k] = min(dp[msk | (1 << k)][k], dp[msk][j] + graph2[j][k]);
            }
        }
    }
    int ans = INF;
    for (int i = 0; i < n; i++) {
        ans = min(ans, dp[(1 << n) - 1][i]);
    }
    cout << ans << endl;
}


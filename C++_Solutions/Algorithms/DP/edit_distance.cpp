int editDistance(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();
        // for all i, j, dp[i][j] will hold the edit distance between the first
        // i characters of source string and first j characters of target string
        int dp[m + 1][n + 1];
        memset(dp, 0, sizeof(dp));
        // source can be transformed into target prefix by inserting
        // all of the characters in the prefix
        for (int i = 1; i <= n; i++) {
            dp[0][i] = i;
        }
        // source prefixes can be transformed into empty string by
        // by deleting all of the characters
        for (int i = 1; i <= m; i++) {
            dp[i][0] = i;
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1]; // no operation required as characters are the same
                }
                else {
                    dp[i][j] = 1 + min(dp[i - 1][j - 1],    // substitution
                            min(dp[i][j - 1],     // insertion
                                dp[i - 1][j]));    // deletion
                }
            }
        }
        return dp[m][n];
    }

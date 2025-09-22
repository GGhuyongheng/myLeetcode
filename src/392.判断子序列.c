/*
 * @lc app=leetcode.cn id=392 lang=c
 *
 * [392] 判断子序列
 */

// @lc code=start
// #include "myheader.h"

bool isSubsequence(char* s, char* t) {
    int m = strlen(s), n = strlen(t);
    int dp[m][n];
    memset(dp, 0, sizeof(dp));

    for (int i = 0; i < m; i++) {
        if (s[i] == t[0]) {
            while (i < m) dp[i++][0] = 1;
        }
    }

    for (int j = 0; j < n; j++) {
        if (t[j] == s[0]) {
            while (j < n) dp[0][j++] = 1;
        }
    }

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (s[i] == t[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = fmax(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[m - 1][n - 1] == m;
}
// @lc code=end


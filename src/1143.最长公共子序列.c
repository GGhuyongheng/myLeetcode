/*
 * @lc app=leetcode.cn id=1143 lang=c
 *
 * [1143] 最长公共子序列
 */

// @lc code=start

// dp[i][j] 表示text1[0, i]且text2[0, j]的最长公共子序列的长度
// 如果dp[i] = dp[j], dp[i][j] = dp[i-1][j-1] + 1;否则，dp[i][j] = max(dp[i-1][j], dp[i][j-1]);

#include "myheader.h"
int longestCommonSubsequence(char* text1, char* text2) {
    int m = strlen(text1), n = strlen(text2);
    int dp[m][n];
    memset(dp, 0, sizeof(dp));

    for (int i = 0; i < m; i++) {
        if (text1[i] == text2[0]) {
            while (i < m) dp[i++][0] = 1;
        }
    }

    for (int j = 0; j < n; j++) {
        if (text2[j] == text1[0]) {
            while (j < n) dp[0][j++] = 1;
        }
    }

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (text1[i] == text2[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = fmax(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[m - 1][n - 1];
}
// @lc code=end
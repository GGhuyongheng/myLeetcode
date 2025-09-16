/*
 * @lc app=leetcode.cn id=1035 lang=c
 *
 * [1035] 不相交的线
 */



// @lc code=start
int maxUncrossedLines(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int m = nums1Size, n = nums2Size;
    int dp[m][n];
    memset(dp, 0, sizeof(dp));

    for (int i = 0; i < m; i++) {
        if (nums1[i] == nums2[0]) {
            while (i < m) dp[i++][0] = 1;
        }
    }

    for (int j = 0; j < n; j++) {
        if (nums2[j] == nums1[0]) {
            while (j < n) dp[0][j++] = 1;
        }
    }

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (nums1[i] == nums2[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = fmax(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[m - 1][n - 1];
}
// @lc code=end


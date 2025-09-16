/*
 * @lc app=leetcode.cn id=392 lang=c
 *
 * [392] 判断子序列
 */

// @lc code=start
#include "myheader.h"

bool isSubsequence(char* s, char* t) {
    int i = 0, j = 0, m = strlen(s), n = strlen(t);
    while (i < m && j < n) {
        if (s[i] == t[j]) {
            i++;
        }

        j++;
    }

    if (i == m) return true;
    return false;
}
// @lc code=end


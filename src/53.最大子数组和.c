/*
 * @lc app=leetcode.cn id=53 lang=c
 *
 * [53] 最大子数组和
 */

// @lc code=start
int maxSubArray(int* nums, int numsSize) {
    int sum = 0, max = INT_MIN;
    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
        max = sum > max ? sum : max;
        if (sum < 0) {
            sum = 0;
            continue;
        }
    }

    return max;
}
// @lc code=end


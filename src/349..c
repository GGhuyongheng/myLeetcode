/*
 * @lc app=leetcode.cn id=349 lang=c
 *
 * [349] 两个数组的交集
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include "uthash.h"
#include <stdio.h>
#include <stdlib.h>

struct unordered_set {
    int key;
    UT_hash_handle hh;
};

void debug(struct unordered_set *set)
{
    struct unordered_set *p, *tmp;
    HASH_ITER(hh, set, p, tmp) {
        printf("%d ", p->key);
    }

    printf("\n");
}

struct unordered_set* find(struct unordered_set** hashtable, int ikey) {
    struct unordered_set* tmp;
    HASH_FIND_INT(*hashtable, &ikey, tmp);
    return tmp;
}

void insert(struct unordered_set** hashtable, int ikey) {
    struct unordered_set* tmp = find(hashtable, ikey);
    if (tmp != NULL) return;
    tmp = malloc(sizeof(struct unordered_set));
    tmp->key = ikey;
    debug(*hashtable);
    HASH_ADD_INT(*hashtable, key, tmp);
    debug(*hashtable);
}

int* getIntersection(struct unordered_set** set1, struct unordered_set** set2, int* returnSize) {
    if (HASH_COUNT(*set1) > HASH_COUNT(*set2)) {
        return getIntersection(set2, set1, returnSize);
    }
    int* intersection = malloc(sizeof(int) * (HASH_COUNT(*set1) + HASH_COUNT(*set2)));
    struct unordered_set *s, *tmp;
    HASH_ITER(hh, *set1, s, tmp) {
        if (find(set2, s->key)) {
            intersection[(*returnSize)++] = s->key;
        }
    }
    return intersection;
}

int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    *returnSize = 0;
    struct unordered_set *set1 = NULL, *set2 = NULL;
    for (int i = 0; i < nums1Size; i++) {
        insert(&set1, nums1[i]);
    }
    for (int i = 0; i < nums2Size; i++) {
        insert(&set2, nums2[i]);
    }

    return getIntersection(&set1, &set2, returnSize);
}

int main()
{
    int returnSize;
    int num1[] = {1, 2, 2, 4, 5, 6, 7, 8};
    int num2[] = {2, 3, 4};
    int *ret = intersection(num1, 8, num2, 3, &returnSize);
    
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", ret[i]);
    }
    
    system("pause");
    return 0;
}
// @lc code=end


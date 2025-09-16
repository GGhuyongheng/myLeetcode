/*
 * @lc app=leetcode.cn id=347 lang=c
 *
 * [347] 前 K 个高频元素
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include "myheader.h"

typedef struct Hash_Table {
    int key;
    int val;
    UT_hash_handle hh;
} Hash_Table;

typedef struct Hash_Table* Hash_Table_Ptr;

typedef struct Pair {
    int key;
    int val;
} Pair_t;

Pair_t *g_Heap = NULL;
int g_HeapSize = 0;

void Swap(Pair_t *x, Pair_t *s)
{
    Pair_t t = *x;
    *x = *s;
    *s = t;
}

void push(Hash_Table_Ptr p)
{
    g_Heap[++g_HeapSize].key = p->key;
    g_Heap[g_HeapSize].val = p->val;
    int x = g_HeapSize, s;
    while (x > 1) {
        s = x >> 1;
        if (g_Heap[x].val >= g_Heap[s].val) return;
        Swap(&g_Heap[x], &g_Heap[s]);
        x = s;
    }
}

void pop()
{
    if (g_HeapSize == 0) return;

    g_Heap[1] = g_Heap[g_HeapSize--];
    int x = 1, s;
    while ((s = x << 1) <= g_HeapSize) {
        if (s < g_HeapSize && g_Heap[s].val > g_Heap[s + 1].val) s++;
        if (g_Heap[x].val <= g_Heap[s].val) return;
        Swap(&g_Heap[x], &g_Heap[s]);
        x = s;
    }
}

int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {
    Hash_Table_Ptr g_HT = NULL;
    Hash_Table_Ptr p = NULL, tmp = NULL;

        for(int i = 0; i < numsSize; i++) {
            HASH_FIND(hh, g_HT, &nums[i], sizeof(int), p);
            if (p == NULL) {
                p = malloc(sizeof(Hash_Table));
                p->key = nums[i];
                p->val = 1;
                HASH_ADD(hh, g_HT, key, sizeof(int), p);
            } else {
                p->val++;
            }
        }

        g_Heap = malloc(sizeof(Pair_t) * (k + 1));
        HASH_ITER(hh, g_HT, p, tmp) {
            if (g_HeapSize == k) {
                if (p->val > g_Heap[1].val) {
                    pop();
                    push(p);
                }
            } else {
                push(p);
            }
        }
        
        int *res = malloc(sizeof(int) * k);
        *returnSize = k;
        for (int i = 0; i < k; i++) {
            res[i] = g_Heap[1].key;
            pop();
        }

        return res;
}
// @lc code=end


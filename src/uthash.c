#include "uthash.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct Treenode *right;
} TreeNode, *TreeNodePtr;

TreeNodePtr g_myTree;

typedef struct Stack {
    TreeNodePtr arr[1000];
    int top;
} Stack;

Stack g_treeStack;
int g_result[1000], g_index;

void InorderTraversal(TreeNodePtr root)
{
    g_treeStack.arr[g_treeStack.top++] = root;
    while (g_treeStack.top) {
        TreeNodePtr tmp = g_treeStack.arr[g_treeStack.top - 1];
        while (tmp->left != NULL) {
            g_treeStack.arr[g_treeStack.top++] = tmp->left;
            tmp = tmp->left;
        }

        g_result[g_index++] = tmp->val;
        tmp = g_treeStack.arr[--g_treeStack.top];

        if (tmp->right != NULL) {
            g_treeStack.arr[g_treeStack.top++] = tmp->right;
        } else {

        }
    }
}

typedef struct Set {
    int key;
    UT_hash_handle hh;
} UnorderedSet;

void debug(UnorderedSet *set)
{
    UnorderedSet *p, *tmp;
    HASH_ITER(hh, set, p, tmp) {
        printf("%d ", p->key);
    }

    printf("\n");
}

UnorderedSet *Find(UnorderedSet *hashTable, int iKey)
{
    UnorderedSet *tmp = NULL;
    HASH_FIND(hh, hashTable, &iKey, sizeof(int), tmp);
    return tmp;
}

void Insert(UnorderedSet **hashTable, int iKey)
{
    UnorderedSet *tmp = Find(*hashTable, iKey);
    if (tmp != NULL) {
        return;
    }

    tmp = malloc(sizeof(UnorderedSet));
    tmp->key = iKey;
    HASH_ADD(hh, *hashTable, key, sizeof(int), tmp);
}

int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize)
{
    *returnSize = 0;
    UnorderedSet *set1 = NULL, *set2 = NULL, *p, *tmp;
    for (int i = 0; i < nums1Size; i++) {
        Insert(&set1, nums1[i]);
    }

    for (int i = 0; i < nums2Size; i++) {
        Insert(&set2, nums2[i]);
    }

    int length = HASH_COUNT(set1) > HASH_COUNT(set2) ? HASH_COUNT(set1) : HASH_COUNT(set2);
    int *ret = malloc(sizeof(int) *length);
    HASH_ITER(hh, set1, p, tmp) {
        if (Find(set2, p->key)) {
            ret[(*returnSize)++] = p->key;
        }
    }

    return ret;
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
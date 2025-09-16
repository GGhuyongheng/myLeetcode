#include <stdio.h>
#include <stdlib.h>

typedef struct List {
    int val;
    struct List *next;
} List;

List *ReverseList(List *head)
{
    List *cur = head->next, *prev = head;
    while (cur != NULL) {
        List *tmp = cur->next;
        cur->next = prev;
        if (prev == head) {
            prev->next = NULL;
        }

        prev = cur;
        cur = tmp;
    }

    return prev;
}

int factorial(int n)
{
	if (n == 0)
		return 1;
	else {
		int recurse = factorial(n-1);
		int result = n * recurse;
		return result;
	}
}

void main()
{
    int res = factorial(8);

    List *head = NULL;
    List *dummyNode = (List *)malloc(sizeof(List));
    dummyNode->next = NULL;
    int arr[] = {10, 8, 6, 4, 2};
    List *cur = dummyNode;
    for (int i =0; i < sizeof(arr) / sizeof(arr[0]); i++) {
        cur->next = (List *)malloc(sizeof(List));
        if (cur->next == NULL) return;
        cur->next->val = arr[i];
        cur->next->next = NULL;
        cur = cur->next;
    }

    head = dummyNode->next;
    List *result = ReverseList(head);
    while (result != NULL) {
        printf("%d ", result->val);
        result = result->next;
    }

    printf("\n");
    system("pause");
}
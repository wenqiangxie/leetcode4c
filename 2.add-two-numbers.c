/*
 * @lc app=leetcode id=2 lang=c
 *
 * [2] Add Two Numbers
 */

#include <stdio.h>
#include <stdlib.h>

/* singly-linked list node */
struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2);

int main()
{
    /* array of input */
    int l1Arr[] = {9, 9, 9, 9, 9, 9, 9};
    int l2Arr[] = {9, 9, 9, 9};

    /* transform input from array list to linked list */
    struct ListNode *l1 = NULL, *l2 = NULL, *p1 = NULL, *p2 = NULL, *p;

    for (int ii = 0; ii < sizeof(l1Arr) / sizeof(int); ii++)
    {
        struct ListNode *p = (struct ListNode *)malloc(sizeof(struct ListNode));
        p->next = NULL;
        p->val = l1Arr[ii];

        if (NULL == l1)
        {
            l1 = p1 = p;
        }
        else
        {
            p1->next = p;
            p1 = p1->next;
        }
    }

    for (int ii = 0; ii < sizeof(l2Arr) / sizeof(int); ii++)
    {
        p = (struct ListNode *)malloc(sizeof(struct ListNode));
        p->next = NULL;
        p->val = l2Arr[ii];

        if (NULL == l2)
        {
            l2 = p2 = p;
        }
        else
        {
            p2->next = p;
            p2 = p2->next;
        }
    }

    /* run test function */
    struct ListNode *result = p = addTwoNumbers(l1, l2);

    /* print test result */
    while (NULL != p)
    {
        printf("%d\t", p->val);
        p = p->next;
    }

    return 0;
}

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
    /* this slution is inplace, l1 linked list will be return which store answer */
    /* if l1 linked list is shorter than l2 linked list, the elements of l2 longer */
    /* than l1 will be cut and append to l1, so l1 never be NULL or should be end */
    struct ListNode *p1 = l1, *p2 = l2, *phead = NULL, *p3 = NULL;
    while (p1 != NULL)
    {
        /* l1 and l2, calculate sum of those elements in custom */
        if (p2 != NULL)
        {
            p1->val = p1->val + p2->val;
        }

        /* try to find that current l1 node is max than 9, if yes, try to add to next node, */
        /* or no, do nothing */
        if (p1->val > 9)
        {
            /* l1 doesn't have next node after current node, a new node should be created */
            if (p1->next == NULL)
            {
                p1->next = (struct ListNode *)malloc(sizeof(struct ListNode));
                p1->next->val = 0;
                p1->next->next = NULL;
            }

            /* modify value of current node and next node */
            p1->next->val = p1->next->val + (p1->val / 10);
            p1->val = p1->val - 10 * (p1->val / 10);
        }

        /* if l1 is shorted than l2(in current node, l1 doesn't have next node but l2 do), */
        /* try to cut nodes from l2 and append to l1 */
        if (p1 != NULL && p2 != NULL && p1->next == NULL && p2->next != NULL)
        {
            p1->next = p2->next;
            p2 = NULL;
        }

        /* l1 and l2 move next from current node */
        if (p1 != NULL)
        {
            p1 = p1->next;
        }

        if (p2 != NULL)
        {
            p2 = p2->next;
        }
    }

    /* return result */
    return l1;
}
// @lc code=end

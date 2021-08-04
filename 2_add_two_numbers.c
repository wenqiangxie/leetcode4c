/**
 * 2. Add Two Numbers
 *
 * https://leetcode.com/problems/add-two-numbers/
 *
 * Runtime: 12 ms, faster than 81.43% of C online submissions for Add Two Numbers.
 * Memory Usage: 7.1 MB, less than 99.62% of C online submissions for Add Two Numbers.
 */
 
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *p1 = l1, *p2=l2, *phead = NULL, *p3 = NULL;
    while(p1 != NULL){
        if(p2 != NULL){
            p1->val = p1 ->val + p2->val;
        }
        
        if(p1->val > 9){
            if(p1->next == NULL){
                p1->next = (struct ListNode*)malloc(sizeof(struct ListNode));
                p1->next->val = 0;
                p1->next->next = NULL;
            }
            
            p1->next->val = p1->next->val + (p1->val / 10);
            p1->val = p1->val - 10 * (p1->val / 10);
        }

        if(p1 != NULL && p2 != NULL && p1->next == NULL && p2->next != NULL){
            p1->next = p2 -> next;
            p2 = NULL;
        }
        
        if(p1 != NULL){
            p1 = p1->next;
        }
        
        if(p2 != NULL){
            p2 = p2 ->next;
        }
    }
        
    return l1;
}

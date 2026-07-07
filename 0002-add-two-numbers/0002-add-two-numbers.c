#include <stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * struct ListNode *next;
 * };
 */

// Prototype for the recursive helper function
struct ListNode* addTwoNumbersRecursion(struct ListNode* l1, struct ListNode* l2, int remainder);

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    return addTwoNumbersRecursion(l1, l2, 0);
}

struct ListNode* addTwoNumbersRecursion(struct ListNode* l1, struct ListNode* l2, int remainder)
{
    if (l1 == NULL && l2 == NULL)
    {
        if (remainder != 0)
        {
            struct ListNode* ret = malloc(sizeof(struct ListNode));
            ret->val = remainder;
            ret->next = NULL;
            return ret;
        }
        return NULL;
    }

    else if (l1 == NULL)
    {
        int value = l2->val + remainder;
        l2->val = value % 10;
        l2->next = addTwoNumbersRecursion(NULL, l2->next, value / 10);
        return l2;
    }   

    else if (l2 == NULL)
    {
        int value = l1->val + remainder;
        l1->val = value % 10;
        l1->next = addTwoNumbersRecursion(l1->next, NULL, value / 10);
        return l1;
    }
    
    else
    {
        int value = l1->val + l2->val + remainder;

        struct ListNode* ret = malloc(sizeof(struct ListNode));
        ret->val = value % 10;
        ret->next = addTwoNumbersRecursion(l1->next, l2->next, value / 10);
        return ret;
    }
}
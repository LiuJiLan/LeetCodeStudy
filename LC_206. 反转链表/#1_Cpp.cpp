//2020.09.09

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


//递归法
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        return reverse(NULL,head);
    }
    
    ListNode* reverse(ListNode* pre, ListNode* cur) {
        if (cur == NULL) {
            return pre;
        }
        
        ListNode* temp = cur->next;
        cur->next = pre;
        
        return reverse(cur,temp);
    }
};


//原题
/*
class Solution {
public:
    ListNode* reverseList(ListNode* head) {

    }
};
*/

//迭代-同速双指针法
/*

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        
        struct ListNode * pre = NULL ,* cur = head ,* temp = NULL;//val temp:NULL for safety
        
        while (cur != NULL) {
            temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }
        
        return pre;        
    }
};

*/
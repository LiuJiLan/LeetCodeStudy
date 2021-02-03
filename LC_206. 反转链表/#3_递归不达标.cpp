//2020.09.11_#3_递归不达标

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        return reverse(NULL, head);
    }
    
    ListNode * reverse(ListNode * pre, ListNode * cur) {
        //if statement both secure cur == head and cur == NULL two situations
        if (cur == NULL) {
            return pre;
        }
        
        ListNode * temp = cur->next;
        cur->next = pre;
        
        return reverse(cur, temp);
    }
}; 

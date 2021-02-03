//2020.11.02_#7_递归达标

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    ListNode * recursion(ListNode * pre, ListNode * cur) {
        if (cur == NULL) {
            return pre;
        }
        
        ListNode * temp = cur->next;
        cur->next = pre;
    
        return recursion(cur, temp);
    }
public:
    ListNode* reverseList(ListNode* head) {
        return recursion(NULL, head);
    }
};

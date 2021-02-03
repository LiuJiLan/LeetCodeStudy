//2020.11.26_#9_递归达标

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
    ListNode * reverse(ListNode * pre, ListNode * cur) {
        if (cur == NULL) {
            return pre;
        }
        ListNode * temp = cur->next;
        cur->next = pre;
        return reverse(cur, temp);
    }
    
public:
    ListNode* reverseList(ListNode* head) {
        return reverse(NULL, head);
    }
};

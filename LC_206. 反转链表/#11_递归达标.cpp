//2021.01.30_#11_递归达标

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
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

//2020.10.08_#5_递归达标

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
    ListNode * ans;
    
    void recursion(ListNode * pre, ListNode * cur) {
        if (cur == NULL) {
            ans = pre;
            return;
        }
        
        ListNode * temp = cur->next;
        cur->next = pre;
        
        recursion(cur, temp);
    }
    
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL) {
            return NULL;
        }
        
        recursion(NULL, head);
        
        return ans;
    }
};

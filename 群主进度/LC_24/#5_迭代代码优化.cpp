//2020.09.11_#5_迭代代码优化

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
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        
        ListNode * cur = head;
        ListNode * newHead = head->next;
        ListNode * temp = head;
        //set temp as for temp->next = cur->next safely
        
        do {
            temp->next = cur->next;
            temp = cur;
            cur = cur->next;
            temp->next = cur->next;
            cur->next = temp;
            cur = temp->next;
            
        } while (cur != NULL && cur->next != NULL);
        
        return newHead;
        
    }
};
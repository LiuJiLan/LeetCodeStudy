//2020.09.16_#6_迭代不达标

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
        
        ListNode * newHead = head->next;
        ListNode * cur = head;
        ListNode * temp = head;//set temp to head for safety
        
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
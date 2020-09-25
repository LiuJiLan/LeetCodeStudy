//2020.09.18_#8_达标

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
        ListNode * node = head, * temp = head;
        
        do {
            temp->next = node->next;
            temp = node;
            node = node->next;
            temp->next = node->next;
            node->next = temp;
            node = temp->next;
        } while (node != NULL && node->next != NULL);
        
        return newHead;
    }
};
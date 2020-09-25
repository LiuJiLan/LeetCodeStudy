//2020.09.19_#9_达标

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
            temp = node->next;
            node->next = temp->next;
            temp->next = node;
            temp = node;
            node = node->next;
        } while (node != NULL && node->next != NULL);
        
        return newHead;
    }
};
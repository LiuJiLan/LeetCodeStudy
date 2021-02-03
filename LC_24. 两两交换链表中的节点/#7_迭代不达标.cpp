//2020.09.17_#7_迭代不达标

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
        
        ListNode * newHead = head->next, * node = head, * temp = head;
        //set temp to head for safety
        
        do {
            temp->next = node->next;
            temp = node;
            node = node->next;
            temp->next = node->next;
            node->next = temp;
            node = temp->next;
        } while (node && node->next);
        
        
        return newHead;
    }
};
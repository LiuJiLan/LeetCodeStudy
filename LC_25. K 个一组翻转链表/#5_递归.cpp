//2020.09.24_#5_递归

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int count = 0;
        ListNode * node = head;
        
        while (node != NULL && count != k) {
            node = node->next;
            count++;
        }
        
        if (count == k) {
            node = reverseKGroup(node, k);
            
            while (count-- > 0) {
                ListNode * temp = head->next;
                head->next = node;
                node = head;
                head = temp;
            }
            
            return node;
        }
        
        return head;
    }
};

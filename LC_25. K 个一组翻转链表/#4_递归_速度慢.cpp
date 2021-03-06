//2020.09.21_#4_递归_速度慢

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
        ListNode * node = head;
        int count = 0;
        
        while (node != NULL && count < k) {
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

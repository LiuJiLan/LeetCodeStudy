//2020.11.14_#7_递归

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
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL || k == 0) {
            return head;
        }
        
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

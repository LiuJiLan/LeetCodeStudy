//2020.09.10_#2
//写慢了，代码也写长了，重写

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//递归法
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        return reverse(head);
    }
    
    ListNode * reverse(ListNode * node) {
        if (node == NULL || node->next == NULL) {
            return node;
        }
        
        ListNode * temp = node;
        node = node->next;
        temp->next = reverse(node->next);
        node->next = temp;
        
        return node;
    }
};
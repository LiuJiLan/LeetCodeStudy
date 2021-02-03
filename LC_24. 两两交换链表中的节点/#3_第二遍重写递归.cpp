//2020.09.10_#3 第二遍重写递归

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
        return reverse(head);
    }
    
    ListNode* reverse(ListNode* node) {
        if (node == NULL || node->next == NULL) {
            return node;
        }
        
        ListNode* newNode = node->next;
        node->next = reverse(newNode->next);
        newNode->next = node;
        
        return newNode;
    
    }
};
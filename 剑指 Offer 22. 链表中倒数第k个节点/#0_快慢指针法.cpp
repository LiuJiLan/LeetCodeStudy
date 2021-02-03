//2020.10.13_#0_快慢指针法

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
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode * fast = head, * slow = head;
        
        for (int i = 0; i < k; i++) {
            fast = fast->next;
        }
        
        while (fast != NULL) {
            fast = fast->next;
            slow = slow->next;
        }
        
        //不能用do-while,会出现错误
        //do {
        //    fast = fast->next;
        //    slow = slow->next;
        //} while (fast != NULL);
        
        return slow;
    }
};

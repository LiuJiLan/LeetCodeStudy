//2020.11.02_#5_达标

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
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL || head->next == NULL) {
            return NULL;
        }
        
        ListNode * slow = head, * fast = head;
        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if (fast == slow) {
                ListNode * thirdNode = head;
                while (thirdNode != slow) {
                    slow = slow->next;
                    thirdNode = thirdNode->next;
                }
                return thirdNode;
            }
        }
        
        return NULL;
    }
};

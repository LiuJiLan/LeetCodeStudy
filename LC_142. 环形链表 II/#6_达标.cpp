//2020.11.26_#6_达标

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
        if (head == NULL) {
            return NULL;
        }
        ListNode * slow = head, * fast = head;
        while (fast->next != NULL && fast->next->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) {
                ListNode * thirdNode = head;
                while (thirdNode != slow) {
                    thirdNode = thirdNode->next;
                    slow = slow->next;
                }
                return thirdNode;
            }
        }
        return NULL;
    }
};

//2020.09.12_#2_达标

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
        else if (head->next == head) {
            return head;
        }
        
        ListNode * fast = head, * slow = head;
        
        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
            
            if (fast == slow) {
                ListNode * thirdNode = head;
                
                while (slow != thirdNode) {
                    slow = slow->next;
                    thirdNode = thirdNode->next;
                }
                
                return thirdNode;
            }
        }
        
        return NULL;
        
    }
};
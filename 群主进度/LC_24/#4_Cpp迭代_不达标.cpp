//2020.09.10_#4_迭代法不达标


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
        
        ListNode * oldPre = head, * newPre = NULL;//set newPre NULL for safety
        
        while(oldPre != NULL) {
                        
            ListNode* tempThird = oldPre->next->next;
            newPre = oldPre->next;
            newPre->next = oldPre;
            oldPre = tempThird;
            
        }
        
        return newPre;
    }
};
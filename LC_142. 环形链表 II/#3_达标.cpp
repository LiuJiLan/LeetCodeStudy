//2020.09.18_#3_达标

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
        
        ListNode * s = head, * f = head;
        
        while (f->next != NULL && f->next->next != NULL) {
            s = s->next;
            f = f->next->next;
            
            if (s == f) {
                ListNode * thirdPoint = head;
                
                while (thirdPoint != s) {
                    thirdPoint = thirdPoint->next;
                    s = s->next;
                }
                
                return thirdPoint;
            }
        }
        
        return NULL;
        
    }
};
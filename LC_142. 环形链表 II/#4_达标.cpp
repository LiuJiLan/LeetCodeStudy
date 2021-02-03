//2020.10.09_#4_达标

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
        ListNode * s = head, * f = head;
        while (f->next != NULL && f->next->next != NULL) {
            s = s->next;
            f = f->next->next;
            
            if (s == f) {
                ListNode * thirdPoint = head;  //Just for safety
                while (thirdPoint != s) {
                    s = s->next;
                    thirdPoint = thirdPoint->next;
                }
                return s;
            }
        }
        
        return NULL;
    }
};

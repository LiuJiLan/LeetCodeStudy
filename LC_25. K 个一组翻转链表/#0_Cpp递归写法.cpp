//2020.09.12_#0_Cpp递归写法

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode * cur = head;
        int count = 0;
        
        while (cur != NULL && count != k) {
            cur = cur->next;
            count++;
        }
        
        if (count == k) {
            cur = reverseKGroup(cur, k);
            
            while (count-- > 0) {
                ListNode * temp = head->next;
                head->next = cur;
                cur = head;
                head = temp;
            }
            
            head = cur;
        }
        return head;
    }
};


//Java递归写法
/*
public ListNode reverseKGroup(ListNode head, int k) {
    ListNode curr = head;
    int count = 0;
    while (curr != null && count != k) { // find the k+1 node
        curr = curr.next;
        count++;
    }
    if (count == k) { // if k+1 node is found
        curr = reverseKGroup(curr, k); // reverse list with k+1 node as head
        // head - head-pointer to direct part, 
        // curr - head-pointer to reversed part;
        while (count-- > 0) { // reverse current k-group: 
            ListNode tmp = head.next; // tmp - next head in direct part
            head.next = curr; // preappending "direct" head to the reversed list 
            curr = head; // move head of reversed part to a new node
            head = tmp; // move "direct" head to the next node in direct part
        }
        head = curr;
    }
    return head;
}
*/
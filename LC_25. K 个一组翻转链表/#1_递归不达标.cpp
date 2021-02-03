//2020.09.12_#1_递归不达标

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
        //In the following program
        //node set as the previous one of the head
        //head just like another temp
        //node head temp -> pre cur next
        
        ListNode * node = head;
        int count = 0;
        
        while (node != NULL && count != k) {
            node = node->next;
            count++;
        }
        
        
        
        if (count == k) {
            //count == k才能进行递归
            //now node is the k+1 one
            node = reverseKGroup(node, k);
            
        //while (count-- > 0) 可以计数conut次并把count归零
        while (count-- > 0) {
            ListNode * temp = head->next;
            head->next = node;
            node = head;//node变成现在的head
            head = temp;
        }
            return node;
            
        }
        
        
        
        return head;
    }
};
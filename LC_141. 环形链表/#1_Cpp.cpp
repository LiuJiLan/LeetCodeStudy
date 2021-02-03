//2020.09.09

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
    bool hasCycle(ListNode *head) {
        if (head == NULL || head->next ==NULL) {
            return false;
        }
        
        ListNode* slow = head, * fast = head;
        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow ->next;
            fast = fast->next->next;
            
            if(slow == fast) {
                return true;
            }
        }
        
        return false;
    }
};

/*
//标答
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL || head -> next == NULL)    //先判断是否为空或者是否只含有一个元素
            return false;
 
        ListNode *fast = head;
        ListNode *slow = head;
        
        //其实只用考虑快指针
        while(fast -> next && fast -> next -> next){
            fast = fast -> next -> next;
            slow = slow -> next;
            if(fast == slow)
                return true;
        }
 
        return false;
    }
};
*/
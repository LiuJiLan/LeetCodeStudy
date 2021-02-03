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
        
        ListNode * cur = head;
        ListNode * newHead = head->next;
        
        while (cur != NULL && cur->next != NULL) {
            ListNode * temp = cur;//这里temp是原来第一节点,现在第二节点
            cur = cur->next;//这里cur是原来第二节点，现在第一节点
            
            //这里的temp->next实际上是(oringin)head->neaxt->next,
            //相当于原第三个节点
            temp->next = cur->next;//将原第一节点和第三节点链接
            cur->next = temp;//将现在的第一节点跟现在第二节点链接
            
            cur = temp->next;//cur现在变化为第三节点
            
            //本质上的变化只能在前三个节点进行讨论，因为不知道第三节点会不会是NULL
            
            if (cur != NULL && cur->next != NULL) {
                temp->next = cur->next;//将原第四节点接到现第二节点后面
            }
        }
        
        return newHead;
        
       
    }
    
};




//原题
/*
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
       
    }
    
};
*/

//#1_递归
/*
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if ((head == NULL) || (head->next == NULL)) {
            return head;
        }
        
        ListNode * newHead = head->next;
        
        //现在的head其实是第二节点
        //head->next->next仍然是之前的第三节点
        head->next = swapPairs(head->next->next);
        
        newHead->next = head;
        
        return newHead;
    }
    
};
*/


//递归法_JAVA
/*
public class Solution {
    public ListNode swapPairs(ListNode head) {
        if ((head == null)||(head.next == null))
            return head;
        ListNode n = head.next;
        head.next = swapPairs(head.next.next);
        n.next = head;
        return n;
    }
}
*/

//迭代法_JAVA
/*
public class Solution {
    public ListNode swapPairs(ListNode head) {
        if (head == null || head.next == null) return head;
        ListNode cur = head;
        ListNode newHead = head.next;
        while (cur != null && cur.next != null) {
            ListNode tmp = cur;
            cur = cur.next;
            tmp.next = cur.next;
            cur.next = tmp;
            cur = tmp.next;
            if (cur != null && cur.next != null) tmp.next = cur.next;
        }
        return newHead;
    }
}
*/
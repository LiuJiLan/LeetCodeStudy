//2021.02.04_#15_递归_更好的方法

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if ((head == NULL) || (head->next == NULL)) {
            return head;
        }
            
        ListNode * node = head->next;
        head->next = swapPairs(head->next->next);
        node->next = head;
        return node;
    }
};

#if 0
// MostVotes_Java

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

#endif

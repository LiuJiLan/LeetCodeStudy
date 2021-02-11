//2020.11.27_#14_迭代_慢了

//这里注意一定记住temp->next = node->next;
//另外注意node和temp可以用head来省一个

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
        if (head == NULL || head->next == NULL) {
            return head;
        }
        
        ListNode * newHead = head->next;
        ListNode* node = head;
        ListNode * temp = head;
        do {
            temp->next = node->next;
            temp = node->next->next;
            node->next->next = node;
            node->next = temp;
            temp = node;
            node = node->next;
        } while (node != NULL && node->next != NULL);
        return newHead;
    }
};

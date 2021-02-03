//2020.11.02_#11_递归自己探索

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
private:
    ListNode * recursion(ListNode * node) {
        if (node == NULL || node->next == NULL) {
            return node;
        }
        
        ListNode * cur = node, * nex = node->next;
        //We can reuse node as nex to spare space
        ListNode * temp = nex->next;
        nex->next = cur;
        cur->next = recursion(temp);
        
        return nex;
    }
    
public:
    ListNode* swapPairs(ListNode* head) {
        return recursion(head);
    }
};

#if 0
//  变量精简
class Solution {
private:
    ListNode * recursion(ListNode * node) {
        if (node == NULL || node->next == NULL) {
            return node;
        }
        
        ListNode * nex = node->next;
        ListNode * temp = nex->next;
        nex->next = node;
        node->next = recursion(temp);
        
        return nex;
    }
    
public:
    ListNode* swapPairs(ListNode* head) {
        return recursion(head);
    }
};

#endif

#if 0
// 函数精简
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        
        ListNode * nex = head->next;
        ListNode * temp = nex->next;
        nex->next = head;
        head->next = swapPairs(temp);
        
        return nex;
    }
};


#endif

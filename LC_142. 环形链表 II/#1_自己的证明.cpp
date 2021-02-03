//2020.09.11_#1_自己的证明

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/*
数学证明：

前提：环存在

设起点到环的链接点为L
设环的周长为C

当fast指针到达环的衔接点时，S(fast) = L+C
此时S(slow) = (L+C)/2
即：slow指针走出环的衔接点 = (L+C)/2-L = (C-L)/2

//证明:S(slow) <= L + C
此时有极端情况：L=0，C=1
即：head->next == head 为true
再次极端条件下slow到达环的衔接点，
即：S(slow) = L + C;
由此可得一般情况下slow指针没有走完环。

这时：假设slow再走出x与fast相遇，
即：此时fast由环的衔接点再走出2x
有：(C-L)/2 + x = 2x
可得相遇点为环的衔接点再走出(C-L)
即：距离换的衔接点(另一段弧)为L

所以当fast和slow相遇时，第三个指针从head出发，
当slow继续前进达到环的衔接点时(由于S(第三指针)=L，即：S(第三指针) == S(slow)时)，
就是第三指针到达环的衔接点时候

*/

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL || head->next == NULL) {
            return NULL;
        }
        else if (head == head->next) {
            return head;
        }
        
        ListNode * fast = head, * slow = head;
        while(fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;

            if (fast == slow) {
                ListNode * thirdPoint = head;
                while (thirdPoint != slow) {
                    slow = slow->next;
                    thirdPoint = thirdPoint->next;
                }
                return thirdPoint;
            }
        }
        
        return NULL;
    }
};
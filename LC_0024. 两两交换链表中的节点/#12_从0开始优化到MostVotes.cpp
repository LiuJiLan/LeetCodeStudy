//2020.11.02_#12_从0开始优化到MostVotes

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        
        ListNode * newHead = head->next;
        ListNode * nex = head->next;
        ListNode * temp = nex->next;
        
        while (head != NULL && head->next != NULL) {
            // 注意这个地方可以通过改为do-while优化
            nex = head->next;
            temp = nex->next;
            nex->next = head;
            // 这个写法的精确时间复杂度跟BestVotes迭代代码一致
            // BestVotes运用了巧妙的方法,此方法用的是if判断
            // (假设if判断占一拍的时间)
            if (temp != NULL) {
                head->next = temp->next;
            } else {
                head->next = temp;
            }
            head = temp;
        }
        
        return newHead;
    }
};


#if 0
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        
        ListNode * newHead = head->next;
        
        do {
            ListNode * nex = head->next;
            ListNode * temp = nex->next;
            nex->next = head;
            if (temp != NULL) {
                // 条件不能是temp != NULL,而是head != NULL && head->next != NULL
                // 所以可以还原使用while
                // 然后直接判断temp(因为 head = temp;)
                // (其实最后发现还是能用do-while)
                head->next = temp->next;
            } else {
                head->next = temp;
            }
            head = temp;
        } while (head != NULL && head->next != NULL);
        
        return newHead;
    }
};

#endif

#if 0

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        
        ListNode * newHead = head->next;
        ListNode * nex = head;  //令nex为head是非常重要的
        ListNode * temp = NULL;  //temp的初值会比较随意
        
        do {
            nex->next = head->next;  // 来自于上一次循环的末尾,所以首次循环前的nex值设置非常重要
            nex = head->next;
            temp = nex->next;
            nex->next = head;
            nex = head;  // 利用循环后半段不用的nex把head存起来
            head->next = temp;
            head = temp;
            // 这种写法比最佳写法多了一行,实际上head = temp;是不需要的
            // 直接将在判断条件中使用temp就行了
        } while (head != NULL && head->next != NULL);
        
        return newHead;
    }
};

#endif

#if 0
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        
        ListNode * newHead = head->next;
        ListNode * nex = head;
        ListNode * temp = head;  //这个改进之后temp也必须提前付初值
        
        do {
            nex->next = temp->next;  //注意此行由head->next变为temp->next
            nex = temp->next;  //注意此行由head->next变为temp->next
            
            //temp = nex->next;
            //temp的角色始终是储存下一个循环开始节点的位置
            //但是此处不能将temp赋值,此处的temp内容还没有将本身的1号为交到nex->next手上
            //解决方法就是利用temp的next节点去储存下一个循环开始节点
            temp->next = nex->next;  //此时的temp还是本身的1号节点
            //那么注意在这temp的next节点恰好储存了下一个循环开始节点
            //所以原来循环的最后一句话head->next = temp;可以废除
            
            nex->next = temp;
            nex = temp;  //此处仍要让nex存储1号位,只不过此时的1号位是temp
            temp = temp->next;  //此时将存贮在temp->next中的3号位(下一个循环开始节点)交给temp
        } while (temp != NULL && temp->next != NULL);
        
        //这就很有趣了,因为只使用了temp和nex
        //head没有被利用,还可以改进
        
        return newHead;
    }
};
#endif

#if 0
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        
        ListNode * newHead = head->next;
        ListNode * nex = head;
        
        do {
            nex->next = head->next;
            nex = head->next;
            head->next = nex->next;
            nex->next = head;
            nex = head;
            head = head->next;
        } while (head != NULL && head->next != NULL);
        return newHead;
    }
};
#endif


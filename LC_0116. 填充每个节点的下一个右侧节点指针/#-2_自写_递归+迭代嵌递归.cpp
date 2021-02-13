//2021.02.13_#-2_自写_递归+迭代嵌递归

// v1
//
// 1                      A
//                      /   \
//                    /       \
// 2                B           C
//                 / \         / \
// 3             E     F     G     H
//              / \   / \   / \   / \
// 4           H   I J   K L   M N   O
//
// 5                  NULL
//

//
// 难点其实和单向链表一样:
// 最难的是找父节点,和父节点的父节点.
// 如果层序遍历,信息存在了queue中,
// 如果遍历其实是是用栈来维护中间信息的储存.
//

//
// 尝试找了各种递归规律,
// 会发现随着整个树的深度加深,
// 始终没法在类似 B-C F-G K-L 这些部分用很好的递归方式解决
// 那么不妨换一个思路,
// 在那些像那样的倒水滴区域使用迭代的方法.
//
// 1                                  R
//                                  /   \
//                                /       \
//                              /           \
//                            /               \
//                          /                   \
// 2                      A                       a
//                      /   \                   /   \
//                    /       \               /       \
// 3                B           C           b           c
//                 / \         / \         / \         / \
// 4             D     E     F     G     d     e     f     g
//              / \   / \   / \   / \   / \   / \   / \   / \
// 5           H   I J   K L   M N   O h   i j   k l   m n   o
//
// 6                                 NULL
//
// 1                                  R
//                                  /   \
//                                /       \
//                              /           \
//                            /               \
//                          /                   \
// 2                      A                       a
//                      /   \                   /   \
//                    /       \               /       \
// 3                B           #           #           c
//                 / \         / \         / \         / \
// 4             D     E     F     #     #     e     f     g
//              / \   / \   / \   / \   / \   / \   / \   / \
// 5           H   I J   K L   M N   # #   i j   k l   m n   o
//
// 6                                 NULL
//
// 如图中“#”的位置
// 那这样就很容易产生递归效应:
//
// 1                                  R
//                                  /   \
//                                /       \
//                              /           \
//                            /               \
//                          /                   \
// 2                      A                       a
//                      /   \                   /   \
//                    /       \               /       \
// 3                B           C           b           c
//                 / \         / \         / \         / \
// 4             D     #     #     G     d     #     #     g
//              / \   / \   / \   / \   / \   / \   / \   / \
// 5           H   I J   # #   M N   O h   i j   # #   m n   o
//
// 6                                 NULL
//
// 如图中“#”的位置
//


// v2
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
private:
    void recursion(Node * node) {
        if (node == NULL || node->left == NULL) {
            return;
        }
        
        // connect two son
        node->left->next = node->right;
        
        // connect the gaps
        Node * leftGap = node->left->right;
        Node * rightGap = node->right->left;
        while (leftGap != NULL) {  //  do-while改while可以省去一个if
            leftGap->next = rightGap;
            
            leftGap = leftGap->right;
            rightGap = rightGap->left;
        }
        
        // drill down
        recursion(node->left);
        recursion(node->right);
    }
    
public:
    Node* connect(Node* root) {
        recursion(root);
        return root;
    }
};



#if 0
// v1

class Solution {
private: // 尽管我已经预测到不需要分两个函数, 但为了方便自己阅读, v1把两个递归分开
    void connectTwoSon(Node * node) {
        if (node == NULL || node->left == NULL) {
            return;
        }
        
        node->left->next = node->right;
        connectTwoSon(node->left);
        connectTwoSon(node->right);
    }
    
    void connectGap(Node * node) {
        if (node == NULL || node->left == NULL || node->left->left == NULL) {
            return;
        }
        
        Node * leftGap = node->left->right;
        Node * rightGap = node->right->left;
        do {
            leftGap->next = rightGap;
            
            leftGap = leftGap->right;
            rightGap = rightGap->left;
        } while (leftGap != NULL);
        
        connectGap(node->left);
        connectGap(node->right);
    }
    
public:
    Node* connect(Node* root) {
        connectTwoSon(root);
        connectGap(root);
        return root;
    }
};

#enfif

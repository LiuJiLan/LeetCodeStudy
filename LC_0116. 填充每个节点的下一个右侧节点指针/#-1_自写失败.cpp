//2021.02.13_#-1_自写失败

//
// 此题一般想法是做层序遍历, 但这样空间复杂度会是O(N)
// 如果以递归的思想来看,有两大必要操作:
// 链接同一个父节点的两个子节点(其实有逻辑漏洞)
// 链接两个三角形子树
//
// 但是这道题的题设是有问题的:
// “你只能使用常量级额外空间。”
// “使用递归解题也符合要求，本题中递归程序占用的栈空间不算做额外的空间复杂度。”
// 但其实,站在BFS和DFS的角度上来看,栈的空间并不能忽略不计.
// 所以说看上去直接的层序遍历和用递归的空间复杂度并不会有很大的区别.
// 题目还设有前提, 表示是一个“完美二叉树”(树是全满的)
// 这明显就是为了使用递归而设计的, 如果只是一颗“完全二叉树”递归方法中要讨论的点就太多了
//
// 综上所述,这是一道经过精心设计的题目.
//

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


#if 0
// v4
// 其实v3和v4都出在解决了很多问题,但没解决更深的间隙问题, 如K与L的间隙
// 所以,重写逻辑.
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
// 1            A
//            /   \
// 2         B     C
//          / \   / \
// 3       E   F G   H
//
// 4           NULL
//

class Solution {
private:
    void recursion(Node* node) {
        if (node != NULL) {  // 应对行1为非NULL的情况
            if (node->left != NULL) {  // 应对行1,行2为非NULL的情况, 链接行1的两子节点
                node->left->next = node->right;
                if (node->left->left != NULL) {  // 应对行1,行2,行3,链接行3中两三角的间隙
                    node->left->right->next = node->right->left;
                    recursion(node->left);
                    recursion(node->right);
                }
            }
        }
    }
    
public:
    Node* connect(Node* root) {
        recursion(root);
        return root;
    }
};

#endif


#if 0
// v3
// 这个写法的逻辑问题解决了很多

//
// 1            A
//            /   \
// 2         B     C
//          / \   / \
// 3       E   F G   H
//
// 4           NULL
//

class Solution {
private:
    void recursion(Node* node) {
        if (node == NULL) { // 应对4的情况
            return;
        }
        
        if (node->left == NULL) {  // 应对3的情况
            // 已经知道了下一个是4的情况,
            // 就没有必要向下传递了.
            return;
        }
        
        // 上面两个if看似是用来处理情况3和情况4的,其实不然
        // 因为只有情况1会将递归下传
        // 所以之际的运行中在这颗树足够深的情况下只会发生情况3和情况4
        // 所以上面两个if实际是处理这颗树不够深的情况
        
        if (node->left->left == NULL) {  // 应对2的情况
            node->left->next = node->right; // 链接两子节点
            
            // 这时也没有必要下传,
            // 因为3的情况也是什么都没做
            // 而且两个三角之间的链接也已经由上一层如果存在的1情况做好了
            return;
        }
        
        if (node->left->left->left == NULL) {  // 应对1的情况
            node->left->right->next = node->right->left;
        }
        
        // drill down应该继续写在外面,因为有可能题目并不能完全满足情况4
        recursion(node->left);
        recursion(node->right);
    }
    
public:
    Node* connect(Node* root) {
        recursion(root);
        
        return root;
    }
};

#endif


#if 0
// v2
// 这个写法的逻辑问题解决了很多, 更多的问题在情况4

//
// 1            A
//            /   \
// 2         B     C
//          / \   / \
// 3       E   F G   H
//
// 4           NULL
//

class Solution {
private:
    void recursion(Node* node) {
        if (node == NULL) { // 应对4的情况
            return;
        }
        
        if (node->left == NULL) {  // 应对3的情况
            // 已经知道了下一个是4的情况,
            // 就没有必要向下传递了.
            return;
        }
        
        // 上面两个if看似是用来处理情况3和情况4的,其实不然
        // 因为只有情况1会将递归下传
        // 所以之际的运行中在这颗树足够深的情况下只会发生情况3和情况4
        // 所以上面两个if实际是处理这颗树不够深的情况
        
        if (node->left->left == NULL) {  // 应对2的情况
            node->left->next = node->right; // 链接两子节点
            
            // 这时也没有必要下传,
            // 因为3的情况也是什么都没做
            // 而且两个三角之间的链接也已经由上一层如果存在的1情况做好了
            return;
        }
        
        if (node->left->left->left == NULL) {  // 应对1的情况
            // 应对1的情况要做两件事:
            // 第一件事时链接自己的子节点
            // 接着连接两个三角
            node->left->next = node->right;
            node->left->right->next = node->right->left;
            
            // 只有这个情况的参数应该下传
            // 因为还有情况2的两个子节点未连接
            
            recursion(node->left);
            recursion(node->right);
        }
    }
    
public:
    Node* connect(Node* root) {
        recursion(root);
        
        return root;
    }
};

#endif

#if 0
// v1
// 此写法有逻辑问题

class Solution {
private:
    void recursion(Node* node) {
        if (node == NULL) {
            return;
        }
        
        if (node->left == NULL) {  // 只要node的子节点是非NULL子节点就行
            return;
            // 不为NULL是执行if (node->left->left != NULL)的前提
        }
        
        node->left->next = node->right; // 链接两子节点
        recursion(node->left);
        recursion(node->right);
        
        if (node->left->left != NULL) {  // 只要node的子节点还有非NULL子节点就行
            node->left->right->next = node->right->left;
        }
        
    }
    
public:
    Node* connect(Node* root) {
        recursion(root);
        
        return root;
    }
};

#endif

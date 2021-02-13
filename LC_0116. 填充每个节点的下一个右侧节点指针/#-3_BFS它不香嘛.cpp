//2021.02.13_#-3_BFS它不香嘛

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
public:
    Node* connect(Node* root) {
        queue<Node *> que = queue<Node *>();
        que.push(root);
        
        while (!que.empty()) {
            if (que.front() == NULL) {  // 因为是一颗完美树, 所以遇到NULL就可以退出循环了
                break;
            }
            
            int count = (int) que.size();
            while (count-- > 0) {
                Node * node = que.front();
                que.pop();
                
                if (count > 0) {
                    node->next = que.front();
                }
                
                que.push(node->left);
                que.push(node->right);
            }
        }
        
        return root;
    }
};



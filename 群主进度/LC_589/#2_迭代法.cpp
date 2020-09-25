//2020.09.24_#2_迭代法

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
private:
    vector<int> list;
    
public:
    vector<int> preorder(Node* root) {
        if (root == NULL) {
            return list;
        }
        
        stack<Node*> stk;
        
        stk.push(root);
        
        while (!stk.empty()) {
            root = stk.top();
            stk.pop();
            list.push_back(root->val);
            
            for(int i = (int)(root->children).size()-1; i >= 0; i--) {
                if ((root->children)[i] != NULL) {
                    stk.push((root->children)[i]);
                }
            }
        }
        
        
        return list;
    }
};

//2020.09.19_#1_迭代法


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
public:
    vector<int> preorder(Node* root) {
        vector<int> ans;
        
        if (root == NULL) {
            return ans;
        }
        
        stack<Node*> stk;
        stk.push(root);
        
        while (!stk.empty()) {
            root = stk.top();
            stk.pop();
            
            ans.push_back(root->val);
            
            for (int i = (root->children).size()-1; i >= 0; i--) {
                if ((root->children)[i] != NULL) {
                    stk.push((root->children)[i]);
                }
            }
        }
        
        return ans;
    }
};

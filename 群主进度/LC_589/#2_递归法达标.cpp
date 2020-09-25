//2020.09.24_#2_递归法达标

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
        
        list.push_back(root->val);
        
        for (int i = 0; i < (root->children).size(); i++) {
            preorder((root->children)[i]);
        }
        
        return list;
    }
};

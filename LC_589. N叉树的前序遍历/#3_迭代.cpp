//2020.10.17_#3_迭代

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
    
    void DFS(Node * root) {
        if (root == NULL) {
            return;
        }
        
        list.push_back(root->val);
        
        for (int i = 0; i < (root->children).size(); i++) {
            DFS((root->children)[i]);
        }
    }
    
public:
    vector<int> preorder(Node* root) {
        list = vector<int>();
        DFS(root);
        return list;
    }
};

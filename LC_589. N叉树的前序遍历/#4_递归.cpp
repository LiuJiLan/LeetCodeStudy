//2020.11.14_#4_递归

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
    
    void DFS(Node * node) {
        if (node == NULL) {
            return;
        }
        
        list.push_back(node->val);
        for (int i = 0; i < node->children.size(); i++) {
            DFS(node->children.at(i));
        }
    }
    
public:
    vector<int> preorder(Node* root) {
        list = vector<int>();
        DFS(root);
        return list;
    }
};
